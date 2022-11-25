#pragma once
#include "type.h"
#include <crisp/allocator/type.h>

void
	crisp_queue_initialize
		(crisp_queue*, crisp_allocator*, crisp_u64);

void
	crisp_queue_cleanup
		(crisp_queue*);

crisp_bool
	crisp_queue_push
		(crisp_queue*, void*);

void
	crisp_queue_push_until_success
		(crisp_queue*, void*);

crisp_u64
	crisp_queue_push_bounded
		(crisp_queue*, void**, crisp_u64);

void*
	crisp_queue_pop
		(crisp_queue*);

void*
	crisp_queue_pop_until_success
		(crisp_queue*);

crisp_u64
	crisp_queue_pop_bounded
		(crisp_queue*, void**, crisp_u64);