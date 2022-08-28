#include <atomic_structure/mpmc/mpmc_manip.h>
#include <atomic_structure/mpmc/details/details_mpmc_manip.h>

bool
    atomic_mpmc_push
        (atomic_mpmc pMpmc, void* pMpmcPushData)
{
    return
        __atomic_mpmc_push
            (pMpmc.handle, pMpmcPushData);
}

void
    atomic_mpmc_push_until_success
        (atomic_mpmc pMpmc, void* pMpmcPushData)
{
    __atomic_mpmc_push_until_success
        (pMpmc.handle, pMpmcPushData);
}

void*
    atomic_mpmc_pop
        (atomic_mpmc pMpmc)
{
    return
        __atomic_mpmc_pop
            (pMpmc.handle);
}

void*
    atomic_mpmc_pop_until_success
        (atomic_mpmc pMpmc)
{
    return
        __atomic_mpmc_pop_until_success
            (pMpmc.handle);
}