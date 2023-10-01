#ifndef __DETAILS_STR_H__
#define __DETAILS_STR_H__

#include "mem.h"
#include "alloc.h"

typedef struct __str {
	__alloc *alloc	  ;
	__mem	*alloc_mem;

	u64_t    off_front, off_back;
	char*    ptr;
}	__str;

bool_t
	__str_init
		(__str*, __alloc*);

bool_t
	__str_init_as_clone
		(__str*, __str*);

bool_t
	__str_deinit
		(__str*);

void
	__str_reserve_back
		(__str*, u64_t);

void
	__str_reserve_front
		(__str*, u64_t);

void
	__str_push_back
		(__str*, __str*);

void
	__str_push_back_cstr
		(__str*, const char*);

void
	__str_push_front
		(__str*, __str*);

void
	__str_push_front_cstr
		(__str*, const char*);

void
	__str_push_at
		(__str*, u64_t, __str*);

void
	__str_push_at_cstr
		(__str*, u64_t, const char*);

u64_t
	__str_find
		(__str*, u64_t, __str*);

u64_t
	__str_find_from_cstr
		(__str*, u64_t, const char*);

bool_t
	__str_eq
		(__str*, __str*);

bool_t
	__str_eq_from_cstr
		(__str*, const char*);

bool_t
	__str_gt
		(__str*, __str*);

bool_t
	__str_gt_from_cstr
		(__str*, const char*);

bool_t
	__str_lt
		(__str*, __str*);

bool_t
	__str_lt_from_cstr
		(__str*, const char*);

#endif