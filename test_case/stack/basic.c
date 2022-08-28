#include <atomic_structure/stack/stack.h>
#include <atomic_structure/allocator/aligned_heap.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>

#include <stdint.h>
#include <stddef.h>

void
    atomic_structure_testcase_stack_push
        (atomic_stack, uint64_t);

uint64_t
    atomic_structure_testcase_stack_pop
        (atomic_stack, uint64_t);

int main(int argc, char** argv)
{
    uint64_t          AtomicStackTestValue = atoi(argv[1]);
    atomic_stack      AtomicStack;
    atomic_allocator* AtomicStackAllocator
                        = atomic_allocator_aligned_heap_initialize(16);

    fprintf
        (stdout, "[ATOMIC_STRUCTURE][STACK] Test Begin\r\n");
    AtomicStack
        = atomic_stack_initialize(AtomicStackAllocator);

    atomic_structure_testcase_stack_push
        (AtomicStack, AtomicStackTestValue);
    AtomicStackTestValue
        = atomic_structure_testcase_stack_pop
            (AtomicStack, AtomicStackTestValue);

    fprintf
        (stdout, 
            "[ATOMIC_STRUCTURE][STACK] Test Result : %d\r\n", 
                AtomicStackTestValue);
}

void
    atomic_structure_testcase_stack_push
        (atomic_stack pStack, uint64_t pIteration)
{
    fprintf(stdout, "[ATOMIC_STRUCTURE][STACK] Push Test Begin\r\n");
    
    for(int i = 1 ; i <= pIteration ; i++)
    {
        size_t*
            AtomicStackNodeData = malloc(8);
        
        *AtomicStackNodeData = i;
        atomic_stack_push
            (pStack, AtomicStackNodeData);
    }
}

uint64_t
    atomic_structure_testcase_stack_pop
        (atomic_stack pStack, uint64_t pIteration)
{
    uint64_t AtomicStackSum = 0;
    fprintf
        (stdout, "[ATOMIC_STRUCTURE][STACK] Pop Test Begin\r\n");

    for(int i = 1 ; i <= pIteration ; i++)
    {
        AtomicStackSum
            += *(uint64_t*)atomic_stack_pop_until_success(pStack);
        fprintf
            (stdout, "[ATOMIC_STRUCTURE][STACK] Pop Sum : %d\r\n",
                AtomicStackSum);
    }

    return
        AtomicStackSum;
}