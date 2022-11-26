#include <boost/lockfree/queue.hpp>
#include <boost/thread.hpp>
#include <chrono>

void
	pf_spsc_boost_push
		(boost::lockfree::queue<std::uint64_t>&, 
		 std::uint64_t,
		 std::uint64_t&);

void
	pf_spsc_boost_pop
		(boost::lockfree::queue<std::uint64_t>&,
		 std::uint64_t,
		 std::uint64_t&);

void
	pf_spsc_boost_push_and_pop
		(boost::lockfree::queue<std::uint64_t>&,
		 std::uint64_t,
		 std::uint64_t,
		 std::uint64_t&);