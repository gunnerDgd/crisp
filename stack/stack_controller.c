#include "stack_controller.h"

__stack_controller
__stack_controller_entity =
	{
		.push		  = &__stack_push		 ,
		.push_bounded = &__stack_push_bounded,

		.pop		  = &__stack_pop,
		.pop_bounded  = &__stack_pop_bounded
	};

__stack_controller*
	__stack_default_controller() {
		return
			&__stack_controller_entity;
}

void
	__stack_push
		(__stack_head* pHead, __stack_node* pNode) {
	pNode->next = pHead->node;
	pHead->node = pNode;
}

void
	__stack_push_bounded
		(__stack_head*  pHead	  ,
		 __stack_node** pNodeArray,
		 crisp_u64		pNodeCount) {
	while (--pNodeCount >= 0)
		__stack_push(pHead, pNodeArray[pNodeCount]);
}

__stack_node*
	__stack_pop
		(__stack_head* pHead) {
	__stack_node* node_pop = pHead->node;

	if (!node_pop)
		return node_pop;

	pHead->node	   = node_pop->next;
	node_pop->next = 0;

	return node_pop;
}

void
	__stack_pop_bounded
		(__stack_head*  pHead	  ,
		 __stack_node** pNodeArray,
		 crisp_u64	    pNodeCount) {
	while(--pNodeCount >= 0) {
		pNodeArray[pNodeCount] = __stack_pop(pHead);
		if (!pNodeArray[pNodeCount])
			return;
	}
}