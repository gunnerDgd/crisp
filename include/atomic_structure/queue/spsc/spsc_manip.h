#pragma once
#include <stdbool.h>
#include <atomic_structure/queue/spsc/spsc_type.h>

void*
    atomic_spsc_read_from
        (atomic_spsc);

void*
    atomic_spsc_read_from_until_success
        (atomic_spsc);

bool
    atomic_spsc_write_to
        (atomic_spsc, void*);

void
    atomic_spsc_write_to_until_success
        (atomic_spsc, void*);