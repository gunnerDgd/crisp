#include "turbo_list.h"

#include <list/list.h>
#include <list/type_list.h>

#include <turbo/turbo_list.h>

void
	crisp_turbo_list_initialize
		(crisp_turbo_list* pHead) {
	__list_entity* head = pHead;
				   head->controller = __turbo_list_controller();

	__list_head_initialize(&head->head);
}