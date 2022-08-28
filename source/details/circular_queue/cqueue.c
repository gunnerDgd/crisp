#include <atomic_structure/details/circular_queue/cqueue.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
#include <sys/mman.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
#include <Windows.h>
#endif

#define __atomic_circular_queue_size(pCqueueNodeCount)\
    ((pCqueueNodeCount * sizeof(__atomic_circular_queue_node))\
        + sizeof(__atomic_circular_queue))

__atomic_circular_queue*
    __atomic_circular_queue_initialize
        (size_t pCqueueNodeCount)
{
    __atomic_circular_queue*
        ptr_cqueue
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
            = mmap
                (0, __atomic_circular_queue_size(pCqueueNodeCount),
                    PROT_READ | PROT_WRITE, 
                        MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
            = VirtualAlloc
                    (0, __atomic_circular_queue_size(pCqueueNodeCount),
                        MEM_COMMIT, PAGE_READWRITE);
#endif
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

void
    __atomic_circular_queue_cleanup
        (__atomic_circular_queue* pCqueue)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
    munmap
        (pCqueue, 
            __atomic_circular_queue_size(pCqueue->cqueue_node_count));
        
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    VirtualFree
        (pCqueue, 0, MEM_FREE);
#endif
}