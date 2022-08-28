#include <atomic_structure/spsc/details/details_spsc_init.h>
#include <atomic_structure/details/circular_queue/cqueue.h>

__atomic_spsc*
    __atomic_spsc_initialize
        (size_t pSpscNodeCount)
{
    return
        __atomic_circular_queue_initialize
            (pSpscNodeCount);
}

void
    __atomic_spsc_cleanup
        (__atomic_spsc* pSpsc)
{
    __atomic_circular_queue_cleanup
        (pSpsc);
}