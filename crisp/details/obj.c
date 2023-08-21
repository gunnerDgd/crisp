#include "obj.h"
#include "atomic.h"

obj_t*
    obj_init(mem_t* par_mem, obj_trait_t* par_trait, c_u32_t par_arg_count, va_list par_arg) {
        obj_t *ret = mem_ptr (par_mem); if(par_mem->mem_alloc_size <= sizeof(obj_t)) return 0;
               ret->mem   =   par_mem;
               ret->ref   =         1;
               ret->trait = par_trait;

		if(!ret->trait->init) 														  return object;
		if(!ret->trait->init((c_u8_t*)ret + sizeof(obj_t), par_arg_count, par_arg)) return 	  0;

		return ret;
}

obj_t*
    obj_init_as_clone(mem_t* par_mem, obj_t* par_object_clone) {
		if(par_mem->mem_alloc_size < par_object_clone->mem->mem_alloc_size) return 0;
		if(!par_object_clone->trait->init_as_clone) {
        	obj_t *ret 		  = mem_ptr(par_mem); mem_copy_from(par_mem, mem_ptr(par_object_clone->mem), par_object_clone->mem->mem_alloc_size);
               	   ret->mem   =  		par_mem ;
               	   ret->ref   =         	   1;
			       ret->trait = par_object_clone->trait;
			return ret;
		}

        obj_t *ret        = 	   mem_ptr(par_mem);
               ret->mem   =         	   par_mem ;
               ret->ref   =                		  1;
			   ret->trait = par_object_clone->trait;

        if(!ret->trait->init_as_clone((c_u8_t*)ret + sizeof(obj_t), (c_u8_t*)par_object_clone + sizeof(obj_t)))
			return 0;

		return ret;
}

obj_t*
    obj_init_as_ref(obj_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg64(&par_object->ref, ref + 1) != ref);

        if(par_object->trait->init_as_ref) par_object->trait->init_as_ref((c_u8_t*)par_object + sizeof(obj_t));
        return par_object;
}

mem_t*
    obj_deinit(obj_t* par_object) {
        c_u64_t ref;
        do { ref = par_object->ref; } while(atomic_cmpxchg64(&par_object->ref, ref - 1) != ref);

        if(ref == 0) {
            	   par_object->trait->deinit((c_u8_t*)par_object + sizeof(obj_t));
            return par_object->mem;
        }

        return 0;
}