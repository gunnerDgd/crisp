#include <atomic_structure/stack/details/details_stack_init.h>
#include <atomic_structure/stack/details/details_stack_manip.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
#include <stdatomic.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
#include <Windows.h>
#endif

void
    __atomic_stack_push
        (__atomic_stack* pStack, void* pStackNode)
{
    __atomic_stack_node*
        ptr_stack_node
            = __atomic_stack_node_initialize
                    (pStack, pStackNode);
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
    do
    {
        ptr_stack_node->ptr_node_next
            = pStack->ptr_stack_node;
    } while
        (!atomic_compare_exchange_weak
            (&pStack->ptr_stack_node,
                &ptr_stack_node->ptr_node_next, ptr_stack_node));
#elif ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
    do
    {
        ptr_stack_node->ptr_node_next
            = pStack->ptr_stack_node;
    } while
        (InterlockedCompareExchange64
            (&pStack->ptr_stack_node,
                ptr_stack_node, ptr_stack_node->ptr_node_next)
                    != ptr_stack_node->ptr_node_next);
#endif
}

void*
    __atomic_stack_pop
        (__atomic_stack* pStack)
{
    __atomic_stack_node*
        ptr_stack_node;
    void*
        ptr_stack_node_data;
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
    do
    {
        ptr_stack_node
            = pStack->ptr_stack_node;
        
        if(!ptr_stack_node)
            return 0;
    } while
        (!atomic_compare_exchange_weak
            (&pStack->ptr_stack_node,
                &ptr_stack_node, ptr_stack_node->ptr_node_next));
#elif ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
    do
    {
        ptr_stack_node
            = pStack->ptr_stack_node;
        
        if(!ptr_stack_node)
            return 0;
    } while
        (InterlockedCompareExchange64
            (&pStack->ptr_stack_node,
                ptr_stack_node->ptr_node_next, ptr_stack_node)
                    != ptr_stack_node);
#endif
    ptr_stack_node_data
        = ptr_stack_node->ptr_node_data;
    __atomic_stack_node_cleanup
        (pStack, ptr_stack_node);

    return 
        ptr_stack_node_data;
}

void*
    __atomic_stack_pop_until_success
        (__atomic_stack* pStack)
{
    void*
        ptr_stack_node_data;
    
    while
        (!(ptr_stack_node_data = __atomic_stack_pop(pStack)));
    return
        ptr_stack_node_data;
}