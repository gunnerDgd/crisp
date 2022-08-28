#include <atomic_structure/allocator/details/system_paging/syspaging_init.h>
#include <atomic_structure/allocator/details/system_paging/syspaging_manip.h>

#include <stdlib.h>

__atomic_allocator_syspaging*
    __atomic_allocator_syspaging_initialize
        ()
{
    __atomic_allocator_syspaging*
        ptr_allocator
            = malloc
                (sizeof(__atomic_allocator_syspaging));
    
    ptr_allocator->syspaging_allocator.allocate
        = &__atomic_allocator_syspaging_allocate;
    ptr_allocator->syspaging_allocator.allocate_alignment
        = &__atomic_allocator_syspaging_allocate_alignment;
    ptr_allocator->syspaging_allocator.deallocate
        = &__atomic_allocator_syspaging_deallocate;
    
    ptr_allocator->syspaging_category
        = normal;
    return
        ptr_allocator;
}

__atomic_allocator_syspaging*
    __atomic_allocator_syspaging_initialize_large
        ()
{
    __atomic_allocator_syspaging*
        ptr_allocator
            = malloc(sizeof(__atomic_allocator_syspaging));
    
    ptr_allocator->syspaging_allocator.allocate
        = &__atomic_allocator_syspaging_allocate_large;
    ptr_allocator->syspaging_allocator.allocate_alignment
        = &__atomic_allocator_syspaging_allocate_alignment;
    ptr_allocator->syspaging_allocator.deallocate
        = &__atomic_allocator_syspaging_deallocate;
 
    ptr_allocator->syspaging_category
        = large_page;
    return
        ptr_allocator;
}

__atomic_allocator_syspaging*
    __atomic_allocator_syspaging_initialize_huge
        ()
{
    __atomic_allocator_syspaging*
        ptr_allocator
            = malloc(sizeof(__atomic_allocator_syspaging));
    
    ptr_allocator->syspaging_allocator.allocate
        = &__atomic_allocator_syspaging_allocate_huge;
    ptr_allocator->syspaging_allocator.allocate_alignment
        = &__atomic_allocator_syspaging_allocate_alignment;
    ptr_allocator->syspaging_allocator.deallocate
        = &__atomic_allocator_syspaging_deallocate;

    ptr_allocator->syspaging_category
        = huge_page;
    return
        ptr_allocator;
}

void
    __atomic_allocator_syspaging_cleanup
        (__atomic_allocator_syspaging* pAllocator)
{
    free
        (pAllocator);
}