#include "obj.h"
#include "atomic.h"

obj_t*
    obj_init(alloc_t* par_alloc, c_u64_t par_alloc_size, obj_trait_t* par_trait, void* par_init) {
        mem_t *object_mem = mem_init(par_alloc, par_alloc_size + sizeof(obj_t));
        obj_t *object     = mem_ptr (object_mem);

                  object->alloc_mem = object_mem;
				  object->alloc 	=  par_alloc;
                  object->ref   	=          1;
                  object->trait 	=  par_trait;

		if(!object->trait->init(object, par_init)) {
			mem_deinit(object->alloc_mem);
			return 0;
		}

        return    object;
}

obj_t*
    obj_init_as_clone(obj_t* par_object_clone) {
        mem_t *object_mem = mem_init_as_clone(par_object_clone->alloc_mem);
        obj_t *object     = mem_ptr 		 (object_mem);

			   object->alloc     = par_object_clone->alloc;
               object->alloc_mem =              object_mem;
               object->ref   	 =                       1;
			   object->trait     = par_object_clone->trait;

        if(!object->trait->init_as_clone(object, par_object_clone)) {
			mem_deinit(object->alloc_mem);
			return 0;
		}
        return    object;
}

obj_t*
    obj_init_as_ref(obj_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg64(&par_object->ref, ref + 1) != ref);

               par_object->trait->init_as_ref(par_object);
        return par_object;
}

c_bool_t
    obj_deinit(obj_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg64(&par_object->ref, ref - 1) != ref);

        if(ref == 0) {
            par_object->trait->deinit(par_object);
            mem_deinit(par_object->alloc_mem);
            return true;
        }

        return false;
}