#include <atomic_structure/queue/details/circular_type.h>
#include <atomic_structure/allocator/details/details_allocator_type.h>

__atomic_circular_queue*
    __atomic_circular_queue_initialize
        (__atomic_allocator*, size_t);

__atomic_circular_queue*
    __atomic_circular_queue_initialize_from_memory
        (void*, size_t*, size_t);

#define __atomic_circular_queue_size(pCqueueNodeCount)\
    ((pCqueueNodeCount * sizeof(__atomic_circular_queue_node))\
        + sizeof(__atomic_circular_queue))