#include "obj.h"
#include "atom.h"

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
		(mem* par_res, obj_trait* par_trait, u32_t par_count, va_list par) {
			if (!par_trait)					    return 0		   ;
			if (!par_res)						par_res = get_mem();
			if (!par_res)						return 0		   ;
			if (par_trait->size <= sizeof(obj)) return 0		   ;

			obj    *ret = mem_new(par_res, par_trait->size); if (!ret) return 0;
			mem_set(ret, 0x00, par_trait->size);

			ret->trait = par_trait;
			ret->mem   = par_res  ;
			ret->ref   = 1		  ;

			if (!par_trait->on_new)			   return ret;
			if (!par_trait->on_new(ret, par_count, par)) {
				mem_del(par_res, ret);
				return 0;
			}

			return ret;
}

bool_t
	obj_new_at
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, ...) {
			va_list  par;
			va_start(par, par_count); bool_t ret = obj_new_at_va(par_obj, par_trait, par_count, par);
			va_end  (par);

			return ret;
}

bool_t 
	obj_new_at_va
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, va_list par) {
			if (!par_obj)						return false_t;
			if (!par_trait)						return false_t;
			if (par_trait->size <= sizeof(obj)) return false_t;

			mem_set(par_obj, 0x00, par_trait->size);
			par_obj->trait = par_trait;
			par_obj->mem   = 0		  ;
			par_obj->ref   = 1		  ;

			if (!par_trait->on_new)				return true_t;
			if (!par_trait->on_new(par_obj, par_count, par)) {
				mem_set(par_obj, 0x00, par_trait->size);
				return false_t;
			}

			return true_t;
}

obj*	   
	obj_clone   
		(obj* par)										 {
			if (!par)							 return 0;
			if (!par->mem)						 return 0;
			if (!par->trait)					 return 0;
			if (par->trait->size <= sizeof(obj)) return 0;

			obj *ret   = mem_new(par->mem, par->trait->size); if (!ret) return 0;
			ret->trait = par->trait;
			ret->mem   = par->mem  ;
			ret->ref   = 1		   ;

			if (!par->trait->on_clone)				{
				mem_copy(ret, par, par->trait->size);
				return   ret;
			}

			if(!par->trait->on_clone(ret, par)) {
				mem_del(ret->mem, ret);
				return 0;
			}

			return ret;
}

bool_t     
	obj_clone_at
		(obj* par, obj* par_clone)							   {
			if (!par)								   return 0;
			if (!par_clone)							   return 0;
			if (!par_clone->trait)					   return 0;
			if (par_clone->trait->size <= sizeof(obj)) return 0;
			if (!par_clone->mem && !par_clone->ref)    return 0;

			par->trait = par_clone->trait;
			par->mem   = 0				 ;
			par->ref   = 1				 ;

			if (!par_clone->trait->on_clone)					{
				mem_copy(par, par_clone, par_clone->trait->size);
				return true_t;
			}

			if(!par->trait->on_clone(par, par_clone))     {
				mem_set(par, 0x00, par_clone->trait->size);
				return false_t;
			}

			return true_t;
}

obj*
	obj_ref
		(obj* par)					 { 
			if (!par)		 return 0;
			if (!par->trait) return 0;
			if (!par->ref)	 return 0;

			if (!par->trait->on_ref) { 
				lock_inc64(&par->ref);
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

			u64_t ref = lock_cas_dec64(&par->ref);
			if (ref == 0)									   {
				if (par->trait->on_del) par->trait->on_del(par);
				if (!par->mem)						    {
					mem_set(par, 0x00, par->trait->size);
					return 0;
				}

				mem_del(par->mem, par);
				return 0;
			}

			return ref;
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