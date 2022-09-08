#include <atomic_structure/queue/details/circular.h>
#include <atomic_structure/queue/mpmc/details/details_mpmc_init.h>

__atomic_mpmc
    __atomic_mpmc_initialize
        (size_t pMpmcNodeCount, __atomic_allocator* pMpmcAllocator)
{
    __atomic_mpmc
        ptr_mpmc
            = {
                .ptr_mpmc_allocator = pMpmcAllocator,
                .ptr_mpmc_circular
                    = __atomic_circular_queue_initialize
                            (pMpmcAllocator, pMpmcNodeCount)
              };
    
    ptr_mpmc.ptr_mpmc_circular->ptr_cqueue_rdptr
        = ptr_mpmc.ptr_mpmc_circular->cqueue_node_ptr;
    ptr_mpmc.ptr_mpmc_circular->ptr_cqueue_wrptr
        = ptr_mpmc.ptr_mpmc_circular->cqueue_node_ptr;

    return
        ptr_mpmc;
}

__atomic_mpmc
    __atomic_mpmc_intialize_from_memory
        (void*  pMpmcMemory, 
         size_t pMpmcMemorySize, 
         size_t pMpmcNodeCount)
{
    __atomic_mpmc
        ptr_mpmc
            = {
                .ptr_mpmc_allocator = 0,
                .ptr_mpmc_circular
                    = __atomic_circular_queue_initialize_from_memory
                            (pMpmcMemory, pMpmcMemorySize, pMpmcNodeCount)
              };
    
    ptr_mpmc.ptr_mpmc_circular->ptr_cqueue_rdptr
        = ptr_mpmc.ptr_mpmc_circular->cqueue_node_ptr;
    ptr_mpmc.ptr_mpmc_circular->ptr_cqueue_wrptr
        = ptr_mpmc.ptr_mpmc_circular->cqueue_node_ptr;

    return
        ptr_mpmc;
}

__atomic_mpmc
    __atomic_mpmc_initialize_from_circular
        (__atomic_circular_queue* pMpmcExisting)
{
    __atomic_mpmc
        ptr_mpmc
            = {
                .ptr_mpmc_allocator = 0,
                .ptr_mpmc_circular
                    = __atomic_circular_queue_initialize_from_existing
                            (pMpmcExisting)
              };
    
    return
        ptr_mpmc;
}

void
    __atomic_mpmc_cleanup
        (__atomic_mpmc pMpmc)
{
    if(pMpmc.ptr_mpmc_allocator)
        pMpmc.ptr_mpmc_allocator->deallocate
            (pMpmc.ptr_mpmc_allocator->allocate_parameter,
                __atomic_circular_queue_size
                    (pMpmc.ptr_mpmc_circular->cqueue_node_count),
                        pMpmc.ptr_mpmc_circular);
}