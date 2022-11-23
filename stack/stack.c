#include "stack.h"

void
	__stack_head_initialize
		(__stack_head* pHead) {
	pHead->node = 0;
}

void
	__stack_node_initialize
		(__stack_node* pNode, __stack_head* pHead, void* pEntity) {
	pNode->entity = pEntity;
	pNode->head   = pHead;
}