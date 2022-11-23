#include "dynamic_stack_controller.h"
#include "stack_controller.h"

void
	__dynamic_stack_push
		(__dynamic_stack_head* pHead	  ,
		 void*				   pEntity	  ,
		 crisp_u64			   pEntitySize) {
	__stack_push(&pHead->head,
		__dynamic_stack_node_initialize
			(pHead, pEntity, pEntitySize));
}

void
	__dynamic_stack_push_bounded
		(__dynamic_stack_head* pHead	  ,
		 void**				   pEntity	  ,
		 crisp_u64*			   pEntitySize,
		 crisp_u64			   pEntityCount) {
	while(--pEntityCount >= 0)
		__dynamic_stack_push
			(pHead, pEntity[pEntityCount], pEntitySize[pEntityCount]);
}

__dynamic_stack_node*
	__dynamic_stack_pop
		(__dynamic_stack_head* pHead) {
	return
		__stack_pop(&pHead->head);
}

void
	__dynamic_stack_pop_bounded
		(__dynamic_stack_head*  pHead	  ,
		 __dynamic_stack_node** pNodeArray,
		 crisp_u64				pNodeCount) {
	__stack_pop_bounded
		(pHead, pNodeArray, pNodeCount);
}