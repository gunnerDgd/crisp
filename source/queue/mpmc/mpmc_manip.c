#include <atomic_structure/queue/mpmc/mpmc_manip.h>
#include <atomic_structure/queue/mpmc/details/details_mpmc_manip.h>

bool
    atomic_mpmc_push
        (atomic_mpmc pMpmc, void* pMpmcPushData)
{
    return
        __atomic_mpmc_push
            (&pMpmc, pMpmcPushData);
}

void
    atomic_mpmc_push_until_success
        (atomic_mpmc pMpmc, void* pMpmcPushData)
{
    __atomic_mpmc_push_until_success
        (&pMpmc, pMpmcPushData);
}

void*
    atomic_mpmc_pop
        (atomic_mpmc pMpmc)
{
    return
        __atomic_mpmc_pop(&pMpmc);
}

void*
    atomic_mpmc_pop_until_success
        (atomic_mpmc pMpmc)
{
    return
        __atomic_mpmc_pop_until_success(&pMpmc);
}