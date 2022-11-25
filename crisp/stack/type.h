#pragma once
#include <base/type_primitive.h>

typedef struct
	crisp_stack
		{ crisp_u64 opaque[2]; } crisp_stack;

typedef struct
	crisp_stack_node
		{ crisp_u64 opaque[4]; } crisp_stack_node;

typedef struct
	crisp_dynamic_stack
		{ crisp_u64 opaque[6]; } crisp_dynamic_stack;