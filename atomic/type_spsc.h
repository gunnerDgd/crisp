#pragma once
#include "../base/type_atomic.h"
#include "../base/type_primitive.h"

typedef struct
	__spsc_node {
	volatile struct __spsc_node* prev, * next;
	void					   * entity,
							   * head  ;
}	__spsc_node;

typedef struct
	__spsc_head {
	volatile __spsc_node* node,
						* read, *write;
}	__spsc_head;

typedef struct
	__spsc_controller {
	void(*push)				 (__spsc_head*, __spsc_node*);
	void(*push_until_success)(__spsc_head*, __spsc_node*);
	void(*push_bounded)		 (__spsc_head*, __spsc_node**, crisp_u64);

	__spsc_node* (*pop)				 (__spsc_head*);
	__spsc_node* (*pop_until_success)(__spsc_head*);
	void		 (*pop_bounded)		 (__spsc_head*, __spsc_node**, crisp_u64);
}	__spsc_controller;

typedef struct
	__spsc_entity {
	__spsc_head		  head;
	__spsc_controller controller;
}	__spsc_entity;