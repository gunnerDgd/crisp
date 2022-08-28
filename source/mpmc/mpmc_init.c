#include <atomic_structure/mpmc/mpmc_init.h>
#include <atomic_structure/mpmc/details/details_mpmc_init.h>

atomic_mpmc
    atomic_mpmc_initialize
        (size_t pMpmcNodeCount, atomic_allocator* pMpmcAllocator)
{
    atomic_mpmc
        ptr_mpmc
            = { .handle 
                    = __atomic_mpmc_initialize
                            (pMpmcNodeCount, pMpmcAllocator) };
    
    return
        ptr_mpmc;
}

void
    atomic_mpmc_cleanup
        (atomic_mpmc pMpmc)
{
    __atomic_mpmc_cleanup(pMpmc.handle);
}