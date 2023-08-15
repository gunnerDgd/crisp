#include "object.h"
#include "details/object.h"

c_object_t*
    c_object_init(c_alloc_t* par_object, c_u64_t par_object_size, c_object_trait_t* par_trait, void* par_init) {
        return object_init(par_object, par_object_size, par_trait, par_init);
}

c_object_t*
    c_object_init_as_clone(c_object_t* par_object) {
        return object_init_as_clone(par_object);
}

c_object_t*
    c_object_init_as_ref(c_object_t* par_object) {
        return object_init_as_ref(par_object);
}

c_bool_t
    c_object_deinit(c_object_t* par_object) {
        return object_deinit(par_object);
}

void*
    c_object_ptr(c_object_t* par_object) {
        return (c_u8_t*)par_object + sizeof(object_t);
}