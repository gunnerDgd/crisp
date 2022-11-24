#pragma once
#include <base/type_primitive.h>
#include <base/type_allocator.h>

typedef struct
	__queue_node {
	struct __queue_node* next;
	void			   * head  ,
					   * entity;
}	__queue_node;

typedef struct
	__queue_head {
	__queue_node* node,
				* read, *write; // For Circular Queue Support. Most Of Linear Queue Does not use this member.
}	__queue_head;

typedef struct
	__dynamic_queue_head {
	__queue_head	   head ;
	__allocator_entity alloc;
}	__dynamic_queue_head;

typedef struct
	__queue_controller {
	void		  (*push)			   (__queue_head*, __queue_node*);
	void		  (*push_until_success)(__queue_head*, __queue_node*);
	void		  (*push_bounded)	   (__queue_head*, __queue_node**, crisp_u64);

	__queue_node* (*pop)			   (__queue_head*);
	__queue_node* (*pop_until_success) (__queue_head*);
	void		  (*pop_bounded)	   (__queue_head*, __queue_node**, crisp_u64);
}	__queue_controller;

typedef struct
	__dynamic_queue_controller {
	void	   (*push)			    (__dynamic_queue_head*, void*, crisp_u64);
	void	   (*push_until_success)(__dynamic_queue_head*, void*, crisp_u64);
	void	   (*push_bounded)	    (__dynamic_queue_head*, void*, crisp_u64);

	crisp_bool (*pop)			    (__dynamic_queue_head*);
	void	   (*pop_until_success) (__dynamic_queue_head*);
	void	   (*pop_bounded)	    (__dynamic_queue_head*, crisp_u64);

	void*	   (*peek)				(__dynamic_queue_head*);
}	__dynamic_queue_controller;

