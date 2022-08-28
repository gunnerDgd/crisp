#include <atomic_structure/spsc/spsc_init.h>
#include <atomic_structure/spsc/details/details_spsc_init.h>

atomic_spsc
    atomic_spsc_initialize
        (size_t pSpscCount)
{
    atomic_spsc
        hnd_atomic_spsc = { .handle = 0 };

    if(pSpscCount < 2)
        return hnd_atomic_spsc;
    else {
        hnd_atomic_spsc.handle
            = __atomic_spsc_initialize(pSpscCount);
        return
            hnd_atomic_spsc;
    }
}

void
    atomic_spsc_cleanup
        (atomic_spsc pSpsc)
{
    if(pSpsc.handle)
        __atomic_spsc_cleanup(pSpsc.handle);
}