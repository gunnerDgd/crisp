#include <crisp/alloc.h>
#include <crisp/details/alloc.h>

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