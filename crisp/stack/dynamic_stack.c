#include "dynamic_stack.h"

#include <stack/dynamic_stack.h>
#include <stack/dynamic_stack_controller.h>

void
	crisp_dynamic_stack_initialize
		(crisp_dynamic_stack* pStack, crisp_allocator* pAlloc) {
	__dynamic_stack_entity* stack = pStack;
	
	stack->controller = *__dynamic_stack_default_controller();
	__dynamic_stack_head_initialize
		(&stack->head, pAlloc);
}

void
	crisp_dynamic_stack_cleanup
		(crisp_dynamic_stack* pStack) {
	__dynamic_stack_head_cleanup
		(pStack);
}

void
	crisp_dynamic_stack_push
		(crisp_dynamic_stack* pStack, void* pEntity, crisp_u64 pEntitySize) {
	__dynamic_stack_entity* stack = pStack;
	stack->controller.push
		(&stack->head, pEntity, pEntitySize);
}

void
	crisp_dynamic_stack_push_bounded
		(crisp_dynamic_stack* pStack	  ,
		 void**				  pEntityArray,
		 crisp_u64*			  pEntitySize ,
		 crisp_u64			  pEntityCount) {
	__dynamic_stack_entity* stack = pStack;
	stack->controller.push_bounded
		(&stack->head, pEntityArray, pEntitySize, pEntityCount);
}

void
	crisp_dynamic_stack_pop
		(crisp_dynamic_stack* pStack) {
	__dynamic_stack_entity* stack = pStack;
	stack->controller.pop(&stack->head);
}

void
	crisp_dynamic_stack_pop_bounded
		(crisp_dynamic_stack* pStack, crisp_u64 pCount) {
	__dynamic_stack_entity* stack = pStack;
	stack->controller.pop_bounded
		(&stack->head, pCount);
}

void*
	crisp_dynamic_stack_peek
		(crisp_dynamic_stack* pStack) {
	__dynamic_stack_entity* stack = pStack;
	return
		stack->controller.peek(&stack->head);
}