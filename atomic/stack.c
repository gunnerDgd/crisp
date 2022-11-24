#include "stack.h"

__stack_controller
	__atomic_stack_controller_entity
		= {
			.push		  = &__atomic_stack_push		,
			.push_bounded = &__atomic_stack_push_bounded,

			.pop		  = &__atomic_stack_pop			,
			.pop_bounded  = &__atomic_stack_pop_bounded
		  };

__stack_controller*
	__atomic_stack_controller() {
		return
			&__atomic_stack_controller_entity;
}

void
	__atomic_stack_push_bounded
		(__atomic_stack_head*  pHead	 ,
		 __atomic_stack_node** pNodeArray,
		 crisp_u64			   pNodeCount) {
	while (--pNodeCount >= 0)
		__atomic_stack_push
			(pHead, pNodeArray[pNodeCount]);
}

void
	__atomic_stack_pop_bounded
		(__atomic_stack_head*  pHead	 ,
		 __atomic_stack_node** pNodeArray,
		 crisp_u64			   pNodeCount) {
	while(--pNodeCount >= 0)
		pNodeArray[pNodeCount] = __atomic_stack_pop(pHead);
}