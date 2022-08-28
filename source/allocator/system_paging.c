#include <atomic_structure/allocator/details/system_paging/syspaging_init.h>
#include <atomic_structure/allocator/details/system_paging/syspaging_manip.h>

#include <atomic_structure/allocator/system_paging.h>

atomic_allocator*
    atomic_allocator_syspaging_initialize
        ()
{
    return
        __atomic_allocator_syspaging_initialize();
}

atomic_allocator*
    atomic_allocator_syspaging_initialize_large
        (size_t pAllocUnit)
{
    return
        __atomic_allocator_syspaging_initialize
            (pAllocUnit);
}

atomic_allocator*
    atomic_allocator_syspaging_initialize_heap
        (size_t pAllocUnit)
{
    return
        __atomic_allocator_syspaging_initialize
            (pAllocUnit);
}

void
    atomic_allocator_syspaging_cleanup
        (atomic_allocator* pAllocator)
{
    __atomic_allocator_syspaging_cleanup
        (pAllocator);
}