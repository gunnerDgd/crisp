#pragma once
#include <atomic_structure/allocator/allocator.h>

typedef struct
    __atomic_stack_node
{
    volatile
        struct __atomic_stack_node*
            ptr_node_next;
    void*
        ptr_node_data;
}   __atomic_stack_node;

typedef struct
    __atomic_stack
{
    atomic_allocator*
        ptr_stack_allocator;
    volatile
        __atomic_stack_node*
            ptr_stack_node;
}   __atomic_stack;