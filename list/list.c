#include "list.h"

__list_node
__list_node_placeholder_front = 
	{
		.next   = 0,
		.prev   = 0,

		.head   = 0,
		.entity = 0
	},
__list_node_placeholder_back = 
	{
		.next   = 0,
		.prev   = 0,

		.head   = 0,
		.entity = 0
	};

void
	__list_head_initialize
		(__list_head* pHead) {
	pHead->backmost  = &__list_node_placeholder_back ;
	pHead->frontmost = &__list_node_placeholder_front;

	pHead->frontmost->next = pHead->backmost ;
	pHead->backmost ->prev = pHead->frontmost;
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
	pIterator->node = pHead->frontmost->next;
}

void
	__list_iterator_initialize_end
		(__list_head* pHead, __list_iterator* pIterator) {
	pIterator->node = pHead->backmost;
}