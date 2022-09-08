#include <atomic_structure/queue/spsc/spsc_init.h>
#include <atomic_structure/queue/spsc/details/details_spsc_init.h>

atomic_spsc
    atomic_spsc_initialize
        (size_t           pSpscCount, 
         atomic_allocator pSpscAllocator)
{
    return
        __atomic_spsc_initialize
            (pSpscCount, pSpscAllocator.handle).hnd_spsc;
}

void
    atomic_spsc_cleanup
        (atomic_spsc pSpsc)
{
    __atomic_spsc
        hnd_spsc = { .hnd_spsc = pSpsc };
    
    if(pSpsc.handle)
        __atomic_spsc_cleanup(hnd_spsc);
}