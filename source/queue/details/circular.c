#include <atomic_structure/queue/details/circular.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
#include <sys/mman.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
#include <Windows.h>
#endif



__atomic_circular_queue*
    __atomic_circular_queue_initialize
        (__atomic_allocator* pCqueueAllocator,
         size_t              pCqueueNodeCount)
{
    __atomic_circular_queue*
        ptr_cqueue;
    if(pCqueueAllocator->allocate_max_size
            < __atomic_circular_queue_size(pCqueueNodeCount))
                return 0;
    
    ptr_cqueue
        = pCqueueAllocator->allocate
            (pCqueueAllocator->allocate_parameter,
                __atomic_circular_queue_size(pCqueueNodeCount), 0);
    return
        __atomic_circular_queue_initialize_from_memory
            (ptr_cqueue, 
                __atomic_circular_queue_size(pCqueueNodeCount),
                    pCqueueNodeCount);
}

__atomic_circular_queue*
    __atomic_circular_queue_initialize_from_memory
        (void*   pCqueueMemory    ,
         size_t* pCqueueMemorySize,
         size_t  pCqueueNodeCount)
{
    __atomic_circular_queue*
        ptr_cqueue = pCqueueMemory;
    
    if(pCqueueMemorySize
            < __atomic_circular_queue_size(pCqueueNodeCount)) {
        *pCqueueMemorySize
            = __atomic_circular_queue_size(pCqueueNodeCount)
                    - *pCqueueMemorySize;
        return 0;
    }
    
    ptr_cqueue->cqueue_node_count
        = pCqueueNodeCount;
    ptr_cqueue->cqueue_node_ptr
        = (uint8_t*)ptr_cqueue + sizeof(__atomic_circular_queue);

    for(size_t it_init = 0                    ;
               it_init < pCqueueNodeCount - 1 ;
               it_init++)
    {
        ptr_cqueue
            ->cqueue_node_ptr[it_init].ptr_cqueue_data
                = 0;
        ptr_cqueue
            ->cqueue_node_ptr[it_init].ptr_cqueue_next
                = &ptr_cqueue->cqueue_node_ptr[it_init + 1];
    }

    ptr_cqueue
        ->cqueue_node_ptr[pCqueueNodeCount - 1].ptr_cqueue_data
            = 0;
    ptr_cqueue
        ->cqueue_node_ptr[pCqueueNodeCount - 1].ptr_cqueue_next
            = ptr_cqueue->cqueue_node_ptr;
    
    ptr_cqueue->ptr_cqueue_rdptr
        = ptr_cqueue->cqueue_node_ptr;
    ptr_cqueue->ptr_cqueue_wrptr
        = ptr_cqueue->ptr_cqueue_rdptr->ptr_cqueue_next;

    return
        ptr_cqueue;
} 