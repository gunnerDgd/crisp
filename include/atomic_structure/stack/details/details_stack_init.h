#pragma once
#include <atomic_structure/stack/details/details_stack_type.h>

void
    __atomic_stack_initialize
        (__atomic_stack*, __atomic_allocator*);

__atomic_stack_node*
    __atomic_stack_node_initialize
        (__atomic_stack*, void*);

void
    __atomic_stack_cleanup
        (__atomic_stack*);

void
    __atomic_stack_node_cleanup
        (__atomic_stack*, __atomic_stack_node*);