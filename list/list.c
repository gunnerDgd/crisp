#include "list.h"

void
	__list_head_initialize
		(__list_head* pHead) {
	pHead->backmost  = 0;
	pHead->frontmost = 0;
}

void
	__list_node_initialize
		(__list_node* pNode ,
		 __list_head* pHead , 
		 __list_node* pFront, 
		 __list_node* pBack ,
		 void*		  pEntity) {
	pNode->entity = pEntity;

	pNode->next = pBack ;
	pNode->prev = pFront;

	pNode->head = pHead ;
}

void
	__list_iterator_initialize_begin
		(__list_head* pHead, __list_iterator* pIterator) {
	pIterator->node = pHead->frontmost;
}

void
	__list_iterator_initialize_end
		(__list_head* pHead, __list_iterator* pIterator) {
	pIterator->node = pHead->backmost;
}