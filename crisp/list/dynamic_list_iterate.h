#include "type.h"

void
	crisp_dynamic_list_begin
		(crisp_dynamic_list*, crisp_dynamic_list_iterator*);

void
	crisp_dynamic_list_end
		(crisp_dynamic_list*, crisp_dynamic_list_iterator*);

void
	crisp_dynamic_list_iterator_next
		(crisp_dynamic_list_iterator*);

void
	crisp_dynamic_list_iterator_prev
		(crisp_dynamic_list_iterator*);

void*
	crisp_dynamic_list_iterator_value
		(crisp_dynamic_list_iterator*);

void
	crisp_dynamic_list_for_each
		(crisp_dynamic_list_iterator*, void(*)(void*));