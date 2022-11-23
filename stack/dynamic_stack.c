#include "dynamic_stack.h"

void
	__dynamic_stack_head_initialize
		(__dynamic_stack_head* pHead, __allocator_entity* pAlloc) {
	pHead->alloc	 = *pAlloc;
	pHead->head.node = 0;
}

void
	__dynamic_stack_head_cleanup
		(__dynamic_stack_head* pHead) {
	while(pHead->head.node) {
		__dynamic_stack_node* next = pHead->head.node->next;
		__dynamic_stack_node_cleanup(pHead->head.node);

		pHead->head.node = next;
	}
}

__dynamic_stack_node*
	__dynamic_stack_node_initialize
		(__dynamic_stack_head* pHead, void* pEntity, crisp_u64 pEntitySize) {
	__dynamic_stack_node* node_new
		= pHead->alloc.controller->allocate
				(&pHead->alloc.base, pEntitySize + sizeof(__dynamic_stack_node));

	if (!node_new) return 0;

	node_new->entity = (crisp_u8*)node_new + sizeof(__dynamic_stack_node);
	node_new->head   = pHead;
	node_new->next   = 0;

	pHead->alloc.controller->copy(node_new->entity, pEntity);
	return node_new;
}

void
	__dynamic_stack_node_cleanup
		(__dynamic_stack_node* pNode) {
	__dynamic_stack_head* head = pNode->head;
	head->alloc.controller->deallocate
		(&head->alloc.base, pNode);
}