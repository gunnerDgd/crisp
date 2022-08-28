#include <atomic_structure/details/circular_queue/cqueue.h>
#include <atomic_structure/mpmc/details/details_mpmc_manip.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
#include <stdatomic.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
#include <Windows.h>
#endif

void*
    __atomic_mpmc_pop
        (__atomic_mpmc* pMpmcQueue)
{
    __atomic_mpmc_node*
        ptr_pop_node      = 0;
    void*
        ptr_pop_node_data = 0;
    
    do
    {
        ptr_pop_node
            = pMpmcQueue->ptr_cqueue_rdptr;
        
        if(ptr_pop_node 
                == pMpmcQueue->ptr_cqueue_wrptr)
                    return 0;
    }
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    while
        (InterlockedCompareExchange64
            (&pMpmcQueue->ptr_cqueue_rdptr,
                ptr_pop_node->ptr_cqueue_next, ptr_pop_node) != ptr_pop_node);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    while
        (!atomic_compare_exchange_weak
            (&pMpmcQueue->ptr_cqueue_rdptr,
                &ptr_pop_node, ptr_pop_node->ptr_cqueue_next));
#endif
    
    do
    {
__do_mpmc_read:
        ptr_pop_node_data
            = ptr_pop_node->ptr_cqueue_data;
        if(!ptr_pop_node_data)
            goto __do_mpmc_read;
    }
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    while
        (InterlockedCompareExchange64
            (&ptr_pop_node->ptr_cqueue_data, 0, ptr_pop_node_data) 
                != ptr_pop_node_data);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    while
        (!atomic_compare_exchange_weak
            (&ptr_pop_node->ptr_cqueue_data, &ptr_pop_node_data, 0));
#endif

    return
        ptr_pop_node_data;
}

void*
    __atomic_mpmc_pop_until_success
        (__atomic_mpmc* pMpmcQueue)
{
    void*
        ptr_read;
    
    while
        (!(ptr_read
            = __atomic_mpmc_pop(pMpmcQueue)));
    
    return ptr_read;
}

bool
    __atomic_mpmc_push
        (__atomic_mpmc* pMpmcQueue, void* pMpmcData)
{
    __atomic_mpmc_node*
        ptr_push_node = 0;
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    void*
        ptr_atomic_comparand = 0;
#endif

    do
    {
        ptr_push_node
            = pMpmcQueue->ptr_cqueue_wrptr;
        
        if(ptr_push_node->ptr_cqueue_next
                == pMpmcQueue->ptr_cqueue_rdptr)
                    return false;
    }
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS 
    while
        (InterlockedCompareExchange64
            (&pMpmcQueue->ptr_cqueue_wrptr, 
                    ptr_push_node->ptr_cqueue_next, ptr_push_node) 
                        != ptr_push_node);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    while
        (!atomic_compare_exchange_weak
            (&pMpmcQueue->ptr_cqueue_wrptr,
                &ptr_push_node, ptr_push_node->ptr_cqueue_next));
#endif
    
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    while
        (InterlockedCompareExchange64
            (&ptr_push_node->ptr_cqueue_data, pMpmcData, 0));
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    while
        (!atomic_compare_exchange_weak
            (&ptr_push_node->ptr_cqueue_data, 
                &ptr_atomic_comparand, pMpmcData));
#endif

    return true;
}

void
    __atomic_mpmc_push_until_success
        (__atomic_mpmc* pMpmcQueue, void* pMpmcData)
{
    while
        (!__atomic_mpmc_push(pMpmcQueue, pMpmcData));
}