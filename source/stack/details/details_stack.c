#include <atomic_structure/stack/details/details_stack.h>
#include <assert.h>

#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
#include <stdatomic.h>
#elif  ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
#include <Windows.h>
#endif

void
    __atomic_stack_initialize
        (__atomic_stack* pStack)
{
    pStack->ptr_stack_node = 0;
}

void
    __atomic_stack_node_initialize
        (__atomic_stack_node* pStackNode, void* pStackNodeData)
{
    pStackNode->ptr_node_next = 0;
    pStackNode->ptr_node_data = pStackNodeData;
}

void*
    __atomic_stack_node_data
        (__atomic_stack_node* pStackNode)
{
    return
        pStackNode->ptr_node_data;
}

void
    __atomic_stack_push
        (__atomic_stack* pStack, __atomic_stack_node* pStackNode)
{
#ifdef ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_GNU
    do
    {
        pStackNode->ptr_node_next
            = pStack->ptr_stack_node;
    } while
        (!atomic_compare_exchange_weak
            (&pStack->ptr_stack_node,
                &pStackNode, pStackNode->ptr_node_next));
#elif ATOMIC_STRUCTURE_BUILD_ENVIRONMENT_MSVC
    do
    {
        pStackNode->ptr_node_next
            = pStack->ptr_stack_node;
    } while
        (InterlockedCompareExchange64
            (&pStack->ptr_stack_node,
                pStackNode, pStackNode->ptr_node_next)
                    != pStackNode->ptr_node_next);
#else
    static_assert("[FATAL] This Build Environment Does Not Support Atomic Operation.");
#endif
}

__atomic_stack_node*
    __atomic_stack_pop
        (__atomic_stack* pStack)
{
    __atomic_stack_node*
        ptr_stack_node;
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
#else
    static_assert("[FATAL] This Build Environment Does Not Support Atomic Operation.");
#endif

    return ptr_stack_node;
}

__atomic_stack_node*
    __atomic_stack_pop_until_success
        (__atomic_stack* pStack)
{
    __atomic_stack_node*
        ptr_stack_node;
    
    while
        (!(ptr_stack_node
                = __atomic_stack_pop(pStack)));
    return
        ptr_stack_node;
}