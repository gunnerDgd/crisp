#pragma once

#include <stdbool.h>
#include <atomic_structure/spsc/details/details_spsc_type.h>

void*
    __atomic_spsc_read_from
        (__atomic_spsc*);

void*
    __atomic_spsc_read_from_until_success
        (__atomic_spsc*);

bool
    __atomic_spsc_write_to
        (__atomic_spsc*, void*);

void
    __atomic_spsc_write_to_until_success
        (__atomic_spsc*, void*);
