#pragma once
#include "type.h"

void
	crisp_list_begin
		(crisp_list*, crisp_list_iterator*);

void
	crisp_list_end
		(crisp_list*, crisp_list_iterator*);

void
	crisp_list_iterator_next
		(crisp_list_iterator*);

void
	crisp_list_iterator_prev
		(crisp_list_iterator*);

void*
	crisp_list_iterator_value
		(crisp_list_iterator*);

void
	crisp_list_for_each
		(crisp_list_iterator*, crisp_list_iterator*, void(*)(void*));