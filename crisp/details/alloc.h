#ifndef CRISP_DETAILS_ALLOC_H
#define CRISP_DETAILS_ALLOC_H

#include <crisp/type.h>
#include <crisp/type_atomic.h>

typedef struct
    alloc_handle_t { c_u64_t handle[248]; }
        alloc_handle_t;

typedef struct alloc_trait_t {
    c_bool_t      (*init)             (struct alloc_t*);
    c_bool_t      (*init_as_clone)    (struct alloc_t*, struct alloc_t*);
    c_bool_t      (*deinit)           (struct alloc_t*);

    struct mem_t* (*mem_init)         (struct alloc_t*, c_u64_t);
    struct mem_t* (*mem_init_as_clone)(struct alloc_t*, struct mem_t*);
    c_bool_t      (*mem_deinit)       (struct alloc_t*, struct mem_t*);
}   alloc_trait_t;

typedef struct
    alloc_t { alloc_handle_t handle; alloc_trait_t* handle_trait; }
        alloc_t;

#define alloc_init(par_alloc)                           ((alloc_t*)par_alloc)->handle_trait->init         (par_alloc)
#define alloc_init_as_clone(par_alloc, par_alloc_clone) ((alloc_t*)par_alloc)->handle_trait->init_as_clone(par_alloc, par_alloc_clone)
#define alloc_deinit(par_alloc)                         ((alloc_t*)par_alloc)->handle_trait->deinit       (par_alloc)

extern alloc_trait_t alloc_global_trait;

#endif
