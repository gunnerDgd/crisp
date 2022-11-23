#pragma once
#include "type_dynamic_stack.h"

void
	__dynamic_stack_head_initialize
		(__dynamic_stack_head*, __allocator_entity*);

void
	__dynamic_stack_head_cleanup
		(__dynamic_stack_head*);

__dynamic_stack_node*
	__dynamic_stack_node_initialize
		(__dynamic_stack_head*, void*, crisp_u64);

void
	__dynamic_stack_node_cleanup
		(__dynamic_stack_node*);