#include <atomic_structure/allocator/allocator.h>
#include <atomic_structure/allocator/details/details_allocator.h>

atomic_allocator
    atomic_allocator_initialize
        (atomic_allocator_allocate_t   pFnAllocate       ,
         atomic_allocator_deallocate_t pFnDeallocate     ,
         size_t                        pAllocateMaxSize  ,
         size_t                        pAllocateAlignment,
         void*                         pAllocateParameter)
{
    atomic_allocator
        ptr_allocator
            = { .handle
                    = __atomic_allocator_initialize
                        (pFnAllocate, pFnDeallocate,
                            pAllocateMaxSize, pAllocateAlignment,
                                pAllocateAlignment) };
    
    return
        ptr_allocator;
}

void
    atomic_allocator_cleanup
        (atomic_allocator pAllocator)
{
    __atomic_allocator_cleanup
        (pAllocator.handle);
}