#include <atomic_structure/allocator/aligned_heap.h>

#include <atomic_structure/allocator/details/aligned_heap/aheap_init.h>
#include <atomic_structure/allocator/details/aligned_heap/aheap_manip.h>

atomic_allocator*
    atomic_allocator_aligned_heap_initialize
        (size_t pAllocAlignment)
{
    return
        __atomic_allocator_aligned_heap_initialize
            (pAllocAlignment);
}

void
    atomic_allocator_aligned_heap_cleanup
        (atomic_allocator* pAllocator)
{
    __atomic_allocator_aligned_heap_cleanup
        (pAllocator);
}