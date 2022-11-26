#include "spsc.h"

#include <atomic/spsc.h>

#include <queue/type.h>
#include <queue/queue.h>
#include <queue/queue_controller.h>

void
	crisp_spsc_initialize
		(crisp_spsc* pHead, crisp_allocator* pAlloc, crisp_u64 pSize) {
	__queue_entity* spsc = pHead;
	
	spsc->head		 = __queue_head_initialize  (pAlloc, pSize);
	spsc->controller = __spsc_default_controller();
	return spsc;
}

void
	crisp_spsc_cleanup
		(crisp_spsc* pHead) {
	__queue_head_cleanup
		(((__queue_entity*)pHead)->head);
}