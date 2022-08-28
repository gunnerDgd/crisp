#include <atomic_structure/spsc/spsc.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
    atomic_structure_testcase_spsc_push
        (atomic_spsc, size_t);

size_t
    atomic_structure_testcase_spsc_pop
        (atomic_spsc, size_t);

int main(int argc, char** argv)
{
    size_t
        SpscIterationCount = atoi(argv[1]),
        SpscTestResult     = 0;
    atomic_spsc
        SpscQueue          = atomic_spsc_initialize(SpscIterationCount +  2);
    
    if(!SpscQueue.handle) {
        fprintf(stdout, "[ATOMIC_STRUCTURE][SPSC][FATAL-ERROR] MMAP Failed !!\r\n");
        return 0;
    }

    
    atomic_structure_testcase_spsc_push
        (SpscQueue, SpscIterationCount);
    SpscTestResult
        = atomic_structure_testcase_spsc_pop
            (SpscQueue, SpscIterationCount);

    fprintf(stdout, "[ATOMIC_STRUCTURE][SPSC] Test Result : %d\r\n", SpscTestResult);
    atomic_spsc_cleanup(SpscQueue);
}

void
    atomic_structure_testcase_spsc_push
        (atomic_spsc pSpscQueue, size_t pSpscIteration)
{

    for(size_t it_push  = 1;
               it_push <= pSpscIteration;
               it_push++)
    {
        size_t*
            SpscPushValue = malloc(8);
        *SpscPushValue
            = it_push;
        fprintf
            (stdout, "[ATOMIC_STRUCTURE][SPSC] Push Operation\r\n");

        
        atomic_spsc_write_to_until_success
            (pSpscQueue, SpscPushValue);
    }
}

size_t
    atomic_structure_testcase_spsc_pop
        (atomic_spsc pSpscQueue, size_t pSpscIteration)
{
    size_t
        SpscReadValueSum = 0;
    
    for(size_t it_pop = 0;
               it_pop < pSpscIteration;
               it_pop++)
    {
        size_t*
            SpscReadValue 
                = atomic_spsc_read_from_until_success(pSpscQueue);
        SpscReadValueSum
            += *SpscReadValue;
        fprintf(stdout, "[ATOMIC_STRUCTURE][SPSC] Pop Operation : %d\r\n", *SpscReadValue);
    }

    return
        SpscReadValueSum;
}