#include <crisp/atomic/spsc.h>
#include <crisp/queue/queue.h>

#include <crisp/allocator/standard_library.h>

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

int main() {
	crisp_spsc		spsc;
	crisp_allocator alloc;

	crisp_allocator_standard_library(&alloc);
	crisp_spsc_initialize		    (&spsc, &alloc, 1025);

	for(crisp_u64 push_count = 0   ;
				  push_count < 1024;
				  push_count++)	   {
		crisp_u64* push_value = malloc(8);
				 * push_value = push_count;
		crisp_queue_push(&spsc, push_value);
	}

	for(crisp_u64 pop_count = 0   ;
				  pop_count < 1024;
				  pop_count++)	   {
		crisp_u64* pop_value = crisp_queue_pop(&spsc);
		printf("[POP Value] : %d\n", *pop_value);
	}

	crisp_spsc_cleanup(&spsc);

}