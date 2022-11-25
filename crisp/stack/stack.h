#pragma once
#include "type.h"

void
	crisp_stack_initialize
		(crisp_stack*);

void
	crisp_stack_push
		(crisp_stack*, crisp_stack_node*);

void
	crisp_stack_push_bounded
		(crisp_stack*, crisp_stack_node**, crisp_u64);

crisp_stack_node*
	crisp_stack_pop
		(crisp_stack*);

void
	crisp_stack_pop_bounded
		(crisp_stack*, crisp_stack_node**, crisp_u64);