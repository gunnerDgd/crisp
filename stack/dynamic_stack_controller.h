#pragma once
#include "dynamic_stack.h"

__dynamic_stack_controller*
	__dynamic_stack_default_controller();

void
	__dynamic_stack_push
		(__dynamic_stack_head*, void*, crisp_u64);

void
	__dynamic_stack_push_bounded
		(__dynamic_stack_head*, void**, crisp_u64*, crisp_u64);

void
	__dynamic_stack_pop
		(__dynamic_stack_head*);

void
	__dynamic_stack_pop_bounded
		(__dynamic_stack_head*, crisp_u64);

void*
	__dynamic_stack_peek
		(__dynamic_stack_head*);