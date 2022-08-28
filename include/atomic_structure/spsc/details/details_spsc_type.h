#pragma once
#include <atomic_structure/details/circular_queue/cqueue.h>

typedef
    __atomic_circular_queue
        __atomic_spsc;

typedef
    __atomic_circular_queue_node
        __atomic_spsc_node;