#include "obj.h"
#include "atomic.h"

__obj*
    __obj_init
		(__alloc* par_alloc, __obj_trait* par_trait, u32_t par_count, va_list par) {
			__mem* ret_mem    = __mem_init(par_alloc, par_trait->size());
			__obj *ret 	      = ret_mem->ptr;							 if(ret_mem->alloc_size <= sizeof(__obj)) return 0;
				   ret->mem   = ret_mem     ;
				   ret->ref   =            1;
				   ret->trait =    par_trait;

		if(ret->trait->init) {
			if(!ret->trait->init(ret, par_count, par)) {
				__mem_deinit(ret_mem);
				return 0;
			}
		}

		return ret;
}

bool_t 
	__obj_init_at
		(__obj* par_obj, __obj_trait* par_trait, u32_t par_count, va_list par) {
			par_obj->mem   =		 0;
			par_obj->trait = par_trait;
			par_obj->ref   =		 1;

			if (par_obj->trait->init)
				return par_obj->trait->init(par_obj, par_count, par);
			
			return true_t;
}

__obj*
    __obj_init_as_clone
		(__obj* par) {
			__mem *ret_mem    = __mem_init_as_clone(par->mem); if(!ret_mem) return 0;
			__obj *ret	      = ret_mem->ptr;
				   ret->mem   = ret_mem		;
				   ret->ref   =            1;
				   ret->trait =   par->trait;

			if(ret->trait->init_as_clone) {
				bool_t res = ret->trait->init_as_clone (ret, par);
				if (!res)				 {
					__mem_deinit(ret_mem);
					return 0;
				}
			}

			return ret;
}

__obj*
    __obj_init_as_ref
		(__obj* par) {
			u64_t ref;
			do  { ref = par->ref; } while(__atomic_cmpxchg64(&par->ref, ref, ref + 1) != ref);

			if (par->trait->init_as_ref)
				par->trait->init_as_ref(par);
			return par;
}

void
    __obj_deinit
		(__obj* par) {
			u64_t ref;
			do  { ref = par->ref; } while(__atomic_cmpxchg64(&par->ref, ref, ref - 1) != ref);

			if (par->ref == 0)					   {
				par->trait->deinit(par)			   ;
				if(par->mem) __mem_deinit(par->mem);
			}
}