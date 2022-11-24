#pragma once
#include "type_dynamic_list.h"

void
	__dynamic_list_head_initialize
		(__dynamic_list_head*, __allocator_entity*);

void
	__dynamic_list_head_cleanup
		(__dynamic_list_head*);

__dynamic_list_node*
	__dynamic_list_node_initialize
		(__dynamic_list_head*, crisp_u64);

void
	__dynamic_list_node_cleanup
		(__dynamic_list_node*);