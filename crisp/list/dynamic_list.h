#include "type.h"
#include <crisp/allocator/type.h>

void
	crisp_dynamic_list_initialize
		(crisp_dynamic_list*, crisp_allocator*);

void
	crisp_dynamic_list_cleanup
		(crisp_dynamic_list*);

void
	crisp_dynamic_list_push_front
		(crisp_dynamic_list*, void*, crisp_u64);

void
	crisp_dynamic_list_push_back
		(crisp_dynamic_list*, void*, crisp_u64);

void
	crisp_dynamic_list_push_at
		(crisp_dynamic_list*, void*, crisp_u64, crisp_dynamic_list_iterator*);

void
	crisp_dynamic_list_pop_front
		(crisp_dynamic_list*);

void
	crisp_dynamic_list_pop_back
		(crisp_dynamic_list*);

void
	crisp_dynamic_list_pop_at
		(crisp_dynamic_list*, crisp_dynamic_list_iterator*);