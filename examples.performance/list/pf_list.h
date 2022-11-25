extern "C"
{
#include <crisp/list/dynamic_list.h>
#include <crisp/list/dynamic_list_iterate.h>

#include <crisp/allocator/standard_library.h>
}

void
	pf_list_initialize
		(crisp_dynamic_list*);

crisp_u64
	pf_list_push_performance
		(crisp_dynamic_list*, crisp_u64);

crisp_u64
	pf_list_pop_performance
		(crisp_dynamic_list*, crisp_u64);

void
	pf_list_cleanup
		(crisp_dynamic_list*);