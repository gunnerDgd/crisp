#pragma once
#include "type_list.h"

__list_controller*
	__list_default_controller();

void
	__list_push_front
		(__list_head*, __list_node*);

void
	__list_push_back
		(__list_head*, __list_node*);

void
	__list_push_at
		(__list_head*, __list_node*, __list_node*);

__list_node*
	__list_pop_front
		(__list_head*);

__list_node*
	__list_pop_back
		(__list_head*);

void
	__list_pop_at
		(__list_head*, __list_node*);