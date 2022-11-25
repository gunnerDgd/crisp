#include "dynamic_list_iterate.h"

#include <list/list.h>
#include <list/list_iterate.h>

#include <list/dynamic_list.h>
#include <list/dynamic_list_controller.h>

void
	crisp_dynamic_list_begin
		(crisp_dynamic_list*		  pList,
		 crisp_dynamic_list_iterator* pIterator) {
	__list_iterator_initialize_begin(pList, pIterator);
}

void
	crisp_dynamic_list_end
		(crisp_dynamic_list*		  pList,
		 crisp_dynamic_list_iterator* pIterator) {
	__list_iterator_initialize_end(pList, pIterator);
}

void
	crisp_dynamic_list_iterator_next
		(crisp_dynamic_list_iterator* pIterator) {
	__list_iterator_next(pIterator);
}

void
	crisp_dynamic_list_iterator_prev
		(crisp_dynamic_list_iterator* pIterator) {
	__list_iterator_prev(pIterator);
}

void*
	crisp_dynamic_list_iterator_value
		(crisp_dynamic_list_iterator* pIterator) {
	return
		__list_iterator_value(pIterator);
}

void
	crisp_dynamic_list_for_each
		(crisp_dynamic_list_iterator* pBegin,
		 crisp_dynamic_list_iterator* pEnd  ,
		 void					   (* pFunc)(void*)) {
	__list_iterator_for_each(pBegin, pEnd, pFunc);
}