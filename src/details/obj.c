#include "obj.h"
#include "../atom.h"

__obj*
    __obj_new
		(mem_res* par_res, __obj_trait* par_trait, u32_t par_count, va_list par) {
			__obj* ret = mem_new(par_res, par_trait->size);
			if   (!ret) return false_t;

			mem_set(ret, 0x00, par_trait->size);
			ret->trait = par_trait;
			ret->res   = par_res  ;
			ret->ref   = 1		  ;
			
			if (!ret->trait->on_new)			return ret;
			if (!ret->trait->on_new(ret, par_count, par)) {
				mem_del(par_res, ret);
				return 0;
			}

			return ret;
}

bool_t 
	__obj_new_at
		(__obj* par_obj, __obj_trait* par_trait, u32_t par_count, va_list par) {
			mem_set(par_obj, 0x00, par_trait->size);
			par_obj->trait = par_trait;
			par_obj->res   =		 0;
			par_obj->ref   =		 1;

			if (!par_obj->trait->on_new)			 return true_t;
			if (!par_obj->trait->on_new(par_obj, par_count, par)) {
				par_obj->trait = 0;
				par_obj->ref   = 9;
				par_obj->res   = 0;

				return false_t;
			}
			
			return true_t;
}

__obj*
    __obj_clone
		(__obj* par)		  	     {
			if (!par->res)   return 0;
			if (!par->trait) return 0;

			__obj *ret = mem_new(par->res, par->trait->size); 
			if (!ret)						return 0;
			if (!par->trait->on_clone)				{
				mem_copy(ret, par, par->trait->size);
				ret->trait = par->trait;
				ret->res   = par->res  ;
				ret->ref   = 1		   ;

				return ret;
			}

			if(!par->trait->on_clone(ret, par)) {
				mem_del(ret->res, ret);
				return 0;
			}

			ret->trait = par->trait;
			ret->res   = par->res  ;
			ret->ref   = 1		   ;
			return ret;
}

bool_t
	__obj_clone_at
		(__obj* par, __obj* par_clone)     {
			if (!par_clone->trait) return 0;
			if (!par_clone->trait->on_clone)					{
				mem_copy(par, par_clone, par_clone->trait->size);
				par->trait = par_clone->trait;
				par->res   = 0;
				par->ref   = 1;

				return true_t;
			}

			par->trait = par_clone->trait;
			par->res   = 0;
			par->ref   = 1;

			if(!par->trait->on_clone(par, par_clone))     {
				mem_set(par, 0x00, par_clone->trait->size);
				return false_t;
			}

			return true_t;
}

__obj*
    __obj_ref
		(__obj* par)				 {
			if (!par->trait->on_ref) { 
				lock_inc64(&par->ref);
				return par;
			}
			
			if (!par->trait->on_ref(par)) return 0;
			lock_inc64(&par->ref);
			return par;

}

u64_t
    __obj_del
		(__obj* par)				{
			if(par->ref == 0) return;

			u64_t ref;
			do  { ref = par->ref; } while(lock_cas64(&par->ref, ref, ref - 1) != ref);

			if (par->ref == 0)								   {
				if (par->trait->on_del) par->trait->on_del(par);
				if (!par->res)						    {
					mem_set(par, 0x00, par->trait->size);
					return 0;
				}

				mem_del(par->res, par);
				return 0;
			}

			return ref - 1;
}