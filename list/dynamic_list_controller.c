#include "dynamic_list_controller.h"
#include "dynamic_list.h"

#include "list.h"

__dynamic_list_controller
	__dynamic_list_default_controller_entity
		= {
			.push_front = &__dynamic_list_push_front,
			.push_back  = &__dynamic_list_push_back ,
			.push_at    = &__dynamic_list_push_at   ,

			.pop_front  = &__dynamic_list_pop_front ,
			.pop_back	= &__dynamic_list_pop_back  ,
			.pop_at		= &__dynamic_list_pop_at
		  };

__dynamic_list_controller*
	__dynamic_list_default_controller() {
		return &__dynamic_list_default_controller_entity;
}

void
	__dynamic_list_push_front
		(__dynamic_list_head* pHead, void* pEntity, crisp_u64 pEntitySize) {
	__dynamic_list_node* node_new
		= __dynamic_list_node_initialize(pHead, pEntitySize);
	pHead->alloc.controller->copy
		(node_new->entity, pEntity, pEntitySize);

	__list_push_front
		(&pHead->head, node_new);
}

void
	__dynamic_list_push_back
		(__dynamic_list_head* pHead, void* pEntity, crisp_u64 pEntitySize) {
	__dynamic_list_node* node_new
		= __dynamic_list_node_initialize(pHead, pEntitySize);
	pHead->alloc.controller->copy
		(node_new->entity, pEntity, pEntitySize);

	__list_push_back
		(&pHead->head, node_new);
}

void
	__dynamic_list_push_at
		(__dynamic_list_head* pHead		 ,
		 __dynamic_list_node* pNodeAt	 ,
		 void				* pEntity	 ,
		 crisp_u64			  pEntitySize) {
	__dynamic_list_node* node_new
		= __dynamic_list_node_initialize(pHead, pEntitySize);
	pHead->alloc.controller->copy
		(node_new->entity, pEntity, pEntitySize);

	__list_push_at
		(&pHead->head, node_new, pNodeAt);
}

void
	__dynamic_list_pop_front
		(__dynamic_list_head* pHead) {
	__dynamic_list_node_cleanup
		(__list_pop_front(&pHead->head));
}

void
	__dynamic_list_pop_back
		(__dynamic_list_head* pHead) {
	__dynamic_list_node_cleanup
		(__list_pop_back(&pHead->head));
}

void
	__dynamic_list_pop_at
		(__dynamic_list_head* pHead, __dynamic_list_node* pNodeAt) {
	__list_pop_at			   (&pHead->head, pNodeAt);
	__dynamic_list_node_cleanup(pNodeAt);
}