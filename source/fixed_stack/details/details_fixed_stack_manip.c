#include <atomic_structure/fixed_stack/details/details_fixed_stack_manip.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
#include <Windows.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_LINUX
#include <stdatomic.h>
#endif

void
    __atomic_fixed_stack_push
        (__atomic_fixed_stack*      pFixedStack,
         __atomic_fixed_stack_node* pFixedStackNode)
{
    do
    {
        pFixedStackNode->ptr_next_node
            = pFixedStack->ptr_fixed_stack_node;
    }
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    while
        (InterlockedCompareExchange64
            (&pFixedStack->ptr_fixed_stack_node,
                pFixedStackNode, pFixedStackNode->ptr_next_node)
                    != pFixedStackNode->ptr_next_node);
#endif
}

__atomic_fixed_stack_node*
    __atomic_fixed_stack_pop
        (__atomic_fixed_stack* pFixedStack)
{
    __atomic_fixed_stack_node*
        ptr_fixed_stack_node;
    
    do
    {
        ptr_fixed_stack_node
            = pFixedStack->ptr_fixed_stack_node;
        
        if(!ptr_fixed_stack_node)
            return
                ptr_fixed_stack_node;
    }
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_WINDOWS
    while
        (InterlockedCompareExchange64
            (&pFixedStack->ptr_fixed_stack_node,
                ptr_fixed_stack_node->ptr_next_node,
                    ptr_fixed_stack_node) != ptr_fixed_stack_node);
#endif

    return
        ptr_fixed_stack_node;
}

__atomic_fixed_stack_node*
    __atomic_fixed_stack_pop_until_success
        (__atomic_fixed_stack* pFixedStack)
{
    __atomic_fixed_stack_node*
        ptr_fixed_stack_node;
    
    while
        (!(ptr_fixed_stack_node
            = __atomic_fixed_stack_pop(pFixedStack)));
    
    return
        ptr_fixed_stack_node;
}
