#pragma once
#include "type_primitive.h"

typedef struct 
	__allocator_base {
	crisp_u64 size_max ,
			  size_unit;

	void*	  handle;
}	__allocator_base;

typedef struct
	__allocator_controller {
	void* (*allocate)     (__allocator_base*, crisp_u64);
	void* (*allocate_unit)(__allocator_base*);
	void* (*allocate_max) (__allocator_base*);
	
	void  (*deallocate)   (__allocator_base*, void*);

	crisp_u64 (*copy)		    (void*, void*, crisp_u64);
	crisp_u64 (*copy_with_clear)(void*, void*, crisp_u64);
}	__allocator_controller;

typedef struct
	__allocator_entity {
	__allocator_base		base;
	__allocator_controller* controller;
}	__allocator_entity;