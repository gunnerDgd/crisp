#ifndef CRISP_DETAILS_STR_H
#define CRISP_DETAILS_STR_H

#include <crisp/details/mem.h>
#include <crisp/details/alloc.h>

typedef struct str_t {
	alloc_t *alloc	  ;
	mem_t	*alloc_mem;

	c_u64_t  off_front, off_back;
	char*    ptr;
}	str_t;

c_bool_t
	str_init
		(str_t*, alloc_t*);

c_bool_t
	str_init_as_clone
		(str_t*, str_t*);

c_bool_t
	str_deinit
		(str_t*);

void
	str_reserve_back
		(str_t*, c_u64_t);

void
	str_reserve_front
		(str_t*, c_u64_t);

void
	str_push_back
		(str_t*, str_t*);

void
	str_push_back_cstr
		(str_t*, const char*);

void
	str_push_front
		(str_t*, str_t*);

void
	str_push_front_cstr
		(str_t*, const char*);

void
	str_push_at
		(str_t*, c_u64_t, str_t*);

void
	str_push_at_cstr
		(str_t*, c_u64_t, const char*);

c_u64_t
	str_find
		(str_t*, c_u64_t, str_t*);

c_u64_t
	str_find_cstr
		(str_t*, c_u64_t, const char*);

c_bool_t
	str_eq
		(str_t*, str_t*);

c_bool_t
	str_gt
		(str_t*, str_t*);

c_bool_t
	str_lt
		(str_t*, str_t*);

#endif