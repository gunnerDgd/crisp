#include "alloc.h"
#include "details/alloc.h"


bool_t
    alloc_init
        (alloc* par_alloc, alloc_trait par_alloc_trait) {
            if(!par_alloc) return false_t;
            
            return
                (par_alloc_trait)
                    ? __alloc_init(par_alloc, par_alloc_trait)
                    : false_t;
}

bool_t
    alloc_init_as_clone
        (alloc *par_alloc, alloc *par_alloc_clone) {
            return __alloc_init_as_clone(par_alloc, par_alloc_clone);
}

void
    alloc_deinit
        (alloc* par_alloc) {
            return __alloc_deinit(par_alloc);
}