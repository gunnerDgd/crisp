#include "object.h"
#include "atomic.h"

object_t*
    object_init(alloc_t* par_alloc, c_u64_t par_alloc_size, object_trait_t* par_trait, void* par_init) {
        mem_t    *object_mem = mem_init(par_alloc, par_alloc_size + sizeof(object_t));
        object_t *object     = mem_ptr (object_mem);

                  object->mem   = object_mem;
                  object->ref   =          1;
                  object->alloc =  par_alloc;
                  object->trait =  par_trait;

		if(!object->trait->init(object, par_init)) {
			mem_deinit(object->mem);
			return 0;
		}

        return    object;
}

object_t*
    object_init_as_clone(object_t* par_object_clone) {
        mem_t    *object_mem = mem_init_as_clone(par_object_clone->mem);
        object_t *object     = mem_ptr (object_mem);

                  object->mem   =              object_mem;
                  object->ref   =                       1;
                  object->alloc = par_object_clone->alloc;
				  object->trait = par_object_clone->trait;

        if(!object->trait->init_as_clone(object, par_object_clone)) {
			mem_deinit(object->mem);
			return 0;
		}
        return    object;
}

object_t*
    object_init_as_ref(object_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg64(&par_object->ref, ref + 1) != ref);

               par_object->trait->init_as_ref(par_object);
        return par_object;
}

c_bool_t
    object_deinit(object_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg64(&par_object->ref, ref - 1) != ref);

        if(ref == 0) {
            par_object->trait->deinit(par_object);
            mem_deinit(par_object->mem);
            return true;
        }

        return false;
}