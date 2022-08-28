#pragma once

#include <stdint.h>
#include <stddef.h>

typedef struct
    atomic_stack { uint8_t opaque[16]; } 
        atomic_stack;

typedef struct
    atomic_stack_node { uint8_t opaque[16]; }
        atomic_stack_node;