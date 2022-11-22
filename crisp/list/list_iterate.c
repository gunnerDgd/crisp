#include "list_iterate.h"
#include <list/list.h>

void
	crisp_list_begin
		(crisp_list* pList, crisp_list_iterator* pIterator) {
	__list_iterator_initialize_begin
		(pList, pIterator);
}

void
	crisp_list_end
		(crisp_list* pList, crisp_list_iterator* pIterator) {
	__list_iterator_initialize_end
		(pList, pIterator);
}

void
	crisp_list_iterator_next
		(crisp_list_iterator* pIterator) {
	__list_iterator_next(pIterator);
}

void
	crisp_list_iterator_prev
		(crisp_list_iterator* pIterator) {
	__list_iterator_prev(pIterator);
}

void*
	crisp_list_iterator_value
		(crisp_list_iterator* pIterator) {
	return __list_iterator_value(pIterator);
}

void
	crisp_list_for_each
		(crisp_list_iterator* pIterator, void(*pFunc)(void*)) {
	__list_iterator_for_each(pIterator, pFunc);
}