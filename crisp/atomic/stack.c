#include "stack.h"

#include <atomic/type_stack.h>
#include <atomic/stack.h>

#include <stack/stack.h>

void
	crisp_atomic_stack_initialize
		(crisp_atomic_stack* pStack) {
	__stack_entity* stack = pStack;
	stack->controller = __atomic_stack_controller();
						__stack_head_initialize  (&stack->head);
}