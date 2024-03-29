#include "obj.h"
#include "atom.h"
#include "mem.h"

obj*
    obj_new
		(mem* par_mem, obj_trait* par_trait, u32_t par_count, ...) {
    		va_list  par;
			va_start(par, par_count); obj* ret = obj_new_va(par_mem, par_trait, par_count, par);
			va_end  (par);
			return   ret ;
}

obj*
    obj_new_va
		(mem* par_mem, obj_trait* par_trait, u32_t par_count, va_list par)   		  {
			obj_trait *trait = par_trait; if (!trait)				     return null_t;
			mem       *mem   = par_mem  ; if (trait->size < sizeof(obj)) return null_t;
			if (!mem) mem = get_mem();
			if (!mem) return   null_t;
			
			obj    *ret = mem_acq(mem, null_t, trait->size); if (!ret) return null_t;
			mem_set(ret, 0x00, trait->size)		           ;
			ret->trait = trait;
			ret->mem   = mem  ;
			ret->ref   = 1	  ;

			if (!trait->on_new)			   return ret;
			if (!trait->on_new(ret, par_count, par)) {
				mem_rel(mem, ret, 0);
				return null_t;
			}

			return ret;
}

bool_t
	obj_new_at
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, ...) {
			va_list  par;
			va_start(par, par_count); 
			bool_t ret = obj_new_at_va (
				par_obj  , 
				par_trait,
				par_count,
				par
			);
			
			va_end (par);
			return  ret ;
}

bool_t 
	obj_new_at_va
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, va_list par) {
			obj		  *ret   = par_obj  ; if (!ret)   return false_t;
			obj_trait *trait = par_trait; if (!trait) return false_t;
			if (trait->size < sizeof(obj)) return false_t;

			mem_set(ret, 0x00, trait->size);
			ret->trait = par_trait;
			ret->mem   = 0		  ;
			ret->ref   = 1		  ;

			if (!trait->on_new)			return true_t;
			if (!trait->on_new(ret, par_count, par)) {
				mem_set(ret, 0x00, trait->size);
				return false_t;
			}

			return true_t;
}

obj*	   
	obj_clone   
		(obj* par)											        {
			obj		  *arg   = par		 ; if (!arg)   return null_t;
			obj_trait *trait = arg->trait; if (!trait) return null_t;
			mem		  *mem   = par->mem  ;
			if (!mem)					   mem = get_mem();
			if (!mem)					   return null_t;
			if (trait->size < sizeof(obj)) return null_t;
			if (!arg->ref)				   return null_t;

			obj *ret   = mem_acq(par->mem, null_t, par->trait->size); if (!ret) return null_t;
			ret->trait = trait;
			ret->mem   = mem  ;
			ret->ref   = 1	  ;

			if (!trait->on_clone)			   {
				mem_copy(ret, arg, trait->size);
				return   ret;
			}

			if (!trait->on_clone(ret, arg)) goto clone_failed;
			return ret;
	clone_failed:
			mem_rel(mem, ret, 0);
			return null_t;
}

bool_t     
	obj_clone_at
		(obj* par, obj* par_clone)									 {
			obj		  *arg   = par_clone ; if (!arg)   return false_t;
			obj		  *ret   = par		 ; if (!ret)   return false_t;
			obj_trait *trait = arg->trait; if (!trait) return false_t;
			if (trait_of(ret)) return false_t;
			if (!arg->ref)	   return false_t;

			par->trait = trait;
			par->mem   = 0	  ;
			par->ref   = 1	  ;

			if (!par_clone->trait->on_clone)   {
				mem_copy(ret, arg, trait->size);
				return true_t;
			}

			if(!trait->on_clone(ret, arg)) goto clone_failed;
			return true_t;
	clone_failed:
			mem_set(ret, 0x00, trait->size);
			return false_t;
}

obj*
	obj_ref
		(obj* par)					 {
			if (!par)		 return 0;
			if (!par->trait) return 0;
			if (!par->ref)	 return 0;

			if (!par->trait->on_ref)   { 
				lock_inc_ptr(&par->ref);
				return par;
			}
			
			if   (!par->trait->on_ref(par)) return 0; lock_inc64(&par->ref);
			return par;
}

u64_t
	obj_del
		(obj* par)			           {
			if(!par)		   return 0;
			if(!par->trait)    return 0;
			if (par->ref == 0) return 0;

			u64_t ref = lock_cas_dec_ptr(&par->ref);
			if (ref) return ref;
			if (par->trait->on_del) par->trait->on_del(par);
			if (!par->mem)						    {
				mem_set(par, 0x00, par->trait->size);
				return 0;
			}

			mem_rel(par->mem, par, 0);
			return 0;
}

obj_trait* 
	obj_get_trait
		(obj* par)		      {
			if (!par) return 0;
			return par->trait;
}

u64_t 
	obj_use_count
		(obj* par)					 {
			if (!par)		 return 0;
			if (!par->trait) return 0;

			return par->ref;
}