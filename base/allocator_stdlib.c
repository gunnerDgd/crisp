#include "allocator_stdlib.h"

#include <stdlib.h>
#include <string.h>

__allocator_base
	__allocator_stdlib_entity = 
		{
			.handle    = 0 ,
			.size_max  = -1,
			.size_unit = 1
		};

__allocator_controller
	__allocator_stdlib_controller_entity
		= {
			.allocate	     = &__allocator_stdlib_allocate	    ,
			.allocate_max    = &__allocator_stdlib_allocate_max ,
			.allocate_unit   = &__allocator_stdlib_allocate_unit,

			.deallocate      = &__allocator_stdlib_deallocate   ,
			.copy		     = &__allocator_stdlib_copy		    ,
			.copy_with_clear = &__allocator_stdlib_copy_with_clear
		  };

__allocator_base*
	__allocator_standard_library() {
		return
			&__allocator_stdlib_entity;
}

__allocator_controller*
	__allocator_controller_standard_library() {
		return
			&__allocator_stdlib_controller_entity;
}

void*
	__allocator_stdlib_allocate
		(__allocator_base* pAlloc, crisp_u64 pAllocSize) {
	return
		malloc(pAllocSize);
}

void*
	__allocator_stdlib_allocate_unit
		(__allocator_base* pAlloc) {
	return
		malloc(1);
}

void*
	__allocator_stdlib_allocate_max
		(__allocator_base* pAlloc) {
	return 0;
}

void
	__allocator_stdlib_deallocate
		(__allocator_base* pAlloc, void* pPointer) {
	free(pPointer);
}

crisp_u64
	__allocator_stdlib_copy
		(void* pDest, void* pSource, crisp_u64 pSize) {
	memcpy(pDest, pSource, pSize);
	return pSize;
}

crisp_u64
	__allocator_stdlib_copy_with_clear
		(void* pDest, void* pSource, crisp_u64 pSize) {
	memcpy(pDest, pSource, pSize);
	memset(pSource, 0x00, pSize);

	return pSize;
}