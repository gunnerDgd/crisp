#include <atomic_structure/stack/stack.h>
#include <atomic_structure/stack/details/details_stack.h>

void
    atomic_stack_initialize
        (atomic_stack* pStack)
{
    if(pStack)
        __atomic_stack_initialize
            (pStack);
}

void
    atomic_stack_node_initialize
        (atomic_stack_node* pStackNode, void* pStackNodeData)
{
    if(pStackNode)
        __atomic_stack_node_initialize
            (pStackNode, pStackNodeData);
}

void*
    atomic_stack_node_data
        (atomic_stack_node* pStackNode)
{
    return
        __atomic_stack_node_data(pStackNode);
}

void
    atomic_stack_push
        (atomic_stack* pStack, atomic_stack_node* pStackNode)
{
    if(pStack)
        __atomic_stack_push
            (pStack, pStackNode);
}

atomic_stack_node*
    atomic_stack_pop
        (atomic_stack* pStack)
{
    return
        (pStack) 
            ? __atomic_stack_pop(pStack)
                : 0;
}

atomic_stack_node*
    atomic_stack_pop_until_success
        (atomic_stack* pStack)
{
    return
        (pStack)
            ?__atomic_stack_pop_until_success(pStack)
                : 0;
}