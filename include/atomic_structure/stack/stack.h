#include <atomic_structure/stack/stack_type.h>

void
    atomic_stack_initialize
        (atomic_stack*);

void
    atomic_stack_node_initialize
        (atomic_stack_node*, void*);

void*
    atomic_stack_node_data
        (atomic_stack_node*);

void
    atomic_stack_push
        (atomic_stack*, atomic_stack_node*);

atomic_stack_node*
    atomic_stack_pop
        (atomic_stack*);

atomic_stack_node*
    atomic_stack_pop_until_success
        (atomic_stack*);