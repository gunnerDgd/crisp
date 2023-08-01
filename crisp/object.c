#include "object.h"
#include "details/object.h"

c_object_t
    c_object_init(c_alloc_t* par_object, c_u64_t par_object_size) {
        c_object_t ret = { .ptr = object_init(par_object, par_object_size) };
        return     ret;
}

c_object_t
    c_object_init_as_clone(c_object_t par_object) {
        c_object_t ret = { .ptr = object_init_as_clone(par_object.ptr) };
        return     ret;
}

c_object_t
    c_object_init_as_ref(c_object_t par_object) {
        c_object_t ret = { .ptr = object_init_as_ref(par_object.ptr) };
        return     ret;
}

c_bool_t
    c_object_deinit(c_object_t par_object) {
        return object_deinit(par_object.ptr);
}

void*
    c_object_ptr(c_object_t par_object) {
        return (c_u8_t*)par_object.ptr + sizeof(object_t);
}