#pragma once
#include <atomic_structure/allocator/details/details_allocator_type.h>

typedef struct
    __atomic_fixed_stack_node
{
    volatile struct
        __atomic_fixed_stack_node*
            ptr_next_node;
    void*
        ptr_fixed_stack;
}   __atomic_fixed_stack_node;

typedef struct
    __atomic_fixed_stack
{
    __atomic_allocator*
        ptr_fixed_stack_allocator;
    size_t
        fixed_stack_node_count,
        fixed_stack_node_size ;
    volatile
        __atomic_fixed_stack_node*
            ptr_fixed_stack_node;
}   __atomic_fixed_stack;

#define __atomic_fixed_stack_node_data(pFixedNode)\
    ((uint8_t*)pFixedNode + sizeof(__atomic_fixed_stack_node))

#define __atomic_fixed_stack_node_next(pFixedNode, pFixedNodeDataSize)\
    ((uint8_t*)pFixedNode +\
        sizeof(__atomic_fixed_stack_node) + pFixedNodeDataSize)

#define __atomic_fixed_stack_size(pNodeDataSize, pNodeCount)\
    (sizeof(__atomic_fixed_stack) +\
        ((sizeof(__atomic_fixed_stack_node) + pNodeDataSize) *\
            pNodeCount))