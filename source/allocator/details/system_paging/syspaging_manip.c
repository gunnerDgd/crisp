#include <atomic_structure/allocator/details/system_paging/syspaging_manip.h>

size_t
    __atomic_allocator_syspaging_allocate_alignment
        (__atomic_allocator_syspaging* pAllocator)
{
    return
        pAllocator->syspaging_category;
}

void*
    __atomic_allocator_syspaging_allocate
        (__atomic_allocator_syspaging* pAllocator   , 
         size_t                        pAllocateSize, 
         void*                         pAllocateHint)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    return
        mmap
            (pAllocateHint, pAllocateSize,
                PROT_READ | PROT_WRITE,
                    MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    return
        VirtualAlloc
            (pAllocateHint, pAllocateSize, 
                MEM_COMMIT, PAGE_READWRITE);
#endif
}

void*
    __atomic_allocator_syspaging_allocate_large
        (__atomic_allocator_syspaging* pAllocator   ,
         size_t                        pAllocateSize,
         void*                         pAllocateHint)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    return
        mmap
            (pAllocateHint, pAllocateSize,
                PROT_READ | PROT_WRITE,
                    MAP_ANONYMOUS | MAP_PRIVATE | MAP_HUGETLB | (21 << MAP_HUGE_SHIFT), -1, 0);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    return
        VirtualAlloc
            (pAllocateHint, pAllocateSize,
                MEM_COMMIT | MEM_64K_PAGES, PAGE_READWRITE);
#endif
}

void*
    __atomic_allocator_syspaging_allocate_huge
        (__atomic_allocator_syspaging* pAllocator   , 
         size_t                        pAllocateSize, 
         void*                         pAllocateHint)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    return
        mmap
            (pAllocateHint, pAllocateSize,
                PROT_READ | PROT_WRITE,
                    MAP_ANONYMOUS | MAP_PRIVATE | MAP_HUGETLB | (30 << MAP_HUGE_SHIFT), -1, 0);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    return
        VirtualAlloc
            (pAllocateHint, pAllocateSize,
                MEM_COMMIT | MEM_4MB_PAGES, PAGE_READWRITE);
#endif
}

void
    __atomic_allocator_syspaging_deallocate
        (__atomic_allocator_syspaging* pAllocator     ,
         size_t                        pDeallocateSize, 
         void*                         pDeallocatePtr)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    munmap
        (pDeallocatePtr, pDeallocateSize);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    VirtualFree
        (pDeallocatePtr, 0, MEM_FREE);
#endif
}