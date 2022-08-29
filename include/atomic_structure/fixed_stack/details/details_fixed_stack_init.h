#include <atomic_structure/fixed_stack/details/details_fixed_stack_type.h>

__atomic_fixed_stack*
    __atomic_fixed_stack_initialize
        (atomic_allocator*, size_t, size_t);

void
    __atomic_fixed_stack_cleanup
        (__atomic_fixed_stack*);