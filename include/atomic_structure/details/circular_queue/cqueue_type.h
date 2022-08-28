#pragma once

#include <stdint.h>
#include <stddef.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
#include <pthread.h>
#endif

typedef struct
    __atomic_circular_queue_node
{
    volatile struct 
        __atomic_circular_queue_node*
            ptr_cqueue_next;
    volatile
        void*
            ptr_cqueue_data;
}   __atomic_circular_queue_node;

typedef struct
    __atomic_circular_queue
{
    __atomic_circular_queue_node*
        cqueue_node_ptr;
    volatile
        __atomic_circular_queue_node
            *ptr_cqueue_rdptr,
            *ptr_cqueue_wrptr;
    size_t
        cqueue_node_count;
}   __atomic_circular_queue;