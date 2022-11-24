#pragma once
#include <base/type_primitive.h>

typedef struct
	crisp_list_iterator
		{ crisp_u8 opaque[16]; } crisp_list_iterator;

typedef struct
	crisp_dynamic_list_iterator
		{ crisp_u8 opaque[16]; } crisp_dynamic_list_iterator;

typedef struct
	crisp_list_node
		{ crisp_u8 opaque[32]; } crisp_list_node;

typedef struct
	crisp_list
		{ crisp_u8 opaque[32]; } crisp_list;

typedef struct
	crisp_dynamic_list
		{ crisp_u8 opaque[32]; } crisp_dynamic_list;