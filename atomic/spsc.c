#include "spsc.h"

__spsc_head*
	__spsc_head_initialize
		(__allocator_entity* pAlloc, crisp_u64 pNodeCount) {
	__spsc_head* head
		= pAlloc->controller->allocate
			(&pAlloc->base, 
			 sizeof(__spsc_head) +
			 sizeof(__spsc_node) * pNodeCount);
	__spsc_node* node
		= (crisp_u8*)head + sizeof(__spsc_head);

	for(crisp_u64 it_init = 0;
				  it_init < pNodeCount - 1 ;
				  it_init++) {
		node[it_init].next   = &node[it_init + 1];
		node[it_init].head   = head;
		node[it_init].entity = 0;
	}

	node[pNodeCount - 1].next   = node;
	node[pNodeCount - 1].head   = head;
	node[pNodeCount - 1].entity = 0;

	head->read  = node;
	head->write = node->next;

	return head;
}

void
	__spsc_head_cleanup
		(__spsc_head* pSpsc) {
	__allocator_entity alloc = pSpsc->alloc;
	alloc.controller->deallocate
		(&alloc.base, pSpsc);
}