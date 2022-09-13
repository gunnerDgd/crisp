#include <atomic_structure/stack/details/details_stack_init.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
#include <stdatomic.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
#include <Windows.h>
#endif

void
    __atomic_stack_initialize
        (__atomic_stack*     pStackHandle,
         __atomic_allocator* pStackAllocator)
{
    pStackHandle->ptr_stack_allocator
        = pStackAllocator;
    pStackHandle->ptr_stack_node
        = 0;
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
    __atomic_stack_node*
        ptr_node = pStack->ptr_stack_node;
    
    while(ptr_node) {
        __atomic_stack_node*
            ptr_erase_next
                = ptr_node->ptr_node_next;
        
        __atomic_stack_node_cleanup
            (pStack, ptr_node);
    }
}

void
    __atomic_stack_node_cleanup
        (__atomic_stack* pStack, __atomic_stack_node* pStackNode)
{
    pStack->ptr_stack_allocator->deallocate
        (pStack->ptr_stack_allocator,
            sizeof(__atomic_stack_node), pStackNode);
}