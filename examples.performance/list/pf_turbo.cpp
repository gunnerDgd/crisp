#include "pf_turbo.h"
#include <intrin.h>

void
	pf_turbo_list_initialize
		(crisp_turbo_list* pHead) {
	crisp_turbo_list_initialize(pHead);
}

crisp_u64
	pf_turbo_list_push_performance
		(crisp_turbo_list* pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	pf_begin = __rdtsc();
	for(crisp_u64 push_count = 0;
				  push_count < pCount;
				  push_count++) {
		auto push_value		   = new turbo_node_struct;
			 push_value->value = push_count;
		
		crisp_list_push_back(pList, (crisp_turbo_list_node*)push_value);
	}
	pf_end = __rdtsc();

	return pf_end - pf_begin;
}

crisp_u64
	pf_turbo_list_pop_performance
		(crisp_turbo_list* pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	pf_begin = __rdtsc();
	for(crisp_u64 pop_count = 0		;
				  pop_count < pCount;
				  pop_count++)		{
		auto   pop_value = (turbo_node_struct*)crisp_list_pop_back(pList);
		delete pop_value;
	}
		
	pf_end = __rdtsc();
	return pf_end - pf_begin;
}

void
	pf_turbo_list_cleanup
		(crisp_turbo_list*) {}