#include <atomic_structure/allocator/details/details_allocator.h>
#include <stdlib.h>

__atomic_allocator*
    __atomic_allocator_initialize
        (void*(*pFnAllocate)  (void*, size_t, void*),
         void (*pFnDeallocate)(void*, size_t, void*),
         size_t pAllocateMaxSize, 
         size_t pAllocateAlignment,
         void*  pAllocateParameter)
{
    __atomic_allocator*
        ptr_allocator
            = malloc(sizeof(__atomic_allocator));
    
    ptr_allocator->allocate
        = pFnAllocate;
    ptr_allocator->allocate_alignment
        = pAllocateAlignment;
    ptr_allocator->allocate_max_size
        = pAllocateMaxSize;
    ptr_allocator->deallocate
        = pFnDeallocate;
    ptr_allocator->allocate_parameter
        = pAllocateParameter;

    return
        ptr_allocator;
}

void
    __atomic_allocator_cleanup
        (__atomic_allocator* pAllocator)
{
    free(pAllocator);
}