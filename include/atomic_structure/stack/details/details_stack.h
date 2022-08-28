#pragma once
#include <atomic_structure/stack/details/details_stack_type.h>

__atomic_stack*
    __atomic_stack_initialize
        (atomic_allocator*);

__atomic_stack_node*
    __atomic_stack_node_initialize
        (__atomic_stack*, void*);

void
    __atomic_stack_cleanup
        (__atomic_stack*);

void
    __atomic_stack_node_cleanup
        (__atomic_stack*, __atomic_stack_node*);

void
    __atomic_stack_push
        (__atomic_stack*, void*);

void*
    __atomic_stack_pop
        (__atomic_stack*);

void*
    __atomic_stack_pop_until_success
        (__atomic_stack*);