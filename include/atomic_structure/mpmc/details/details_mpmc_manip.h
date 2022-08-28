#pragma once

#include <stdbool.h>
#include <atomic_structure/mpmc/details/details_mpmc_types.h>

bool
    __atomic_mpmc_push
        (__atomic_mpmc*, void*);

void
    __atomic_mpmc_push_until_success
        (__atomic_mpmc*, void*);

void*
    __atomic_mpmc_pop
        (__atomic_mpmc*);

void*
    __atomic_mpmc_pop_until_success
        (__atomic_mpmc*);