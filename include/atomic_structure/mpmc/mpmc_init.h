#pragma once

#include <atomic_structure/allocator/allocator.h>
#include <atomic_structure/mpmc/mpmc_type.h>

atomic_mpmc
    atomic_mpmc_initialize
        (size_t, atomic_allocator*);

void
    atomic_mpmc_cleanup
        (atomic_mpmc);