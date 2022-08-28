#pragma once

#include <atomic_structure/stack/stack_type.h>
#include <atomic_structure/allocator/allocator.h>

atomic_stack
    atomic_stack_initialize
        (atomic_allocator*);

void
    atomic_stack_cleanup
        (atomic_stack);

void
    atomic_stack_push
        (atomic_stack, void*);

void*
    atomic_stack_pop
        (atomic_stack);

void*
    atomic_stack_pop_until_success
        (atomic_stack);