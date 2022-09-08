#pragma once

#include <stdbool.h>
#include <atomic_structure/queue/mpmc/mpmc_type.h>

bool
    atomic_mpmc_push
        (atomic_mpmc, void*);

void
    atomic_mpmc_push_until_success
        (atomic_mpmc, void*);

void*
    atomic_mpmc_pop
        (atomic_mpmc);

void*
    atomic_mpmc_pop_until_success
        (atomic_mpmc);