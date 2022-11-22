#pragma once
#include "type_list.h"

#include "list_iterate.h"
#include "list_controller.h"

void
	__list_head_initialize
		(__list_head*);

void
	__list_node_initialize
		(__list_node*, __list_head*, __list_node*, __list_node*, void*);

void
	__list_iterator_initialize_begin
		(__list_head*, __list_iterator*);

void
	__list_iterator_initialize_end
		(__list_head*, __list_iterator*);