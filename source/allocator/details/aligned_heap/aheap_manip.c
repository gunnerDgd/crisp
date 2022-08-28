#include <atomic_structure/allocator/details/aligned_heap/aheap_manip.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GCC
#include <stdlib.h>
#include <stdalign.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
#include <malloc.h>
#endif

void*
    __atomic_allocator_aligned_heap_allocate
        (__atomic_allocator_aligned_heap* pAllocator, 
         size_t                           pAllocatorSize, 
         void*                            pAllocatorHint)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GCC
    return
        aligned_malloc
            (__atomic_allocator_aligned_heap_allocate_size
                (pAllocator, pAllocatorSize),
                    pAllocator->aheap_allocate_alignment);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
    return
        _aligned_malloc
            (pAllocatorSize,
                pAllocator->aheap_allocate_alignment);
#endif
}

size_t
    __atomic_allocator_aligned_heap_allocate_alignment
        (__atomic_allocator_aligned_heap* pAllocator)
{
    return
        pAllocator->aheap_allocate_alignment;
}

void
    __atomic_allocator_aligned_heap_deallocate
        (__atomic_allocator_aligned_heap* pAllocator, 
         size_t                           pDeallocSize,
         void*                            pDeallocPtr)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GCC
    aligned_free
        (pDeallocPtr);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
    _aligned_free(pDeallocPtr);
#endif
}