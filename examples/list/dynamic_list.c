#include <crisp/list/dynamic_list.h>
#include <crisp/list/dynamic_list_iterate.h>

#include <crisp/allocator/standard_library.h>

#include <stdio.h>

void print_value(int* node) {
	printf("Node Value : %d\n", *node);
}

int main() {
	crisp_dynamic_list list;
	crisp_allocator	   alloc;

	crisp_allocator_standard_library(&alloc);
	crisp_dynamic_list_initialize   (&list, &alloc);

	for(crisp_u64 i = 0;
				  i < 5;
				  i++)
		crisp_dynamic_list_push_front(&list, &i, sizeof(crisp_u64));

	crisp_dynamic_list_iterator iterator;
	crisp_dynamic_list_begin   (&list, &iterator);
	crisp_dynamic_list_for_each(&iterator, &print_value);
}