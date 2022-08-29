#pragma once

#include <atomic_structure/allocator/allocator.h>
#include <atomic_structure/fixed_stack/fixed_stack_type.h>

void*
    atomic_fixed_stack_pop
        (atomic_fixed_stack);

void*
    atomic_fixed_stack_pop_until_success
        (atomic_fixed_stack);

void
    atomic_fixed_stack_push
        (atomic_fixed_stack, void*);