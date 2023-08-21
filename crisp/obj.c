#include "obj.h"
#include "details/obj.h"

c_obj_t
    c_obj_init(c_mem_t par_mem, c_obj_trait_t* par_trait, c_u32_t par_arg_count, ...) {
    	va_list  ret_args;
		va_start(ret_args, par_arg_count);
		c_obj_t  ret = obj_init(par_mem, par_trait, par_arg_count, ret_args);

		va_end  (ret_args);
		return   ret;
}

c_obj_t
    c_obj_init_from_varg(c_mem_t par_mem, c_obj_trait_t* par_trait, c_u32_t par_arg_count, va_list par_arg) {
		c_obj_t ret = obj_init(par_mem, par_trait, par_arg_count, par_arg);
		return  ret;
}

c_obj_t
    c_obj_init_as_clone(c_mem_t par_mem, c_obj_t par_object) {
        return obj_init_as_clone(par_mem, par_object);
}

c_obj_t
    c_obj_init_as_ref(c_obj_t par_object) {
        return obj_init_as_ref(par_object);
}

c_mem_t
    c_obj_deinit(c_obj_t par_object) {
        return obj_deinit(par_object);
}

void*
	c_obj_ptr(c_obj_t par_object) {
		return (c_u8_t*)par_object + sizeof(obj_t);
}

c_obj_trait_t*
	c_obj_trait(c_obj_t par_object) {
		return ((obj_t*)par_object)->trait;
}