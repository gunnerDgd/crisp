#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct
    atomic_spsc
        { void* handle; }
            atomic_spsc;

typedef struct
    atomic_spsc_read_pointer
        { void* handle; }
            atomic_spsc_read_pointer;

typedef struct
    atomic_spsc_write_pointer
        { void* handle; }
            atomic_spsc_write_pointer;