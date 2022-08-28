#include <atomic_structure/stack/details/details_stack.h>
#include <assert.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
#include <stdatomic.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
#include <Windows.h>
#endif

__atomic_stack*
    __atomic_stack_initialize
        (atomic_allocator* pStackAllocator)
{
    __atomic_stack*
        ptr_stack
            = pStackAllocator->allocate
                (pStackAllocator, sizeof(__atomic_stack), 0);
    
    if(!ptr_stack || ptr_stack == -1)
        return 0;

    ptr_stack->ptr_stack_allocator
        = pStackAllocator;
    ptr_stack->ptr_stack_node
        = 0;
    
    return ptr_stack;
}

__atomic_stack_node*
    __atomic_stack_node_initialize
        (__atomic_stack* pStack, void* pStackNodeData)
{
    __atomic_stack_node*
        ptr_stack_node
            = pStack->ptr_stack_allocator->allocate
                (pStack->ptr_stack_allocator,
                    sizeof(__atomic_stack_node), 0);
    
    ptr_stack_node->ptr_node_data
        = pStackNodeData;
    ptr_stack_node->ptr_node_next
        = 0;

    return
        ptr_stack_node;
}

void
    __atomic_stack_cleanup
        (__atomic_stack* pStack)
{
    pStack->ptr_stack_allocator->deallocate
        (pStack->ptr_stack_allocator,
            sizeof(__atomic_stack), pStack);
}

void
    __atomic_stack_node_cleanup
        (__atomic_stack* pStack, __atomic_stack_node* pStackNode)
{
    pStack->ptr_stack_allocator->deallocate
        (pStack->ptr_stack_allocator,
            sizeof(__atomic_stack_node), pStackNode);
}