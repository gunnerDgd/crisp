#include <list>
extern "C"
{
#include <base/type_primitive.h>
}

crisp_u64
	pf_stl_list_push_performance
		(std::list<crisp_u64>&, crisp_u64);

crisp_u64
	pf_stl_list_pop_performance
		(std::list<crisp_u64>&, crisp_u64);