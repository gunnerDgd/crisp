#include "object.h"
#include "atomic.h"

object_t*
    object_init(alloc_t* par_alloc, c_u64_t par_alloc_size) {
        mem_t    *object_mem = mem_init(par_alloc, par_alloc_size);
        object_t *object     = mem_ptr (object_mem);

                  object->mem   = object_mem;
                  object->ref   =          1;
                  object->alloc =  par_alloc;
        return    object;
}

object_t*
    object_init_as_clone(object_t* par_object_clone) {
        mem_t    *object_mem = mem_init_as_clone(par_object_clone->mem);
        object_t *object     = mem_ptr (object_mem);

                  object->mem   =              object_mem;
                  object->ref   =                       1;
                  object->alloc = par_object_clone->alloc;
        return    object;
}

object_t*
    object_init_as_ref(object_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg_u64(&par_object->ref, ref + 1) == ref);

        return par_object;
}

c_bool_t
    object_deinit(object_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg_u64(&par_object->ref, ref - 1) == ref);

        if(ref == 0) {
            mem_deinit(par_object->mem);
            return true;
        }

        return false;
}