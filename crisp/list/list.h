#pragma once
#include <crisp/list/type.h>

void
	crisp_list_initialize
		(crisp_list*);

void
	crisp_list_push_front
		(crisp_list*, crisp_list_node*);

void
	crisp_list_push_back
		(crisp_list*, crisp_list_node*);

void
	crisp_list_push_at
		(crisp_list*, crisp_list_node*, crisp_list_node*);

crisp_list_node*
	crisp_list_pop_front
		(crisp_list*);

crisp_list_node*
	crisp_list_pop_back
		(crisp_list*);

void
	crisp_list_pop_at
		(crisp_list*, crisp_list_node*);