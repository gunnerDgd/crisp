#include <atomic_structure/fixed_stack/fixed_stack_init.h>
#include <atomic_structure/fixed_stack/details/details_fixed_stack_init.h>

atomic_fixed_stack
    atomic_fixed_stack_initialize
        (atomic_allocator* pFixedStackAllocator,
         size_t            pFixedStackNodeCount,
         size_t            pFixedStackNodeSize)
{
    atomic_fixed_stack
        ptr_fixed_stack
            = { .handle
                    = __atomic_fixed_stack_initialize
                            (pFixedStackAllocator, 
                                pFixedStackNodeCount, pFixedStackNodeSize) };

    return
        ptr_fixed_stack;
}

void
    atomic_fixed_stack_cleanup
        (atomic_fixed_stack pFixedStack)
{
    __atomic_fixed_stack_cleanup
        (pFixedStack.handle);
}