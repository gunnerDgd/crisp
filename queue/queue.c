#include "queue.h"

__queue_head*
	__queue_head_initialize
		(__allocator_entity* pAlloc, crisp_u64 pCount) {
	__queue_head* head
		= pAlloc->controller->allocate
			(&pAlloc->base, 
				sizeof(__queue_head) + 
				sizeof(__queue_node) * pCount);

	head->alloc = *pAlloc;
	head->node	= (crisp_u8*)head + sizeof(__queue_head);
	
	for(crisp_u64 init_it = 0;
				  init_it < pCount - 1;
				  init_it++) {
		head->node[init_it].next = &head->node[init_it + 1];
		head->node[init_it].head = head;
	}

	head->node[pCount - 1].next = &head->node[0];
	head->node[pCount - 1].head =  head;

	head->push_ptr = head->node->next;
	head->pop_ptr  = head->node;

	return head;
}

void
	__queue_head_cleanup
		(__queue_head* pHead) {
	pHead->alloc.controller->deallocate
		(&pHead->alloc.base, pHead);
}