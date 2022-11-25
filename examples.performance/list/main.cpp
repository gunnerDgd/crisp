#include "pf_list.h"
#include "pf_turbo.h"
#include "pf_stl_list.h"

#include <iostream>

int main() {
	std::list<crisp_u64> stl_list;
	crisp_list			     list;
	crisp_turbo_list   turbo_list;

	crisp_u64 pf_stl_list_push,
			  pf_stl_list_pop ,

			  pf_list_push,
			  pf_list_pop ,

			  pf_turbo_list_push,
			  pf_turbo_list_pop ;

	pf_stl_list_push = pf_stl_list_push_performance(stl_list, 1024);
	pf_stl_list_pop  = pf_stl_list_pop_performance (stl_list, 1024);

	pf_list_initialize(&list);
	pf_list_push = pf_list_push_performance(&list, 1024);
	pf_list_pop  = pf_list_pop_performance (&list, 1024);

	pf_turbo_list_initialize(&turbo_list);
	pf_turbo_list_push = pf_turbo_list_push_performance(&list, 1024);
	pf_turbo_list_pop  = pf_turbo_list_pop_performance (&list, 1024);


	std::cout << "[PFTEST] std::list<T>\n"
			  << "[Push] : " <<  pf_stl_list_push << "clock\n"
			  << "[Pop] : "  <<  pf_stl_list_pop  << "clock\n";

	std::cout << "[PFTEST] crisp::list\n"
			  << "[Push] : " << pf_list_push << "clock\n"
			  << "[Pop] : "  << pf_list_pop  << "clock\n\n";

	std::cout << "[PFTEST] crisp::turbo_list\n"
			  << "[Push] : " << pf_turbo_list_push << "clock\n"
			  << "[Pop] : "  << pf_turbo_list_pop  << "clock\n\n";
}