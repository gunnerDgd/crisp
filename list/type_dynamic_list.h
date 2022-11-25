#pragma once
#include "../base/type_allocator.h"
#include "type_list.h"

typedef __list_node     __dynamic_list_node    ;
typedef __list_iterator __dynamic_list_iterator;

typedef struct
	__dynamic_list_head {
	__list_head		   head	;
	__allocator_entity alloc;
}	__dynamic_list_head;

typedef struct
	__dynamic_list_controller {
	void (*push_front)(__dynamic_list_head*, void*, crisp_u64);
	void (*push_back) (__dynamic_list_head*, void*, crisp_u64);
	void (*push_at)   (__dynamic_list_head*, __dynamic_list_node*, void*, crisp_u64);

	void (*pop_front) (__dynamic_list_head*);
	void (*pop_back)  (__dynamic_list_head*);
	void (*pop_at)    (__dynamic_list_head*, __dynamic_list_node*);

	void (*begin)	  (__dynamic_list_iterator*);
	void (*end)		  (__dynamic_list_iterator*);
}	__dynamic_list_controller;

typedef struct
	__dynamic_list_entity {
	__dynamic_list_head		   head;
	__dynamic_list_controller* controller;
}	__dynamic_list_entity;

#define __dynamic_list_entity_push_front(pHead, pEntity, pEntitySize)\
	__dynamic_list_push_front(&((pHead)->head), pEntity, pEntitySize)

#define __dynamic_list_entity_push_back(pHead, pEntity, pEntitySize)\
	__dynamic_list_push_back(&((pHead)->head), pEntity, pEntitySize)

#define __dynamic_list_entity_push_at(pHead, pIterator, pEntity, pEntitySize)\
	__dynamic_list_push_at(&((pHead)->head), (pIterator)->node, pEntity, pEntitySize)

#define __dynamic_list_entity_pop_front(pHead)\
	__dynamic_list_pop_front(&((pHead)->head))

#define __dynamic_list_entity_pop_back(pHead)\
	__dynamic_list_pop_back(&((pHead)->head))

#define __dynamic_list_entity_pop_at(pHead, pNodeAt)\
	__dynamic_list_pop_at(&((pHead)->head), (pNodeAt))