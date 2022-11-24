#pragma once
#include "type_spsc.h"

__spsc_controller*
	__spsc_default_controller();

crisp_bool
	__spsc_push
		(__spsc_head*, void*);

void
	__spsc_push_until_success
		(__spsc_head*, void*);

void
	__spsc_push_bounded
		(__spsc_head*, void**, crisp_u64);

void*
	__spsc_pop
		(__spsc_head*);

void*
	__spsc_pop_until_success
		(__spsc_head*);

void
	__spsc_pop_bounded
		(__spsc_head*, void**, crisp_u64);

crisp_bool
	__spsc_do_push
		(__spsc_head*);

void
	__spsc_do_push_until_success
		(__spsc_head*);

void*
	__spsc_do_pop
		(__spsc_head*);

void*
	__spsc_do_pop_until_success
		(__spsc_head*);