#include "pf_stl_list.h"
#include <intrin.h>

crisp_u64
	pf_stl_list_push_performance
		(std::list<crisp_u64>& pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	pf_begin = __rdtsc();
	for(crisp_u64 push_count = 0;
				  push_count < pCount;
				  push_count++)
		pList.push_back(push_count);
	pf_end = __rdtsc();

	return pf_end - pf_begin;
}

crisp_u64
	pf_stl_list_pop_performance
		(std::list<crisp_u64>& pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	pf_begin = __rdtsc();
	for(crisp_u64 pop_count = 0		;
				  pop_count < pCount;
				  pop_count++)
		pList.pop_back();
	
	pf_end = __rdtsc();
	return pf_end - pf_begin;
}