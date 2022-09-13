#pragma once
#include <atomic_structure/stack/stack_type.h>
#include <atomic_structure/allocator/details/details_allocator_type.h>

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
    union
    {
        struct
        {
            __atomic_allocator*
                ptr_stack_allocator;
            volatile
                __atomic_stack_node*
                    ptr_stack_node;
        };

        atomic_stack
            hnd_stack;
    };
}   __atomic_stack;