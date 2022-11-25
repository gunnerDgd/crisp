#pragma once
#include "type.h"
#include <crisp/allocator/type.h>

void
	crisp_spsc_initialize
		(crisp_spsc*, crisp_allocator*, crisp_u64);

void
	crisp_spsc_cleanup
		(crisp_spsc*);