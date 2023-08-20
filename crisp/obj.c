#include "obj.h"
#include "details/obj.h"

c_obj_t
    c_obj_init(c_alloc_t* par_alloc, c_u64_t par_object_size, c_obj_trait_t* par_trait, void* par_init) {
        return obj_init(par_alloc, par_object_size, par_trait, par_init);
}

c_obj_t
    c_obj_init_as_clone(c_obj_t par_object) {
        return obj_init_as_clone(par_object);
}

c_obj_t
    c_obj_init_as_ref(c_obj_t par_object) {
        return obj_init_as_ref(par_object);
}

c_bool_t
    c_obj_deinit(c_obj_t par_object) {
        return obj_deinit(par_object);
}

void*
	c_obj_ptr(c_obj_t par_object) {
		return (c_u8_t*)par_object + sizeof(obj_t);
}