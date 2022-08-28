#include <atomic_structure/stack/stack.h>
#include <atomic_structure/stack/details/details_stack.h>

atomic_stack
    atomic_stack_initialize
        (atomic_allocator* pStackAllocator)
{
    atomic_stack
        ptr_atomic_stack
            = { .handle = __atomic_stack_initialize(pStackAllocator) };
    
    return
        ptr_atomic_stack;
}

void
    atomic_stack_cleanup
        (atomic_stack pStack)
{
    __atomic_stack_cleanup
        (pStack.handle);
}

void
    atomic_stack_push
        (atomic_stack pStack, void* pStackNodeData)
{
    if(pStack.handle)
        __atomic_stack_push
            (pStack.handle, pStackNodeData);
}

void*
    atomic_stack_pop
        (atomic_stack pStack)
{
    return
        (pStack.handle) 
            ? __atomic_stack_pop(pStack.handle)
                : 0;
}

void*
    atomic_stack_pop_until_success
        (atomic_stack pStack)
{
    return
        (pStack.handle)
            ?__atomic_stack_pop_until_success(pStack.handle)
                : 0;
}