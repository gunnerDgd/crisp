#include <crisp/list/list.h>
#include <crisp/list/list_iterate.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct node_struct {
	crisp_list_node node ;
	int				value;
}	node_struct;

void print_value(int* node) {
	printf("Node Value : %d\n", *node);
}

int main() {
	crisp_list list;
	crisp_list_initialize(&list);

	for(crisp_u64 i = 0;
				  i < 5;
				  i++) {
		node_struct* node = malloc(sizeof(node_struct));
					 node->value = i;

		crisp_list_push_front(&list, node);
	}

	crisp_list_iterator iterator;
	crisp_list_begin   (&list, &iterator);
	crisp_list_for_each(&iterator, &print_value);
}