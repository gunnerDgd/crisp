#pragma once
#include "../base/type_allocator.h"
#include "type_list.h"

typedef __list_node __dynamic_list_node;

typedef struct
	__dynamic_list_head {
	__list_head				head	  ;
	__allocator_base*		alloc_base;
	__allocator_controller* alloc	  ;
}	__dynamic_list_head;

typedef struct
	__dynamic_list_controller {
	void (*push_front)(__dynamic_list_head*, void*, crisp_u64);
	void (*push_back) (__dynamic_list_head*, void*, crisp_u64);
	void (*push_at)   (__dynamic_list_head*, __dynamic_list_node*, void*, crisp_u64);

	void (*pop_front) (__dynamic_list_head*);
	void (*pop_back)  (__dynamic_list_head*);
	void (*pop_at)    (__dynamic_list_head*, __dynamic_list_node*);
}	__dynamic_list_controller;

typedef struct
	__dynamic_list_entity {
	__dynamic_list_head		   head;
	__dynamic_list_controller* controller;
}	__dynamic_list_entity;