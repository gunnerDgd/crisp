#include <crisp/queue/queue.h>
#include <crisp/allocator/standard_library.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	crisp_queue     queue;
	crisp_allocator alloc;

	crisp_allocator_standard_library(&alloc);
	crisp_queue_initialize			(&queue, &alloc, 101);

	for(crisp_u64 push_count = 0   ;
				  push_count < 100 ;
				  push_count++)	   {
		crisp_u64* push_value = malloc(sizeof(crisp_u64));
				 * push_value = push_count;

		crisp_queue_push(&queue, push_value);
	}

	for(crisp_u64 push_count = 0   ;
				  push_count < 100 ;
				  push_count++)	   {
		int* pop_value = crisp_queue_pop(&queue);
		printf("Pop Value : %d\n", *pop_value);

		free(pop_value);
	}
}