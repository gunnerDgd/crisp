#include "obj.h"
#include "details/obj.h"

obj*
    obj_init
		(alloc* par_alloc, obj_trait* par_trait, u32_t par_count, ...) {
    		va_list  par;
			va_start(par, par_count); obj* ret = obj_init_from_varg (par_alloc, par_trait, par_count, par);
			va_end  (par);
			return   ret ;
}

obj*
    obj_init_from_varg
		(alloc* par_alloc, obj_trait* par_trait, u32_t par_count, va_list par) {
			if (!par_alloc) par_alloc = get_alloc();
			if (!par_alloc) return 0;
			if (!par_trait) return 0;

			obj*   ret = __obj_init(par_alloc, par_trait, par_count, par);
			return ret;
}

obj* 
	obj_init_at
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, ...) {
			va_list  par;
			va_start(par, par_count); bool_t ret = obj_init_at_from_varg(par_obj, par_trait, par_count, par);
			va_end  (par);

			return ret;
}

obj* 
	obj_init_at_from_varg
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, va_list par) {
			if (!par_obj)   return false_t;
			if (!par_trait) return false_t;

			return __obj_init_at(par_obj, par_trait, par_count, par);
}

obj*	   obj_init_as_clone(obj* par) { return (par) ? __obj_init_as_clone(par) : 0; }
obj*	   obj_init_as_ref  (obj* par) { return (par) ? __obj_init_as_ref  (par) : 0; }
void	   obj_deinit		(obj* par) { if(par) __obj_deinit(par); }
obj_trait* obj_get_trait    (obj* par) { return (par) ? ((__obj*)par)->trait : 0; }
u64_t      obj_use_count	(obj* par) { return (par) ? ((__obj*)par)->ref   : 0; }

str*
	obj_name
		(obj* par) {
			if (!par)						 return 0;
			if (!((__obj*)par)->trait->name) return 0;

			return ((__obj*)par)->trait->name(par);
}