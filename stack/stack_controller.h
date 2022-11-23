#pragma once
#include "type_stack.h"

__stack_controller*
	__stack_default_controller();

void
	__stack_push
		(__stack_head*, __stack_node*);

void
	__stack_push_bounded
		(__stack_head*, __stack_node**, crisp_u64);

__stack_node*
	__stack_pop
		(__stack_head*);

void
	__stack_pop_bounded
		(__stack_head*, __stack_node**, crisp_u64);