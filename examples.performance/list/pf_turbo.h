extern "C"
{
#include <crisp/turbo/turbo_list.h>
#include <crisp/list/list.h>

#include <crisp/allocator/standard_library.h>
}

typedef struct turbo_node_struct {
	crisp_turbo_list_node node ;
	crisp_u64			  value;
}	turbo_node_struct;

void
	pf_turbo_list_initialize
		(crisp_turbo_list*);

crisp_u64
	pf_turbo_list_push_performance
		(crisp_turbo_list*, crisp_u64);

crisp_u64
	pf_turbo_list_pop_performance
		(crisp_turbo_list*, crisp_u64);

void
	pf_turbo_list_cleanup
		(crisp_turbo_list*);