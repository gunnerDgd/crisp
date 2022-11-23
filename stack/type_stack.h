#pragma once
#include "../base/type_primitive.h"

typedef struct
	__stack_node {
	struct __stack_node* next;
	void			   * entity,
					   * head  ;
}	__stack_node;

typedef struct
	__stack_head {
	__stack_node* node;
}	__stack_head;

typedef struct
	__stack_controller {
	void		  (*push)		 (__stack_head*, __stack_node*);
	void		  (*push_bounded)(__stack_head*, __stack_node**, crisp_u64);

	__stack_node* (*pop)		 (__stack_head*);
	void		  (*pop_bounded) (__stack_head*, __stack_node**, crisp_u64);
}	__stack_controller;

typedef struct
	__stack_entity {
	__stack_head	   head;
	__stack_controller controller;
}	__stack_entity;