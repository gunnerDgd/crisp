#include <iostream>

#include <atomic>
#include <thread>

extern "C"
{
#include <atomic_structure/mpmc/mpmc.h>
#include <atomic_structure/allocator/system_paging.h>
}

void
    atomic_structure_testcase_mpmc_push
        (atomic_mpmc pMpmc, std::size_t pIterationCount)
{
    for(std::size_t it_iter  = 1 ;
                    it_iter <= pIterationCount ;
                    it_iter++)
    {
        std::size_t*
            MpmcPushData = new std::size_t(it_iter);
        atomic_mpmc_push_until_success
            (pMpmc, MpmcPushData);
    }
}

void
    atomic_structure_testcase_mpmc_pop
        (atomic_mpmc pMpmc, std::size_t pIterationCount, std::atomic<std::size_t>& pPopSum)
{
    for(std::size_t it_iter  = 1              ;
                    it_iter <= pIterationCount;
                    it_iter++)
    {
        std::size_t*
            MpmcPopData
                = reinterpret_cast<std::size_t*>
                    (atomic_mpmc_pop_until_success(pMpmc));
        
        pPopSum.fetch_add(*MpmcPopData);
    }
}

std::thread
    *MpmcPushThread[4],
    *MpmcPopThread [4];

int main(int argc, char** argv)
{
    atomic_allocator*
        MpmcQueueAllocator
            = atomic_allocator_syspaging_initialize();
    std::cout
        << "[ATOMIC_STRUCTURE][MPMC] Allocator Initialized\n";
    size_t
        MpmcQueueNodeCount
            = std::atoi(argv[1]);
    atomic_mpmc
        MpmcQueue
            = atomic_mpmc_initialize
                    (MpmcQueueNodeCount, MpmcQueueAllocator);
    std::cout
        << "[ATOMIC_STRUCTURE][MPMC] MPMC Initialized\n";
    std::atomic<std::size_t>
        MpmcValidationSum(0);
    
    std::cout
        << "[ATOMIC_STRUCTURE][MPMC] Test Started\n";


    for(auto& it_push_thread : MpmcPushThread)
        it_push_thread
            = new std::thread
                (atomic_structure_testcase_mpmc_push,
                    MpmcQueue, MpmcQueueNodeCount / 4);
    for(auto& it_pop_thread : MpmcPopThread)
        it_pop_thread
            = new std::thread
                (atomic_structure_testcase_mpmc_pop,
                    MpmcQueue, MpmcQueueNodeCount / 4, std::ref(MpmcValidationSum));
    
    for(auto& it_push_thread : MpmcPushThread)
        it_push_thread->join();
    for(auto& it_pop_thread : MpmcPopThread)
        it_pop_thread->join();
    
    std::cout
        << "[ATOMIC_STRUCTURE][MPMC] Validation Sum : " 
        << MpmcValidationSum << std::endl;
}