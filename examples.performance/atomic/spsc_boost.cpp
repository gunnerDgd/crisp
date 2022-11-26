#include "spsc_boost.hpp"

void
	pf_spsc_boost_push
		(boost::lockfree::queue<std::uint64_t>& spsc ,
		 std::uint64_t							count,
		 std::uint64_t&							pf_count) {
	auto pf_begin = std::chrono::high_resolution_clock::now();
	for(std::uint64_t push_count = 1	 ;
					  push_count <= count;
					  push_count++)
		spsc.push(push_count);
	auto pf_end   = std::chrono::high_resolution_clock::now();
	pf_count = (pf_end - pf_begin).count();
}

void
	pf_spsc_boost_pop
		(boost::lockfree::queue<std::uint64_t>& spsc    ,
		 std::uint64_t							count   ,
		 std::uint64_t&							pf_count) {
	auto		  pf_begin = std::chrono::high_resolution_clock::now();
	std::uint64_t dummy;
	for(std::uint64_t push_count = 1	 ;
					  push_count <= count;
					  push_count++)
		spsc.pop(dummy);
	auto pf_end   = std::chrono::high_resolution_clock::now();
	pf_count = (pf_end - pf_begin).count();
}

void
	pf_spsc_boost_push_and_pop
		(boost::lockfree::queue<std::uint64_t>& spsc		,
		 std::uint64_t							count       ,
		 std::uint64_t							thread_count,
		 std::uint64_t&							pf_count)   {
	boost::thread_group producer, consumer;
	std::uint64_t		dummy;

	auto pf_begin = std::chrono::high_resolution_clock::now();
	for(std::uint64_t producer_count = 0			;
					  producer_count < thread_count ;
					  producer_count++)
		producer.create_thread
			(boost::bind(pf_spsc_boost_push, std::ref(spsc), count, std::ref(dummy)));

	for(std::uint64_t consumer_count = 0			;
					  consumer_count < thread_count ;
					  consumer_count++)
		consumer.create_thread
			(boost::bind(pf_spsc_boost_pop, std::ref(spsc), count, std::ref(dummy)));

	producer.join_all();
	consumer.join_all();
	auto pf_end   = std::chrono::high_resolution_clock::now();

	pf_count = (pf_end - pf_begin).count();
}