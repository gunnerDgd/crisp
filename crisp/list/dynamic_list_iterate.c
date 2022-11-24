#include "dynamic_list_iterate.h"

#include <list/list_iterate.h>

#include <list/dynamic_list.h>
#include <list/dynamic_list_controller.h>

void
	crisp_dynamic_list_begin
		(crisp_dynamic_list*		  pList,
		 crisp_dynamic_list_iterator* pIterator) {
	__list_iterator*     iterator = pIterator;
	__dynamic_list_head* head	  = pList;

	iterator->node = head->head.frontmost;
}

void
	crisp_dynamic_list_end
		(crisp_dynamic_list*		  pList,
		 crisp_dynamic_list_iterator* pIterator) {
	__list_iterator*     iterator = pIterator;
	__dynamic_list_head* head	  = pList;

	iterator->node = head->head.backmost;
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
		(crisp_dynamic_list_iterator* pIterator, 
		 void					   (* pFunc)(void*)) {
	__list_iterator_for_each(pIterator, pFunc);
}