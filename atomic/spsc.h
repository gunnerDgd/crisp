#pragma once
#include "type_spsc.h"

void
	__spsc_head_initialize
		(__spsc_head*);

void
	__spsc_node_initialize
		(__spsc_head*, __spsc_node*, void*);