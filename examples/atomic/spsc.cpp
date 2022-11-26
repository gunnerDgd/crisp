extern "C"
{
#include <crisp/atomic/spsc.h>
#include <crisp/queue/queue.h>

#include <crisp/allocator/standard_library.h>
}

#include <iostream>	
#include <thread>

void fn_producer(crisp_spsc* spsc) {
	for(crisp_u64 push_count  = 1		    ;
				  push_count <= 1000 * 1000 ;
				  push_count++)			    {
		crisp_u64*							 push_value = new crisp_u64(push_count);
		crisp_queue_push_until_success(spsc, push_value);
	}
}

void fn_consumer(crisp_spsc* spsc, crisp_u64& sum) {
	for(crisp_u64 pop_count = 0			 ;
				  pop_count < 1000 * 1000;
				  pop_count++)		     {
		crisp_u64 pop_value =  *(crisp_u64*)crisp_queue_pop_until_success(spsc);
		sum += pop_value;
	}
}

int main() {
	crisp_spsc		spsc;
	crisp_allocator alloc;

	std::thread*	producer,
			   *	consumer;

	crisp_u64		sum = 0;

	std::cout << "[EXAMPLE] crisp::atomic::spsc" << std::endl;

	crisp_allocator_standard_library(&alloc);
	crisp_spsc_initialize		    (&spsc, &alloc, 1000 * 1000 + 1);

	producer = new std::thread(fn_producer, &spsc);
	consumer = new std::thread(fn_consumer, &spsc, std::ref(sum));
	
	producer->join();
	consumer->join();

	std::cout << "[SUM] " << sum << std::endl;

	crisp_spsc_cleanup(&spsc);

}