#include <crisp/turbo/turbo_list.h>
#include <crisp/list/list.h>
#include <crisp/list/list_iterate.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct node_type {
	crisp_turbo_list_node node ;
	crisp_u64			  value;
}	node_type;

void print_value(int* pValue) {
	printf("[Value] : %d\n", *pValue);
}

int main() {
	crisp_turbo_list			 list      ;
	crisp_list_iterator			 begin, end;
	crisp_turbo_list_initialize(&list);

	for(crisp_u64 push_count = 0;
						   push_count < 5;
						   push_count++)	   {
		node_type* push_value		 = malloc(sizeof(node_type));
				   push_value->value = push_count;
		crisp_list_push_front(&list, push_value);
	}

	crisp_list_begin   (&list, &begin);
	crisp_list_end     (&list, &end);
	crisp_list_for_each(&begin, &end, &print_value);
}