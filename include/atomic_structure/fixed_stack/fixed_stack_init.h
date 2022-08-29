#pragma once

#include <atomic_structure/allocator/allocator.h>
#include <atomic_structure/fixed_stack/fixed_stack_type.h>

atomic_fixed_stack
    atomic_fixed_stack_initialize
        (atomic_allocator*, size_t, size_t);

void
    atomic_fixed_stack_cleanup
        (atomic_fixed_stack);