#include "obj.h"
#include "details/obj.h"

obj*
    obj_new
		(alloc* par_alloc, obj_trait* par_trait, u32_t par_count, ...) {
    		va_list  par;
			va_start(par, par_count); obj* ret = obj_new_from_va(par_alloc, par_trait, par_count, par);
			va_end  (par);
			return   ret ;
}

obj*
    obj_new_from_va
		(alloc* par_alloc, obj_trait* par_trait, u32_t par_count, va_list par) {
			if (!par_alloc) par_alloc = get_alloc();
			if (!par_alloc) return 0;
			if (!par_trait) return 0;

			obj*   ret = __obj_new(par_alloc, par_trait, par_count, par);
			return ret;
}

bool_t
	obj_new_at
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, ...) {
			va_list  par;
			va_start(par, par_count); bool_t ret = obj_new_at_from_va(par_obj, par_trait, par_count, par);
			va_end  (par);

			return ret;
}

bool_t 
	obj_new_at_from_va
		(obj* par_obj, obj_trait* par_trait, u32_t par_count, va_list par) {
			if (!par_obj)   return false_t;
			if (!par_trait) return false_t;

			return __obj_new_at(par_obj, par_trait, par_count, par);
}

obj*	   obj_clone   (obj* par)				  { return (par) ? __obj_clone   (par)			  : 0; }
bool_t     obj_clone_at(obj* par, obj* par_clone) { return (par) ? __obj_clone_at(par, par_clone) : 0; }
obj*	   obj_ref     (obj* par)				  { return (par) ? __obj_ref     (par)			  : 0; }
void	   obj_del	   (obj* par)				  { if(par) __obj_del(par); }

obj_trait* obj_get_trait(obj* par) { return (par) ? ((__obj*)par)->trait : 0; }
u64_t      obj_use_count(obj* par) { return (par) ? ((__obj*)par)->ref   : 0; }