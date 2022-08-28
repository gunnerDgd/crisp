#pragma once
#include <atomic_structure/spsc/spsc_type.h>

atomic_spsc
    atomic_spsc_initialize
        (size_t);

void
    atomic_spsc_cleanup
        (atomic_spsc);