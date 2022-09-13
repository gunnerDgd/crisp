#include <atomic_structure/stack/stack.h>

#include <atomic_structure/stack/details/details_stack_init.h>
#include <atomic_structure/stack/details/details_stack_manip.h>

void
    atomic_stack_push
        (atomic_stack* pStack, void* pStackNodeData)
{
    __atomic_stack_push
        (pStack->handle, pStackNodeData);
}

void*
    atomic_stack_pop
        (atomic_stack* pStack)
{
    return
        __atomic_stack_pop
            (pStack->handle);
}

void*
    atomic_stack_pop_until_success
        (atomic_stack* pStack)
{
    return
        __atomic_stack_pop_until_success
            (pStack->handle);
}