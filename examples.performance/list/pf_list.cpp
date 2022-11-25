#include "pf_list.h"
#include <intrin.h>

void
	pf_list_initialize
		(crisp_dynamic_list* pList) {
	crisp_allocator					  alloc;
	crisp_allocator_standard_library(&alloc);
	crisp_dynamic_list_initialize	(pList, &alloc);
}

crisp_u64
	pf_list_push_performance
		(crisp_dynamic_list* pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	pf_begin = __rdtsc();
	for(crisp_u64 push_count = 0;
				  push_count < pCount;
				  push_count++)
		crisp_dynamic_list_push_back(pList, &push_count, sizeof(crisp_u64));
	pf_end = __rdtsc();

	return pf_end - pf_begin;
}

crisp_u64
	pf_list_pop_performance
		(crisp_dynamic_list* pList, crisp_u64 pCount) {
	crisp_u64 pf_begin, pf_end;

	crisp_dynamic_list_iterator iterator;
	crisp_dynamic_list_begin	(pList, &iterator);

	pf_begin = __rdtsc();
	for(crisp_u64 pop_count = 0		;
				  pop_count < pCount;
				  pop_count++)		 {
		int*   pop_value = (int*)crisp_dynamic_list_iterator_value(&iterator);
		crisp_dynamic_list_pop_at(pList, &iterator);
	}
	
	pf_end = __rdtsc();
	return pf_end - pf_begin;
}

void
	pf_list_cleanup
		(crisp_dynamic_list* pList) {
	crisp_dynamic_list_cleanup(pList);
}