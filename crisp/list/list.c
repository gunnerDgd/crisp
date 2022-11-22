#include "list.h"
#include <list/list.h>

void
	crisp_list_initialize
		(crisp_list* pList) {
	__list_entity* ptr_list = pList;
	__list_head_initialize(&ptr_list->head);
	
	ptr_list->controller
		= __list_default_controller();
}

void
	crisp_list_push_front
		(crisp_list* pList, crisp_list_node* pNode) {
	__list_entity_push_front((__list_entity*)pList, pNode);
}

void
	crisp_list_push_back
		(crisp_list* pList, crisp_list_node* pNode) {
	__list_entity_push_back((__list_entity*)pList, pNode);
}

void
	crisp_list_push_at
		(crisp_list* pList, crisp_list_node* pNode, crisp_list_node* pNodeAt) {
	__list_entity_push_at((__list_entity*)pList, pNode, pNodeAt);
}

crisp_list_node*
	crisp_list_pop_front
		(crisp_list* pList) {
	return
		__list_entity_pop_front((__list_entity*)pList);
}

crisp_list_node*
	crisp_list_pop_back
		(crisp_list* pList) {
	return
		__list_entity_pop_back((__list_entity*)pList);
}

void
	crisp_list_pop_at
		(crisp_list* pList, crisp_list_node* pNode) {
	__list_entity_pop_at((__list_entity*)pList, pNode);
}