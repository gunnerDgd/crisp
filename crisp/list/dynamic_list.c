#include "dynamic_list.h"

#include <list/dynamic_list.h>
#include <list/dynamic_list_controller.h>

void
	crisp_dynamic_list_initialize
		(crisp_dynamic_list* pList, crisp_allocator* pAlloc) {
	if (!pList || !pAlloc)
		return;

	__dynamic_list_entity* entity = pList;

	entity->controller 
		= __dynamic_list_default_controller();
		  __dynamic_list_head_initialize   (&entity->head, pAlloc);
}

void
	crisp_dynamic_list_cleanup
		(crisp_dynamic_list* pList) {
	if (!pList)
		return;

	__dynamic_list_entity*		 entity = pList;
	__dynamic_list_head_cleanup(&entity->head);
}

void
	crisp_dynamic_list_push_front
		(crisp_dynamic_list* pList, void* pEntity, crisp_u64 pEntitySize) {
	if (!pList || !pEntity)
		return;

	((__dynamic_list_entity*)pList)
		->controller->push_front
			(pList, pEntity, pEntitySize);
}

void
	crisp_dynamic_list_push_back
		(crisp_dynamic_list* pList, void* pEntity, crisp_u64 pEntitySize) {
	if (!pList || !pEntity)
		return;

	((__dynamic_list_entity*)pList)
		->controller->push_front
			(pList, pEntity, pEntitySize);
}

void
	crisp_dynamic_list_push_at
		(crisp_dynamic_list*		  pList      ,
		 void*						  pEntity    ,
		 crisp_u64					  pEntitySize, 
		 crisp_dynamic_list_iterator* pIterator) {
	if (!pList || !pEntity || !pIterator)
		return;

	__list_iterator* iterator = pIterator;
	((__dynamic_list_entity*)pList)
		->controller->push_at
			(pList, iterator->node, pEntity, pEntitySize);
}

void
	crisp_dynamic_list_pop_front
		(crisp_dynamic_list* pList) {
	if (!pList)
		return;

	((__dynamic_list_entity*)pList)->controller->pop_front(pList);
}

void
	crisp_dynamic_list_pop_back
		(crisp_dynamic_list* pList) {
	if (!pList)
		return;

	((__dynamic_list_entity*)pList)->controller->pop_back(pList);
}

void
	crisp_dynamic_list_pop_at
		(crisp_dynamic_list*		  pList,
		 crisp_dynamic_list_iterator* pIterator) {
	if (!pList || !pIterator)
		return;

	__list_iterator* iterator = pIterator;
	if (iterator->node)
		return;

	__dynamic_list_node* next = iterator->node->next;
	((__dynamic_list_entity*)pList)
		->controller->pop_at(pList, iterator->node);
	
	iterator->node = next;
}