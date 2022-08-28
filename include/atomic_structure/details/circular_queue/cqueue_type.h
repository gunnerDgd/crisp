#pragma once
#include <atomic_structure/allocator/allocator.h>

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
    size_t
        cqueue_node_count;
    atomic_allocator*
        cqueue_allocator_ptr;
    
    volatile
        __atomic_circular_queue_node
            *ptr_cqueue_rdptr,
            *ptr_cqueue_wrptr;
}   __atomic_circular_queue;