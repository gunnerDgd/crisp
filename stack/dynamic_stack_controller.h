#pragma once
#include "dynamic_stack.h"

void
	__dynamic_stack_push
		(__dynamic_stack_head*, void*, crisp_u64);

void
	__dynamic_stack_push_bounded
		(__dynamic_stack_head*, void**, crisp_u64*, crisp_u64);

__dynamic_stack_node*
	__dynamic_stack_pop
		(__dynamic_stack_head*);

void
	__dynamic_stack_pop_bounded
		(__dynamic_stack_head*, __dynamic_stack_node**, crisp_u64);