#pragma once
#include <stdbool.h>
#include <atomic_structure/spsc/spsc_type.h>

atomic_spsc_read_pointer
    atomic_spsc_retrieve_read_pointer
        (atomic_spsc);

atomic_spsc_write_pointer
    atomic_spsc_retrieve_write_pointer
        (atomic_spsc);

void*
    atomic_spsc_read_from
        (atomic_spsc, atomic_spsc_read_pointer);

void*
    atomic_spsc_read_from_until_success
        (atomic_spsc, atomic_spsc_read_pointer);

bool
    atomic_spsc_write_to
        (atomic_spsc, atomic_spsc_write_pointer, void*);

void
    atomic_spsc_write_to_until_success
        (atomic_spsc, atomic_spsc_write_pointer, void*);