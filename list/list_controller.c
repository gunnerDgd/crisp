#include "list_controller.h"

__list_controller
	__list_default_controller_entity = 
		{
			.push_front = &__list_push_front,
			.push_back  = &__list_push_back ,
			.push_at    = &__list_push_at   ,

			.pop_front	= &__list_pop_front ,
			.pop_back	= &__list_pop_back  ,
			.pop_at		= &__list_pop_at
		};


__list_controller*
	__list_default_controller() {
	return &__list_default_controller_entity;
}

void
	__list_push_front
		(__list_head* pHead, __list_node* pNode) {
	pNode->prev	  = pHead->frontmost;
	pNode->next	  = pHead->frontmost->next;
	pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

	pHead->frontmost->next = pNode;
	pNode->next->prev	   = pNode;
}

void
	__list_push_back
		(__list_head* pHead, __list_node* pNode) {
	pNode->next	  = pHead->backmost;
	pNode->prev	  = pHead->backmost->prev;
	pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

	pHead->backmost->prev = pNode;
	pNode->prev->next	  = pNode;
}

void
	__list_push_at
		(__list_head* pHead, __list_node* pNode, __list_node* pNodeAt) {
	pNode  ->prev		= pNodeAt;
	pNode  ->next		= pNodeAt->next;
	pNodeAt->next->prev = pNode;
	pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);
}

__list_node*
	__list_pop_front
		(__list_head* pHead) {
	__list_node* node_popped = pHead->frontmost->next;
	if (node_popped == &__list_node_placeholder_back)
		return 0;
	
	pHead->frontmost->next = node_popped->next;
	return node_popped;
}

__list_node*
	__list_pop_back
		(__list_head* pHead) {
	__list_node* node_popped = pHead->backmost->prev;
	if (node_popped == &__list_node_placeholder_front)
		return 0;

	pHead->backmost->prev = node_popped->prev;
	return node_popped;
}

void
	__list_pop_at
		(__list_head* pHead, __list_node* pNode) {
	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;
}