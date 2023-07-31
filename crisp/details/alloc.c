#include "alloc.h"
#include "alloc_cstd.h"

alloc_trait_t
alloc_global_trait = {
        .init              = cstd_alloc_init         ,
        .init_as_clone     = cstd_alloc_init_as_clone,
        .deinit            = cstd_alloc_deinit       ,

        .mem_init          = cstd_mem_init           ,
        .mem_init_as_clone = cstd_mem_init_as_clone  ,
        .mem_deinit        = cstd_mem_deinit
};