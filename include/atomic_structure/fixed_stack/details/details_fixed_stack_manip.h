#pragma once
#include <atomic_structure/fixed_stack/details/details_fixed_stack_type.h>

void
    __atomic_fixed_stack_push
        (__atomic_fixed_stack*, __atomic_fixed_stack_node*);

__atomic_fixed_stack_node*
    __atomic_fixed_stack_pop
        (__atomic_fixed_stack*);

__atomic_fixed_stack_node*
    __atomic_fixed_stack_pop_until_success
        (__atomic_fixed_stack*);
