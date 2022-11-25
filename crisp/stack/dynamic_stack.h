#pragma once
#include "type.h"
#include <crisp/allocator/type.h>

void
	crisp_dynamic_stack_initialize
		(crisp_dynamic_stack*, crisp_allocator*);

void
	crisp_dynamic_stack_cleanup
		(crisp_dynamic_stack*);

void
	crisp_dynamic_stack_push
		(crisp_dynamic_stack*, void*, crisp_u64);

void
	crisp_dynamic_stack_push_bounded
		(crisp_dynamic_stack*, void**, crisp_u64*, crisp_u64);

void
	crisp_dynamic_stack_pop
		(crisp_dynamic_stack*);

void
	crisp_dynamic_stack_pop_bounded
		(crisp_dynamic_stack*, crisp_u64);

void*
	crisp_dynamic_stack_peek
		(crisp_dynamic_stack*);