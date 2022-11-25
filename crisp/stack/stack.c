#include "stack.h"

#include <stack/stack.h>
#include <stack/stack_controller.h>

void
	crisp_stack_initialize
		(crisp_stack* pStack) {
	__stack_entity* stack = pStack;
	
	stack->controller = __stack_default_controller();
						__stack_head_initialize	  (&stack->head);
}

void
	crisp_stack_push
		(crisp_stack* pStack, crisp_stack_node* pNode) {
	__stack_entity* stack = pStack;
					stack->controller->push(&stack->head, pNode);
}

void
	crisp_stack_push_bounded
		(crisp_stack* pStack, crisp_stack_node** pNode, crisp_u64 pCount) {
	__stack_entity* stack = pStack;
					stack->controller->push_bounded(&stack->head, pNode, pCount);
}

crisp_stack_node*
	crisp_stack_pop
		(crisp_stack* pStack) {
	__stack_entity* stack = pStack;
	return
		stack->controller->pop(&stack->head);
}

void
	crisp_stack_pop_bounded
		(crisp_stack* pStack, crisp_stack_node** pNode, crisp_u64 pCount) {
	__stack_entity* stack = pStack;
	stack->controller->pop_bounded
		(&stack->head, pNode, pCount);
}