#include <atomic_structure/allocator/details/aligned_heap/aheap_init.h>
#include <atomic_structure/allocator/details/aligned_heap/aheap_manip.h>

#include <stdlib.h>

__atomic_allocator_aligned_heap*
    __atomic_allocator_aligned_heap_initialize
        (size_t pAllocateAlignment)
{
    __atomic_allocator_aligned_heap*
        ptr_aheap
            = malloc
                (sizeof(__atomic_allocator_aligned_heap));
    
    ptr_aheap->aheap_allocator.allocate
        = &__atomic_allocator_aligned_heap_allocate;
    ptr_aheap->aheap_allocator.allocate_alignment
        = &__atomic_allocator_aligned_heap_allocate_alignment;
    ptr_aheap->aheap_allocator.deallocate
        = &__atomic_allocator_aligned_heap_deallocate;
    
    ptr_aheap->aheap_allocate_alignment
        = pAllocateAlignment;
    return
        ptr_aheap;
}

void
    __atomic_allocator_aligned_heap_cleanup
        (__atomic_allocator_aligned_heap* pAllocator)
{
    free
        (pAllocator);
}