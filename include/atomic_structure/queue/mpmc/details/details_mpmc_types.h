#pragma once
#include <atomic_structure/queue/details/circular.h>
#include <atomic_structure/queue/mpmc/mpmc_type.h>

#include <atomic_structure/allocator/details/details_allocator.h>

typedef struct
    __atomic_mpmc
{
    union
    {
        struct
        {
            __atomic_circular_queue*
                ptr_mpmc_circular ;
            __atomic_allocator*
                ptr_mpmc_allocator;
        };
        atomic_mpmc
            hnd_mpmc;
    };
}   __atomic_mpmc;

typedef
    __atomic_circular_queue_node
        __atomic_mpmc_node;