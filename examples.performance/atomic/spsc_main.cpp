#include "spsc.hpp"
#include "spsc_boost.hpp"

#include <iostream>

int main() {
	std::cout << "[PERFORMANCE_TEST]\n\n";

	boost::lockfree::queue<std::uint64_t> spsc_boost(1024 * 1024 + 1);
	crisp_spsc								   spsc;

	std::uint64_t pfcnt_spsc_boost_push		   ,
				  pfcnt_spsc_boost_pop		   ,
				  pfcnt_spsc_boost_push_and_pop,

				  pfcnt_spsc_push		 ,
				  pfcnt_spsc_pop	     ,
				  pfcnt_spsc_push_and_pop;

	pf_spsc_initialize  (&spsc, 1024 * 1024 + 1);
	pf_spsc_push		(&spsc, 1024 * 1024,    pfcnt_spsc_push);
	pf_spsc_pop		    (&spsc, 1024 * 1024,    pfcnt_spsc_pop);
	pf_spsc_push_and_pop(&spsc, 1024 * 1024, 4, pfcnt_spsc_push_and_pop);

	pf_spsc_boost_push		  (spsc_boost, 1024 * 1024,    pfcnt_spsc_boost_push);
	pf_spsc_boost_pop		  (spsc_boost, 1024 * 1024,    pfcnt_spsc_boost_pop);
	pf_spsc_boost_push_and_pop(spsc_boost, 1024 * 1024, 4, pfcnt_spsc_boost_push_and_pop);

	std::cout << "[BOOST::LOCKFREE::QUEUE]\n"
			  << "[PUSH] : "		 << pfcnt_spsc_boost_push		  << std::endl
			  << "[POP] : "			 << pfcnt_spsc_boost_pop		  << std::endl
			  << "[PUSH_AND_POP] : " << pfcnt_spsc_boost_push_and_pop << std::endl;

	std::cout << "[CRISP::ATOMIC::SPSC]\n"
			  << "[PUSH] : "		 << pfcnt_spsc_push		    << std::endl
			  << "[POP] : "			 << pfcnt_spsc_pop			<< std::endl
			  << "[PUSH_AND_POP] : " << pfcnt_spsc_push_and_pop << std::endl;
}