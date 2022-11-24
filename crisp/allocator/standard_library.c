#include "standard_library.h"
#include <base/allocator_stdlib.h>

void
	crisp_allocator_standard_library
		(crisp_allocator* pAlloc) {
	__allocator_entity* entity = pAlloc;

	entity->base	   = *__allocator_standard_library();
	entity->controller =  __allocator_controller_standard_library();
}