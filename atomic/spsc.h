#pragma once
#include "type_spsc.h"

__spsc_head*
	__spsc_head_initialize
		(__allocator_entity*, crisp_u64);

void
	__spsc_head_cleanup
		(__spsc_head*);