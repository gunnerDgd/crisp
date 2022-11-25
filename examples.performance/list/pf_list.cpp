#include "pf_list.h"
#include <intrin.h>
#include <iostream>

void
	pf_list_initialize
		(crisp_list* pList) {
	crisp_list_initialize(pList);
}

crisp_u64
	pf_list_push_performance
		(crisp_list* pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	pf_begin = __rdtsc();
	for(crisp_u64 push_count = 0;
				  push_count < pCount;
				  push_count++) {
		auto push_value		   = new node_struct;
			 push_value->value = push_count;
		
		crisp_list_push_back(pList, (crisp_list_node*)push_value);
	}
	pf_end = __rdtsc();

	return pf_end - pf_begin;
}

crisp_u64
	pf_list_pop_performance
		(crisp_list* pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	pf_begin = __rdtsc();
	for(crisp_u64 pop_count = 0		;
				  pop_count < pCount;
				  pop_count++)		{
		auto   pop_value = (node_struct*)crisp_list_pop_back(pList);
		delete pop_value;
	}
		
	pf_end = __rdtsc();
	return pf_end - pf_begin;
}

void
	pf_list_cleanup
		(crisp_list* pList) {
}