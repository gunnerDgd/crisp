#pragma once
#include "type_spsc.h"

__queue_controller*
	__spsc_default_controller();

crisp_bool
	__spsc_push
		(__spsc_head*, void*);

void
	__spsc_push_until_success
		(__spsc_head*, void*);

crisp_u64
	__spsc_push_bounded
		(__spsc_head*, void**, crisp_u64);

void*
	__spsc_pop
		(__spsc_head*);

void*
	__spsc_pop_until_success
		(__spsc_head*);

crisp_u64
	__spsc_pop_bounded
		(__spsc_head*, void**, crisp_u64);