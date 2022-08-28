#include <atomic_structure/details/circular_queue/cqueue.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
    atomic_structure_testcase_cqueue_sizeof
        ()
{
    fprintf
        (stderr,
            "[ATOMIC_STRUCTURE][TESTCASE] Circular Queue Size : %d\r\n\
             [ATOMIC_STRUCTURE][TESTCASE] Circular Queue Pointer Size : %d\r\n\
             [ATOMIC_STRUCTURE][TESTCASE] Circular Queue Node Size : %d\r\n",
                sizeof(__atomic_circular_queue),
                sizeof(__atomic_circular_queue_pointer),
                sizeof(__atomic_circular_queue_node));
}

void
    atomic_structure_testcase_cqueue_push
        (__atomic_circular_queue*, uint64_t);

uint64_t
    atomic_structure_testcase_cqueue_pop
        (__atomic_circular_queue*, uint64_t);

int main(int argc, char** argv)
{
    uint64_t 
        CqueueIterationCount = atoi(argv[1]);
    __atomic_circular_queue*
        CqueueHandle         = __atomic_circular_queue_initialize(CqueueIterationCount);
    
    fprintf
        (stderr,
            "[ATOMIC_STRUCTURE][TESTCASE] Circular Test Begin !!\r\n");
    
    atomic_structure_testcase_cqueue_sizeof();

    atomic_structure_testcase_cqueue_push
        (CqueueHandle, CqueueIterationCount);
    CqueueIterationCount
        = atomic_structure_testcase_cqueue_pop
                (CqueueHandle, CqueueIterationCount);
    
    fprintf
        (stderr,
            "[ATOMIC_STRUCTURE][TESTCASE] Circular Test Result : %d\r\n",
                CqueueIterationCount);
    __atomic_circular_queue_cleanup
        (CqueueHandle);
}

void
    atomic_structure_testcase_cqueue_push
        (__atomic_circular_queue* pCqueue, uint64_t pCqueueIterationCount)
{
    for(size_t it_push  = 1;
               it_push <= pCqueueIterationCount;
               it_push++)
    {
        fprintf
            (stderr,
                "[ATOMIC_STRUCTURE][TESTCASE] Circular Test Push : %08x\r\n\
                 [ATOMIC_STRUCTURE][TESTCASE] Circular Test Push Next :%08x\r\n",
                    pCqueue->ptr_cqueue_wrptr.ptr_cqueue_node,
                        pCqueue->ptr_cqueue_wrptr.ptr_cqueue_node->ptr_cqueue_next);
        pCqueue->ptr_cqueue_wrptr.ptr_cqueue_node->ptr_cqueue_data
            = it_push;
        pCqueue->ptr_cqueue_wrptr.ptr_cqueue_node
            = pCqueue->ptr_cqueue_wrptr.ptr_cqueue_node->ptr_cqueue_next;
    }
}

uint64_t
    atomic_structure_testcase_cqueue_pop
        (__atomic_circular_queue* pCqueue, uint64_t pCqueueIterationCount)
{
    size_t
        CqueueTestcaseResult = 0;
    
    for(size_t it_pop = 0;
               it_pop < pCqueueIterationCount;
               it_pop++)
    {
        fprintf
            (stderr,
                "[ATOMIC_STRUCTURE][TESTCASE] Circular Test Pop : %08x\r\n\
                 [ATOMIC_STRUCTURE][TESTCASE] Circular Test Pop Next :%08x\r\n",
                    pCqueue->ptr_cqueue_rdptr.ptr_cqueue_node,
                        pCqueue->ptr_cqueue_rdptr.ptr_cqueue_node->ptr_cqueue_next);
        CqueueTestcaseResult
            += (uint64_t)pCqueue->ptr_cqueue_rdptr.ptr_cqueue_node->ptr_cqueue_data;
        pCqueue->ptr_cqueue_rdptr.ptr_cqueue_node
            = pCqueue->ptr_cqueue_rdptr.ptr_cqueue_node->ptr_cqueue_next;
    }

    return
        CqueueTestcaseResult;
}