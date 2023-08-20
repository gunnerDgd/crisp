#ifndef CRISP_STR_H
#define CRISP_STR_H

#include <crisp/alloc.h>

typedef struct
	c_str_t { c_u64_t handle[6]; }
		c_str_t;

c_bool_t
	c_str_init
		(c_str_t*, c_alloc_t*);

c_bool_t
	c_str_init_as_clone
		(c_str_t*, c_str_t*);

c_bool_t
	c_str_deinit
		(c_str_t*);

void
	c_str_reserve_back
		(c_str_t*, c_u64_t);

void
	c_str_reserve_front
		(c_str_t*, c_u64_t);

void
	c_str_push_back
		(c_str_t*, c_str_t*);

void
	c_str_push_back_cstr
		(c_str_t*, const char*);

void
	c_str_push_front
		(c_str_t*, c_str_t*);

void
	c_str_push_front_cstr
		(c_str_t*, const char*);

void
	c_str_push_at
		(c_str_t*, c_u64_t, c_str_t*);

void
	c_str_push_at_cstr
		(c_str_t*, c_u64_t, const char*);

c_u64_t
	c_str_find
		(c_str_t*, c_u64_t, c_str_t*);

c_u64_t
	c_str_find_ptr
		(c_str_t*, c_u64_t, const char*);

c_bool_t
	c_str_eq
		(c_str_t*, c_str_t*);

c_bool_t
	c_str_gt
		(c_str_t*, c_str_t*);

c_bool_t
	c_str_lt
		(c_str_t*, c_str_t*);

const char*
	c_str_ptr
		(c_str_t*);

c_u64_t
	c_str_len
		(c_str_t*);

#endif