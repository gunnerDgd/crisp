#include <crisp/alloc.h>
#include <crisp/details/alloc.h>

static c_alloc_t c_alloc_global	 		 ;
static c_bool_t  c_alloc_global_init = false;

c_alloc_t*
	c_global_alloc() {
		if(!c_alloc_global_init) {
			c_alloc_global_init = true;
			if(!c_alloc_init(&c_alloc_global)) {
				c_alloc_global_init = false;
				return 0;
			}

			return &c_alloc_global;
		}
		return &c_alloc_global;
}

c_bool_t
    c_alloc_init(c_alloc_t* par_alloc) {
        alloc_t* ptr_alloc               = par_alloc;
                 ptr_alloc->handle_trait = &alloc_global_trait;

        return alloc_init(ptr_alloc);
}

c_bool_t
    c_alloc_init_as_clone(c_alloc_t *par_alloc, c_alloc_t *par_alloc_clone) {
        return alloc_init_as_clone(par_alloc, par_alloc_clone);
}

c_bool_t
    c_alloc_deinit(c_alloc_t* par_alloc) {
        return alloc_deinit(par_alloc);
}