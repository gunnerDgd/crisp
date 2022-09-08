#pragma once
#include <atomic_structure/queue/spsc/spsc_type.h>
#include <atomic_structure/queue/details/circular_type.h>

#include <atomic_structure/allocator/details/details_allocator_type.h>

typedef struct
    __atomic_spsc
{
    union
    {
        struct
        {
            __atomic_circular_queue*
                ptr_spsc_circular;
            __atomic_allocator*
                ptr_spsc_allocator;
        };

        atomic_spsc hnd_spsc;
    };
}   __atomic_spsc;