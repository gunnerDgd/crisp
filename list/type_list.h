#pragma once
#include "../base/type_primitive.h"

typedef struct
	__list_node {
	struct __list_node* prev, * next;
	void*				head  ,
		*				entity;
}	__list_node;

typedef struct
	__list_head {
	__list_node* frontmost, * backmost;
}	__list_head;

typedef struct
	__list_iterator {
	__list_node* node;
}	__list_iterator;

typedef struct 
	__list_controller {
	void		 (*push_front)(__list_head*, __list_node*);
	void		 (*push_back) (__list_head*, __list_node*);
	void		 (*push_at)   (__list_head*, __list_node*, __list_node*);

	__list_node* (*pop_front) (__list_head*);
	__list_node* (*pop_back)  (__list_head*);
	void		 (*pop_at)    (__list_head*, __list_node*);
}	__list_controller;

typedef struct
	__list_entity {
	__list_head		   head;
	__list_controller* controller;
}	__list_entity;

#define __list_entity_push_front(pEntity, pNode)\
	((__list_controller*)((pEntity)->controller))->push_front(&((pEntity)->head), pNode)

#define __list_entity_push_back(pEntity, pNode)\
	((__list_controller*)((pEntity)->controller))->push_back(&((pEntity)->head), pNode)

#define __list_entity_push_at(pEntity, pNode, pNodeAt)\
	((__list_controller*)((pEntity)->controller))->push_at(&((pEntity)->head), pNode, pNodeAt)

#define __list_entity_pop_front(pEntity)\
	((__list_controller*)((pEntity)->controller))->pop_front(&((pEntity)->head))

#define __list_entity_pop_back(pEntity)\
	((__list_controller*)((pEntity)->controller))->pop_back(&((pEntity)->head))

#define __list_entity_pop_at(pEntity, pNode)\
	((__list_controller*)((pEntity)->controller))->pop_at(&((pEntity)->head), pNode)