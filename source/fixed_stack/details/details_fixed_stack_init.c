#include <atomic_structure/fixed_stack/details/details_fixed_stack_init.h>

__atomic_fixed_stack*
    __atomic_fixed_stack_initialize
        (atomic_allocator* pFixedStackAllocator, 
         size_t            pFixedStackNodeCount, 
         size_t            pFixedStackNodeSize)
{
    __atomic_fixed_stack*
        ptr_fixed_stack;
    __atomic_fixed_stack_node*
        ptr_fixed_stack_node;
    
    if(pFixedStackAllocator->allocate_max_size
            (pFixedStackAllocator) < 
                __atomic_fixed_stack_size
                    (pFixedStackNodeSize, pFixedStackNodeCount))
                        return 0;

    if(pFixedStackAllocator->allocate_alignment
            (pFixedStackAllocator) % 16 != 0)
                return 0;

    ptr_fixed_stack
        = pFixedStackAllocator->allocate
            (pFixedStackAllocator,
                __atomic_fixed_stack_size
                    (pFixedStackNodeSize, pFixedStackNodeCount), 0);
                    
    ptr_fixed_stack_node
        = (uint8_t*)ptr_fixed_stack
                + sizeof(__atomic_fixed_stack);
    
    ptr_fixed_stack->ptr_fixed_stack_allocator
        = pFixedStackAllocator;
    ptr_fixed_stack->ptr_fixed_stack_node
        = ptr_fixed_stack_node;
    
    ptr_fixed_stack->fixed_stack_node_count
        = pFixedStackNodeCount;
    ptr_fixed_stack->fixed_stack_node_size
        = pFixedStackNodeSize;
    
    for (size_t it_init = 0;
                it_init < pFixedStackNodeCount - 1;
                it_init++)
    {
        ptr_fixed_stack_node->ptr_fixed_stack
            = ptr_fixed_stack;
        ptr_fixed_stack_node->ptr_next_node
            = __atomic_fixed_stack_node_next
                    (ptr_fixed_stack_node,
                        ptr_fixed_stack->fixed_stack_node_size);
        
        ptr_fixed_stack_node
            = ptr_fixed_stack_node->ptr_next_node;
    }

    ptr_fixed_stack_node->ptr_fixed_stack
        = ptr_fixed_stack;
    ptr_fixed_stack_node->ptr_next_node
        = 0;
    
    return
        ptr_fixed_stack;
}

void
    __atomic_fixed_stack_cleanup
        (__atomic_fixed_stack* pFixedStack)
{
    pFixedStack->ptr_fixed_stack_allocator->deallocate
        (pFixedStack->ptr_fixed_stack_allocator,
            __atomic_fixed_stack_size
                (pFixedStack->fixed_stack_node_size,
                    pFixedStack->fixed_stack_node_count),
                        pFixedStack);
}