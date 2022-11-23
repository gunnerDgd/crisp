#pragma once
#include "type_stack.h"

void
	__stack_head_initialize
		(__stack_head*);

void
	__stack_node_initialize
		(__stack_node*, __stack_head*, void*);