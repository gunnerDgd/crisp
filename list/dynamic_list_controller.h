#pragma once
#include "type_dynamic_list.h"

__dynamic_list_controller*
	__dynamic_list_default_controller();

void
	__dynamic_list_push_front
		(__dynamic_list_head*, void*, crisp_u64);

void
	__dynamic_list_push_back
		(__dynamic_list_head*, void*, crisp_u64);

void
	__dynamic_list_push_at
		(__dynamic_list_head*, __dynamic_list_node*, void*, crisp_u64);

void
	__dynamic_list_pop_front
		(__dynamic_list_head*);

void
	__dynamic_list_pop_back
		(__dynamic_list_head*);

void
	__dynamic_list_pop_at
		(__dynamic_list_head*, __dynamic_list_node*);