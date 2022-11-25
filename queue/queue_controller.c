#include "queue_controller.h"

__queue_controller
__queue_controller_entity =
	{
		.push				= &__queue_push		   ,
		.push_bounded		= &__queue_push_bounded,
		.push_until_success = &__queue_push  	   ,

		.pop				= &__queue_pop		   ,
		.pop_bounded		= &__queue_pop_bounded ,
		.pop_until_success  = &__queue_pop
	};

__queue_controller*
	__queue_default_controller() {
		return
			&__queue_controller_entity;
}

crisp_bool
	__queue_push
		(__queue_head* pHead, void* pEntity) {
	if (pHead->push_ptr == pHead->pop_ptr)
		return crisp_bool_false;

	pHead->push_ptr->entity = pEntity;
	pHead->push_ptr
		= pHead->push_ptr->next;

	return crisp_bool_true;
}

crisp_u64
	__queue_push_bounded
		(__queue_head* pHead, void** pEntityArray, crisp_u64 pEntityCount) {
	for(crisp_u64 push_count = 0;
				  push_count < pEntityCount;
				  push_count++)
		if (!__queue_push(pHead, pEntityArray[push_count]))
			return push_count;

	return pEntityCount;
}

void*
	__queue_pop
		(__queue_head* pHead) {
	if (pHead->pop_ptr->next == pHead->push_ptr)
		return 0;

					pHead->pop_ptr = pHead->pop_ptr->next;
	void* pop_ptr = pHead->pop_ptr->entity;

	return pop_ptr;
}

crisp_u64
	__queue_pop_bounded
		(__queue_head* pHead, void** pEntityArray, crisp_u64 pEntityCount) {
	for(crisp_u64 push_count = 0;
				  push_count < pEntityCount;
				  push_count++)
		if(!(pEntityArray[push_count] = __queue_pop(pHead)))
			return push_count;

	return pEntityCount;
}