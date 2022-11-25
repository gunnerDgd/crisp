#include "list_iterate.h"

void
	__list_iterator_next
		(__list_iterator* pNode) {
	if (pNode->node == &__list_node_placeholder_back)
		return;

	pNode->node = pNode->node->next;
}

void
	__list_iterator_prev
		(__list_iterator* pNode) {
	if (pNode->node == &__list_node_placeholder_front)
		return;

	pNode->node
		= pNode->node->prev;
}

void*
	__list_iterator_value
		(__list_iterator* pNode) {
	return
		pNode->node->entity;
}

void
	__list_iterator_for_each
		(__list_iterator* pBegin,
		 __list_iterator* pEnd  ,
		 void		   (* pFunc)(void*)) {
	__list_node* node = pBegin->node;
	while(node != pEnd->node) {
		pFunc(node->entity);
		node = node->next;
	}
}