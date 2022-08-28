#pragma once
#include <atomic_structure/details/circular_queue/cqueue.h>

typedef
    __atomic_circular_queue
        __atomic_mpmc;

typedef
    __atomic_circular_queue_node
        __atomic_mpmc_node;