#include "list_iterate.h"

void
	__list_iterator_next
		(__list_iterator* pNode) {
	if (!pNode->node)
		return;

	pNode->node
		= pNode->node->next;
}

void
	__list_iterator_prev
		(__list_iterator* pNode) {
	if (!pNode->node)
		return;

	pNode->node
		= pNode->node->prev;
}

void*
	__list_iterator_value
		(__list_iterator* pNode) {
	if (!pNode->node)
		return 0;

	return
		pNode->node->entity;
}

void
	__list_iterator_for_each
		(__list_iterator* pIterator, void(*pFunc)(void*)) {
	while(pIterator->node) {
		pFunc(pIterator->node);
		pIterator->node
			= pIterator->node->next;
	}
}