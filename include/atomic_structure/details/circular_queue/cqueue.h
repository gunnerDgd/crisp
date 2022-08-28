#include <atomic_structure/details/circular_queue/cqueue_type.h>

__atomic_circular_queue*
    __atomic_circular_queue_initialize
        (size_t);

void
    __atomic_circular_queue_cleanup
        (__atomic_circular_queue*);