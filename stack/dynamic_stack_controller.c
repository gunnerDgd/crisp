#include "dynamic_stack_controller.h"
#include "stack_controller.h"

__dynamic_stack_controller
__dynamic_stack_controller_entity
	= {
		.push		  = &__dynamic_stack_push,
		.push_bounded = &__dynamic_stack_push_bounded,

		.pop		  = &__dynamic_stack_pop,
		.pop_bounded  = &__dynamic_stack_pop_bounded
	  };

__dynamic_stack_controller*
	__dynamic_stack_default_controller() {
		return
			&__dynamic_stack_controller_entity;
}

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

void
	__dynamic_stack_pop
		(__dynamic_stack_head* pHead) {
	__dynamic_stack_node*		 node = __stack_pop(&pHead->head);
	__dynamic_stack_node_cleanup(node);
}

void
	__dynamic_stack_pop_bounded
		(__dynamic_stack_head*  pHead,
		 crisp_u64				pNodeCount) {
	while (--pNodeCount >= 0)
		__dynamic_stack_pop(pHead);
}

void*
	__dynamic_stack_peek
		(__dynamic_stack_head* pHead) {
	return
		pHead->head.node->entity;
}