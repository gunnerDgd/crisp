#include <atomic_structure/queue/spsc/details/details_spsc_init.h>
#include <atomic_structure/queue/details/circular.h>

__atomic_spsc
    __atomic_spsc_initialize
        (size_t              pSpscNodeCount, 
         __atomic_allocator* pSpscAllocator)
{
    __atomic_spsc
        ptr_spsc = 
            { .ptr_spsc_circular
                    =__atomic_circular_queue_initialize
                            (pSpscNodeCount, pSpscAllocator),
              .ptr_spsc_allocator
                    = pSpscAllocator
            };

    return
        ptr_spsc;
}

__atomic_spsc
    __atomic_spsc_initialize_from_memory
        (void*  pSpscMemory    ,
         size_t pSpscMemorySize,
         size_t pSpscNodeCount)
{
    __atomic_spsc
        ptr_spsc = 
            { .ptr_spsc_circular
                    = __atomic_circular_queue_initialize_from_memory
                            (pSpscNodeCount, pSpscMemorySize, pSpscNodeCount),
              .ptr_spsc_allocator
                    = 0
            };

    return
        ptr_spsc;
}

__atomic_spsc
    __atomic_spsc_initialize_from_circular
        (__atomic_circular_queue* pSpscExistingCqueue)
{
    __atomic_spsc
        ptr_spsc = 
            { .ptr_spsc_circular
                    =__atomic_circular_queue_initialize_from_existing
                            (pSpscExistingCqueue),
              .ptr_spsc_allocator
                    = 0
            };

    return
        ptr_spsc;
}

void
    __atomic_spsc_cleanup
        (__atomic_spsc pSpsc)
{
    if(pSpsc.ptr_spsc_allocator)
        pSpsc.ptr_spsc_allocator->deallocate
            (pSpsc.ptr_spsc_allocator->allocate_parameter,
                __atomic_circular_queue_size
                    (pSpsc.ptr_spsc_circular->cqueue_node_count),
                        pSpsc.ptr_spsc_circular);
}