#pragma once
#include "../base/type_atomic.h"
#include "../base/type_primitive.h"
#include "../base/type_allocator.h"

typedef struct
	__spsc_node {
	volatile struct __spsc_node* next;
	volatile void			   * entity,
							   * head  ;
}	__spsc_node;

typedef struct
	__spsc_head {
	volatile __spsc_node* node,
						* read, *write;
	__allocator_entity	  alloc;
}	__spsc_head;

typedef struct
	__spsc_controller {
	void(*push)				 (__spsc_head*, void*);
	void(*push_until_success)(__spsc_head*, void*);
	void(*push_bounded)		 (__spsc_head*, void**, crisp_u64);

	void(*pop)				 (__spsc_head*, void*);
	void(*pop_until_success) (__spsc_head*, void*);
	void(*pop_bounded)		 (__spsc_head*, void**, crisp_u64);
}	__spsc_controller;

typedef struct
	__spsc_entity {
	__spsc_head		  head;
	__spsc_controller controller;
}	__spsc_entity;