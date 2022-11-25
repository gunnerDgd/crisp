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
	pNode->prev	  = 0;
	pNode->next	  = pHead->frontmost;
	pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

	pHead->frontmost = pNode;
	if (!pHead->backmost)
		 pHead->backmost  = pNode;
	else
		 pNode->next->prev = pNode;
}

void
	__list_push_back
		(__list_head* pHead, __list_node* pNode) {
	pNode->next	  = 0;
	pNode->prev	  = pHead->backmost;
	pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

	pHead->backmost = pNode;
	if (!pHead->frontmost)
	 	 pHead->frontmost = pNode;
	else
		 pNode->prev->next = pNode;
}

void
	__list_push_at
		(__list_head* pHead, __list_node* pNode, __list_node* pNodeAt) {
	if (!pNode || !pNodeAt)
		return; // Invalid Parameter.
		
	pNode->prev   = pNodeAt;
	pNode->next   = pNodeAt->next;
	pNode->entity = (crisp_u8*)pNode + sizeof(__list_node);

	if(pNodeAt->next)
		pNodeAt->next->prev = pNode;
}

__list_node*
	__list_pop_front
		(__list_head* pHead) {
	__list_node* node_popped = pHead->frontmost;

	if (!pHead->frontmost) // Empty List
		return node_popped;
	pHead->frontmost = pHead->frontmost->next;

	if (!pHead->frontmost)
		pHead->backmost = 0; // If the Popped Node was Last Node;
	else
		pHead->frontmost->prev = 0;

	return node_popped;
}

__list_node*
	__list_pop_back
		(__list_head* pHead) {
	__list_node* node_popped = pHead->backmost;

	if (!pHead->backmost) // Empty List
		return node_popped;
	pHead->backmost
		= pHead->backmost->prev;
	if (!pHead->backmost)
		 pHead->frontmost = 0; // If the Popped Node was Last Node;

	return node_popped;
}

void
	__list_pop_at
		(__list_head* pHead, __list_node* pNode) {
	if (!pNode->prev) {
		__list_pop_front(pHead);
		return;
	}
	if (!pNode->next) {
		__list_pop_back (pHead);
		return;
	}

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;
}