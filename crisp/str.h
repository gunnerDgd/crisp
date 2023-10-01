#ifndef __STR_H__
#define __STR_H__

#include "alloc.h"

typedef struct
	str { u64_t handle[6]; }
		str;

bool_t
	str_init
		(str*, alloc*);

bool_t
	str_init_as_clone
		(str*, str*);

bool_t
	str_deinit
		(str*);

void
	str_reserve_back
		(str*, u64_t);

void
	str_reserve_front
		(str*, u64_t);

void
	str_push_back
		(str*, str*);

void
	str_push_back_cstr
		(str*, const char*);

void
	str_push_front
		(str*, str*);

void
	str_push_front_cstr
		(str*, const char*);

void
	str_push_at
		(str*, u64_t, str*);

void
	str_push_at_cstr
		(str*, u64_t, const char*);

u64_t
	str_find
		(str*, u64_t, str*);

u64_t
	str_find_from_cstr
		(str*, u64_t, const char*);

bool_t
	str_eq
		(str*, str*);

bool_t
	str_gt
		(str*, str*);

bool_t
	str_lt
		(str*, str*);

const char*
	str_ptr
		(str*);

u64_t
	str_len
		(str*);

#endif