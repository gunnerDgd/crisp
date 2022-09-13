#include <atomic_structure/allocator/details/details_allocator.h>
#include <stdlib.h>

void
    __atomic_allocator_initialize
        (__atomic_allocator* pAllocator,
         void*(*pFnAllocate)  (void*, size_t, void*),
         void (*pFnDeallocate)(void*, size_t, void*),
         size_t pAllocateMaxSize, 
         size_t pAllocateAlignment,
         void*  pAllocateParameter)
{
    pAllocator->allocate
        = pFnAllocate;
    pAllocator->allocate_alignment
        = pAllocateAlignment;
    pAllocator->allocate_max_size
        = pAllocateMaxSize;
    pAllocator->deallocate
        = pFnDeallocate;
    pAllocator->allocate_parameter
        = pAllocateParameter;
}