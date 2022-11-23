#pragma once
#include "type_stack.h"
#include "../base/type_allocator.h"

typedef __stack_node __dynamic_stack_node;

typedef struct
	__dynamic_stack_head {
	__allocator_entity alloc;
	__stack_head	   head ;
}	__dynamic_stack_head;

typedef struct
	__dynamic_stack_controller {
	void  (*push)		 (__dynamic_stack_head*, void* , crisp_u64) ;
	void  (*push_bounded)(__dynamic_stack_head*, void**, crisp_u64*, crisp_u64);
	
	void* (*pop)		 (__dynamic_stack_head*);
	void  (*pop_bounded) (__dynamic_stack_head*, void**, crisp_u64);
}	__dynamic_stack_controller;

typedef struct
	__dynamic_stack_entity {
	__dynamic_stack_head	   head;
	__dynamic_stack_controller controller;
}	__dynamic_stack_entity;