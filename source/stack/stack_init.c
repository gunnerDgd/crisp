#include <atomic_structure/stack/stack.h>

#include <atomic_structure/stack/details/details_stack_init.h>
#include <atomic_structure/stack/details/details_stack_manip.h>

void
    atomic_stack_initialize
        (atomic_stack*     pStack,
         atomic_allocator* pStackAllocator)
{
    __atomic_stack_initialize
        (pStack->handle, pStackAllocator->handle);
}

void
    atomic_stack_cleanup
        (atomic_stack* pStack)
{
    __atomic_stack_cleanup
        (pStack->handle);
}