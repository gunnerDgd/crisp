extern "C"
{
#include <crisp/atomic/stack.h>
#include <crisp/stack/stack.h>
}

#include <iostream>
#include <atomic>
#include <thread>

struct node_struct {
	crisp_atomic_stack_node node;
	crisp_u64				value;
};

void fn_producer(crisp_stack* stack) {
	for(crisp_u64 push_count  = 1		    ;
				  push_count <= 1000 * 1000 ;
				  push_count++)			    {
		node_struct* push_value = new node_struct;
					 push_value->value = push_count;

		crisp_stack_push(stack, &push_value->node);
	}
}

void fn_consumer(crisp_stack* stack, std::atomic<crisp_u64>& sum) {
	for(crisp_u64 pop_count = 0			 ;
				  pop_count < 1000 * 1000;
				  pop_count++)		     {
		node_struct*  pop_value = (node_struct*)crisp_stack_pop(stack);
		sum.fetch_add(pop_value->value);
	}
}

int main() {
	crisp_stack			   stack      ;
	std::thread			  *producer[4],
						  *consumer[4]; // Execute on 4 - Core Environment
	std::atomic<crisp_u64> sum = 0;

	std::cout << "[EXAMPLE] crisp::atomic::stack" << std::endl;

	crisp_atomic_stack_initialize(&stack);

	for (auto&& producer_thread : producer)
		producer_thread = new std::thread(fn_producer, &stack);
	for (auto&& consumer_thread : consumer)
		consumer_thread = new std::thread(fn_consumer, &stack, std::ref(sum));
	
	for (auto&& producer_thread : producer)
		producer_thread->join();
	for (auto&& consumer_thread : consumer)
		consumer_thread->join();

	std::cout << "[SUM] " << sum << std::endl;
}