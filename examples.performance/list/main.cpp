#include "pf_list.h"
#include "pf_stl_list.h"

#include <iostream>

int main() {
	std::list<crisp_u64> stl_list;
	crisp_turbo_list	     list;

	auto pf_list_push = pf_stl_list_push_performance(stl_list, 1024 * 1024);
	auto pf_list_pop  = pf_stl_list_pop_performance (stl_list, 1024 * 1024);
	std::cout << "[PFTEST] std::list<T>\n"
			  << "[Push] : " <<  pf_list_push << "clock\n"
			  << "[Pop] : "  <<  pf_list_pop  << "clock\n";

	pf_list_initialize(&list);
	pf_list_push = pf_list_push_performance(&list, 1024 * 1024); std::cout << "Push Completed\n";
	pf_list_pop  = pf_list_pop_performance (&list, 1024 * 1024);

	std::cout << "[PFTEST] crisp::dynamic_list\n"
			  << "[Push] : " << pf_list_push << "clock\n"
			  << "[Pop] : "  << pf_list_pop  << "clock\n\n";
	pf_list_cleanup	  (&list);
}