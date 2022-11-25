extern "C"
{
#include <crisp/list/list.h>
#include <crisp/list/list_iterate.h>

#include <crisp/list/turbo_list.h>

#include <crisp/allocator/standard_library.h>
}

struct node_struct {
	crisp_turbo_list_node node ;
	crisp_u64			  value;
};

void
	pf_list_initialize
		(crisp_turbo_list*);

crisp_u64
	pf_list_push_performance
		(crisp_turbo_list*, crisp_u64);

crisp_u64
	pf_list_pop_performance
		(crisp_turbo_list*, crisp_u64);

void
	pf_list_cleanup
		(crisp_turbo_list*);