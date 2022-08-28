#include <atomic_structure/details/circular_queue/cqueue.h>
#include <atomic_structure/mpmc/details/details_mpmc_init.h>

__atomic_mpmc*
    __atomic_mpmc_initialize
        (size_t pMpmcNodeCount, atomic_allocator* pMpmcAllocator)
{
    __atomic_mpmc*
        ptr_mpmc
            = __atomic_circular_queue_initialize
                    (pMpmcNodeCount, pMpmcAllocator);
    
    if(!ptr_mpmc || ptr_mpmc == -1)
        return 0;

    ptr_mpmc->ptr_cqueue_rdptr
        = ptr_mpmc->cqueue_node_ptr;
    ptr_mpmc->ptr_cqueue_wrptr
        = ptr_mpmc->cqueue_node_ptr;

    return
        ptr_mpmc;
}

void
    __atomic_mpmc_cleanup
        (__atomic_mpmc* pMpmc)
{
    __atomic_circular_queue_cleanup
        (pMpmc);
}