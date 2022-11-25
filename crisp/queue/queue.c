#include "queue.h"

#include <queue/queue.h>
#include <queue/queue_controller.h>

void
	crisp_queue_initialize
		(crisp_queue* pHead, crisp_allocator* pAlloc, crisp_u64 pSize) {
	__queue_entity* queue			  = pHead;
					queue->head		  = __queue_head_initialize(pAlloc, pSize);
					queue->controller = __queue_default_controller();
	return queue;
}

void
	crisp_queue_cleanup
		(crisp_queue* pHead) {
	__queue_head_cleanup(pHead);
}

crisp_bool
	crisp_queue_push
		(crisp_queue* pHead, void* pEntity) {
	__queue_entity* queue = pHead;

	return
		queue->controller->push
			(queue->head, pEntity);
}

void
	crisp_queue_push_until_success
		(crisp_queue* pHead, void* pEntity) {
	__queue_entity* queue = pHead;
	queue->controller->push_until_success
		(queue->head, pEntity);
}

crisp_u64
	crisp_queue_push_bounded
		(crisp_queue* pHead, void** pEntityArray, crisp_u64 pEntityCount) {
	__queue_entity* queue = pHead;
	return
		queue->controller->push_bounded
			(queue->head, pEntityArray, pEntityCount);
}

void*
	crisp_queue_pop
		(crisp_queue* pHead) {
	__queue_entity* queue = pHead;
	return
		queue->controller->pop(queue->head);
}

void*
	crisp_queue_pop_until_success
		(crisp_queue* pHead) {
	__queue_entity* queue = pHead;
	return
		queue->controller->pop_until_success
			(queue->head);
}

crisp_u64
	crisp_queue_pop_bounded
		(crisp_queue* pHead, void** pEntityArray, crisp_u64 pEntityCount) {
	__queue_entity* queue = pHead;
	return
		queue->controller->pop_bounded
			(queue->head, pEntityArray, pEntityCount);
}