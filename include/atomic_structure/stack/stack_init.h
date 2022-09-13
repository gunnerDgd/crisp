#pragma once

#include <atomic_structure/stack/stack_type.h>
#include <atomic_structure/allocator/allocator.h>

void
    atomic_stack_initialize
        (atomic_stack*, atomic_allocator*);

void
    atomic_stack_cleanup
        (atomic_stack*);