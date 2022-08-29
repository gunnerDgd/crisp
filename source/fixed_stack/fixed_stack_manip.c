#include <atomic_structure/fixed_stack/fixed_stack_manip.h>
#include <atomic_structure/fixed_stack/details/details_fixed_stack_manip.h>

void*
    atomic_fixed_stack_pop
        (atomic_fixed_stack pFixedStack)
{
    __atomic_fixed_stack_node*
        ptr_fixed_stack_node
            = __atomic_fixed_stack_pop(pFixedStack.handle);
    
    return
        __atomic_fixed_stack_node_data
            (ptr_fixed_stack_node);
}

void*
    atomic_fixed_stack_pop_until_success
        (atomic_fixed_stack pFixedStack)
{
    __atomic_fixed_stack_node*
        ptr_fixed_stack_node
            = __atomic_fixed_stack_pop_until_success(pFixedStack.handle);
    
    return
        __atomic_fixed_stack_node_data
            (ptr_fixed_stack_node);
}

void
    atomic_fixed_stack_push
        (atomic_fixed_stack pFixedStack, void* pFixedStackData)
{
    __atomic_fixed_stack_node*
        ptr_fixed_stack_node
            = (uint8_t*)pFixedStackData
                    - sizeof(__atomic_fixed_stack_node);
    
    if(ptr_fixed_stack_node->ptr_fixed_stack
            != pFixedStack.handle)
                return;
    
    __atomic_fixed_stack_push
        (pFixedStack.handle, ptr_fixed_stack_node);
}