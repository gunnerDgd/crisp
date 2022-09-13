#pragma once
#include <atomic_structure/stack/details/details_stack_type.h>

void
    __atomic_stack_push
        (__atomic_stack*, void*);

void*
    __atomic_stack_pop
        (__atomic_stack*);

void*
    __atomic_stack_pop_until_success
        (__atomic_stack*);