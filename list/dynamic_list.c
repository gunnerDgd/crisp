#include "dynamic_list.h"
#include "list.h"

void
	__dynamic_list_head_initialize
		(__dynamic_list_head*	 pHead	   ,
		 __allocator_base*		 pAllocBase,
		 __allocator_controller* pAlloc)   {
	pHead->alloc	  = pAlloc;
	pHead->alloc_base = pAllocBase;

	__list_head_initialize(&pHead->head);
}

void
	__dynamic_list_head_cleanup
		(__dynamic_list_head* pHead) {
	__dynamic_list_node* node_cleanup = pHead->head.frontmost;

	while(node_cleanup) {
		__dynamic_list_node* node_next
			= node_cleanup->next;

		pHead->alloc->deallocate
			(pHead->alloc_base, node_cleanup);
		node_cleanup = node_next;
	}
}

__dynamic_list_node*
	__dynamic_list_node_initialize
		(__dynamic_list_head* pHead, crisp_u64 pNodeSize) {
	__dynamic_list_node*
		node_new = pHead->alloc->allocate
						(pHead->alloc_base, pNodeSize + sizeof(__dynamic_list_node));

	node_new->entity = (crisp_u8*)node_new + sizeof(__dynamic_list_node);
	node_new->next   = 0;
	node_new->prev   = 0;
	node_new->head   = pHead;

	return node_new;
}

void
	__dynamic_list_node_cleanup
		(__dynamic_list_node* pNode) {
	__dynamic_list_head* head = pNode->head;

	head->alloc->deallocate
		(head->alloc_base, pNode);
}