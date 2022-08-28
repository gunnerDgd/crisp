#pragma once
#include <atomic_structure/allocator/allocator.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
#include <sys/mman.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
#include <Windows.h>
#endif

typedef enum 
    __atomic_allocator_syspaging_category
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    normal     = 1024 * 4 ,
    large_page = 1024 * 1024 * 2,
    huge_page  = 1024 * 1024 * 1024
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    normal     = 1024 * 4 ,
    large_page = 1024 * 64,
    huge_page  = 1024 * 1024 * 4
#endif
}   __atomic_allocator_syspaging_category;

typedef struct
    __atomic_allocator_syspaging
{
    atomic_allocator
        syspaging_allocator;
    __atomic_allocator_syspaging_category
        syspaging_category;
}   __atomic_allocator_syspaging;