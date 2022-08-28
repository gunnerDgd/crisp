#pragma once
#include <atomic_structure/allocator/details/system_paging/syspaging_type.h>

size_t
    __atomic_allocator_syspaging_allocate_alignment
        (__atomic_allocator_syspaging*);

void*
    __atomic_allocator_syspaging_allocate
        (__atomic_allocator_syspaging*, size_t, void*);

void*
    __atomic_allocator_syspaging_allocate_large
        (__atomic_allocator_syspaging* pAllocator, size_t, void*);
    
void*
    __atomic_allocator_syspaging_allocate_huge
        (__atomic_allocator_syspaging*, size_t, void*);

void
    __atomic_allocator_syspaging_deallocate
        (__atomic_allocator_syspaging*, size_t, void*);
