#include "type.h"

__queue_controller*
	__queue_default_controller();

crisp_bool
	__queue_push
		(__queue_head*, void*);

crisp_u64
	__queue_push_bounded
		(__queue_head*, void**, crisp_u64);

void*
	__queue_pop
		(__queue_head*);

crisp_u64
	__queue_pop_bounded
		(__queue_head*, void**, crisp_u64);