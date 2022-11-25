#pragma once
#include <base/type_primitive.h>
#include <base/type_allocator.h>

typedef struct
	__queue_node {
	struct __queue_node* next  ;
	void			   * head  ,
					   * entity;
}	__queue_node;

typedef struct
	__queue_head {
	__queue_node	 * node,
					 * push_ptr, *pop_ptr;
	__allocator_entity alloc;
}	__queue_head;

typedef struct
	__queue_controller {
	crisp_bool (*push)			    (__queue_head*, void*);
	void	   (*push_until_success)(__queue_head*, void*); // For SPSC / MPMC Support. Not for Generic Circular Queue.
	crisp_u64  (*push_bounded)	    (__queue_head*, void**, crisp_u64);

	void*	   (*pop)			    (__queue_head*);
	void*	   (*pop_until_success) (__queue_head*);		// For SPSC / MPMC Support. Not for Generic Circular Queue.
	crisp_u64  (*pop_bounded)	    (__queue_head*, void**, crisp_u64);
}	__queue_controller;

typedef struct
	__queue_entity {
	__queue_head*	    head;
	__queue_controller* controller;
}	__queue_entity;