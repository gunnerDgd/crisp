#include "obj.h"
#include "../atomic.h"

__obj*
    __obj_new
		(alloc* par_alloc, __obj_trait* par_trait, u32_t par_count, va_list par) {
			mem* ret_mem = mem_new(par_alloc, par_trait->size);
			if (!ret_mem) 
				return false_t;

			__obj *ret 	      = mem_ptr_raw(ret_mem);
				   ret->mem   = ret_mem  ;
				   ret->ref   = 1		 ;
				   ret->trait = par_trait;

			if(!ret->trait->on_new) return ret;
			if(!ret->trait->on_new(ret, par_count, par)) {
				mem_del(ret_mem);
				return 0;
			}

			return ret;
}

bool_t 
	__obj_new_at
		(__obj* par_obj, __obj_trait* par_trait, u32_t par_count, va_list par) {
			par_obj->mem   =		 0;
			par_obj->trait = par_trait;
			par_obj->ref   =		 1;

			if (par_obj->trait->on_new)
				return par_obj->trait->on_new(par_obj, par_count, par);
			
			return true_t;
}

__obj*
    __obj_clone
		(__obj* par)						  {
			mem *ret_mem = mem_clone(par->mem); 
			if (!ret_mem)			  return 0;

			__obj *ret = mem_ptr_raw(ret_mem);
			if   (!ret)			{
				mem_del(ret_mem);
				return 0;
			}

			ret->mem   = ret_mem   ;
			ret->ref   = 1         ;
			ret->trait = par->trait;

			if (!ret->trait->on_clone)
				return ret;

			if(!ret->trait->on_clone(ret, par)) {
				mem_del(ret_mem);
				return 0;
			}

			return ret;
}

bool_t
	__obj_clone_at
		(__obj* par, __obj* par_clone)   {
			par->ref   =				1;
			par->trait = par_clone->trait;

			if (par->trait->on_clone)
				return par->trait->on_clone(par, par_clone);

			return true_t;
}

__obj*
    __obj_ref
		(__obj* par)				 {
			if (!par->trait->on_ref) { 
				lock_inc64(&par->ref);
				return par;
			}
			
			if (!par->trait->on_ref(par)) return   0;
			lock_inc64(&par->ref);
			return par;

}

void
    __obj_del
		(__obj* par) {
			u64_t ref;
			do  { ref = par->ref; } while(lock_cas64(&par->ref, ref, ref - 1) != ref);

			if (par->ref == 0)		    {
				if(!par->trait->on_del) {
					mem_del(par->mem);
					return;

				}

				par->trait->on_del(par);
			}
}