#include "spsc.hpp"

void
	pf_spsc_initialize
		(crisp_spsc* spsc, crisp_u64 count) {
	crisp_allocator alloc;
	crisp_allocator_standard_library(&alloc);
	crisp_spsc_initialize(spsc, &alloc, count);
}

void
	pf_spsc_cleanup
		(crisp_spsc* spsc) {
	crisp_spsc_cleanup(spsc);
}

void
	pf_spsc_push
		(crisp_spsc* spsc, crisp_u64 count, crisp_u64& pf_count) {
	auto pf_begin = std::chrono::high_resolution_clock::now();
	for(std::uint64_t push_count = 1	 ;
					  push_count <= count;
					  push_count++)
		crisp_queue_push(spsc, (void*)push_count);

	auto pf_end   = std::chrono::high_resolution_clock::now();
	pf_count = (pf_end - pf_begin).count();
}

void
	pf_spsc_pop
		(crisp_spsc* spsc, crisp_u64 count, crisp_u64& pf_count) {
	auto pf_begin = std::chrono::high_resolution_clock::now();
	for(std::uint64_t push_count = 1	 ;
					  push_count <= count;
					  push_count++)
		crisp_queue_pop(spsc);

	auto pf_end = std::chrono::high_resolution_clock::now();
	pf_count	= (pf_end - pf_begin).count();
}

void
	pf_spsc_push_and_pop
		(crisp_spsc* spsc, crisp_u64 count, crisp_u64 thread_count, crisp_u64& pf_count) {
	boost::thread_group producer, consumer;
	std::uint64_t		dummy;

	auto pf_begin = std::chrono::high_resolution_clock::now();
	for(std::uint64_t producer_count = 0			;
					  producer_count < thread_count ;
					  producer_count++)
		producer.create_thread
			(boost::bind(pf_spsc_push, spsc, count, std::ref(dummy)));

	for(std::uint64_t consumer_count = 0			;
					  consumer_count < thread_count ;
					  consumer_count++)
		consumer.create_thread
			(boost::bind(pf_spsc_pop, spsc, count, std::ref(dummy)));

	producer.join_all();
	consumer.join_all();
	auto pf_end   = std::chrono::high_resolution_clock::now();

	pf_count = (pf_end - pf_begin).count();
}