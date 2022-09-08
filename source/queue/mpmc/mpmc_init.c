#include <atomic_structure/queue/mpmc/mpmc_init.h>
#include <atomic_structure/queue/mpmc/details/details_mpmc_init.h>

atomic_mpmc
    atomic_mpmc_initialize
        (size_t pMpmcNodeCount, atomic_allocator pMpmcAllocator)
{
    return
        __atomic_mpmc_initialize
            (pMpmcNodeCount, pMpmcAllocator.handle).hnd_mpmc;
}

void
    atomic_mpmc_cleanup
        (atomic_mpmc pMpmc)
{
    __atomic_mpmc
        hnd_mpmc 
            = { .hnd_mpmc = pMpmc };
    __atomic_mpmc_cleanup(hnd_mpmc);
}