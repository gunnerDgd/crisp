#pragma once
#include "type_stack.h"

__stack_controller*
	__atomic_stack_controller();

void
	__atomic_stack_push
		(__atomic_stack_head*, __atomic_stack_node*);

void
	__atomic_stack_push_bounded
		(__atomic_stack_head*, __atomic_stack_node**, crisp_u64);

__atomic_stack_node*
	__atomic_stack_pop
		(__atomic_stack_head*);

void
	__atomic_stack_pop_bounded
		(__atomic_stack_head*, __atomic_stack_node**, crisp_u64);