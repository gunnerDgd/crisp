#pragma once
#include "type_allocator.h"

__allocator_base*
	__allocator_standard_library();

__allocator_controller*
	__allocator_controller_standard_library();

void*
	__allocator_stdlib_allocate
		(__allocator_base*, crisp_u64);

void*
	__allocator_stdlib_allocate_unit
		(__allocator_base*);

void*
	__allocator_stdlib_allocate_max
		(__allocator_base*);

void
	__allocator_stdlib_deallocate
		(__allocator_base*, void*);

crisp_u64
	__allocator_stdlib_copy
		(void*, void*, crisp_u64);

crisp_u64
	__allocator_stdlib_copy_with_clear
		(void*, void*, crisp_u64);