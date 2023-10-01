#include "alloc.h"
#include "details/alloc.h"

alloc  default_alloc	 		 ;
bool_t default_alloc_init = false;

alloc*
	get_default_alloc() {
		if(!default_alloc_init) {
			if(!alloc_init(&default_alloc)) return 0;
			default_alloc_init = true;
		}

		return &default_alloc;
}

bool_t
    alloc_init(alloc* par_alloc) {
        return __alloc_init(par_alloc, 0);
}

bool_t
    alloc_init_as_clone(alloc *par_alloc, alloc *par_alloc_clone) {
        return __alloc_init_as_clone(par_alloc, par_alloc_clone);
}

void
    alloc_deinit(alloc* par_alloc) {
        return __alloc_deinit(par_alloc);
}