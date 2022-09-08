#pragma once
#include <stdint.h>
#include <stddef.h>

typedef struct
    atomic_mpmc
        { uint64_t handle[2]; }
            atomic_mpmc;