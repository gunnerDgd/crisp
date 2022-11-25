extern "C"
{
#include <crisp/list/list.h>
#include <crisp/list/list_iterate.h>

#include <crisp/allocator/standard_library.h>

typedef struct node_struct {
	crisp_list_node node ;
	crisp_u64		value;
}	node_struct;
}

void
	pf_list_initialize
		(crisp_list*);

crisp_u64
	pf_list_push_performance
		(crisp_list*, crisp_u64);

crisp_u64
	pf_list_pop_performance
		(crisp_list*, crisp_u64);

void
	pf_list_cleanup
		(crisp_list*);