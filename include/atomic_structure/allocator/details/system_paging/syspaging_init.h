#pragma once
#include <atomic_structure/allocator/details/system_paging/syspaging_type.h>

__atomic_allocator_syspaging*
    __atomic_allocator_syspaging_initialize
        ();

__atomic_allocator_syspaging*
    __atomic_allocator_syspaging_initialize_large
        ();

__atomic_allocator_syspaging*
    __atomic_allocator_syspaging_initialize_huge
        ();

void
    __atomic_allocator_syspaging_cleanup
        (__atomic_allocator_syspaging*);