#pragma once
#include <atomic_structure/stack/details/details_stack_type.h>

void
    __atomic_stack_initialize
        (__atomic_stack*);

void
    __atomic_stack_node_initialize
        (__atomic_stack_node*, void*);

void*
    __atomic_stack_node_data
        (__atomic_stack_node*);

void
    __atomic_stack_push
        (__atomic_stack*, __atomic_stack_node*);

__atomic_stack_node*
    __atomic_stack_pop
        (__atomic_stack*);

__atomic_stack_node*
    __atomic_stack_pop_until_success
        (__atomic_stack*);