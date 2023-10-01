#include "str.h"

#include "details/alloc.h"
#include "details/str.h"

bool_t
	str_init(str* par_str, alloc* par_alloc) {
		return __str_init(par_str, par_alloc);
}

bool_t
	str_init_as_clone(str* par_str, str* par_str_clone) {
		return __str_init_as_clone(par_str, par_str_clone);
}

bool_t
	str_deinit(str* par_str) {
		return __str_deinit(par_str);
}

void
	str_reserve_back(str* par_str, u64_t par_size) {
		__str_reserve_back(par_str, par_size);
}

void
	str_reserve_front(str* par_str, u64_t par_size) {
		__str_reserve_front(par_str, par_size);
}

void
	str_push_back(str* par_str, str* par_size) {
		__str_push_back(par_str, par_size);
}

void
	str_push_back_cstr(str* par_str, const char* par_push) {
		__str_push_back_cstr(par_str, par_push);
}

void
	str_push_front(str* par_str, str* par_push) {
		__str_push_front(par_str, par_push);
}

void
	str_push_front_cstr(str* par_str, const char* par_push) {
		__str_push_front_cstr(par_str, par_push);
}

void
	str_push_at(str* par_str, u64_t par_off, str* par_push) {
		__str_push_at(par_str, par_off, par_push);
}

void
	str_push_at_cstr(str* par_str, u64_t par_off, const char* par_push) {
		__str_push_at_cstr(par_str, par_off, par_push);
}

u64_t
	str_find(str* par_str, u64_t par_off, str* par_find) {
		return __str_find(par_str, par_off, par_find);
}

u64_t
	str_find_from_cstr(str* par_str, u64_t par_off, const char* par_find) {
		return __str_find_from_cstr(par_str, par_off, par_find);
}

bool_t
	str_eq(str* par_lhs, str* par_rhs) {
		return __str_eq(par_lhs, par_rhs);
}

bool_t
	str_gt(str* par_lhs, str* par_rhs) {
		return __str_gt(par_lhs, par_rhs);
}

bool_t
	str_lt(str* par_lhs, str* par_rhs) {
		return __str_lt(par_lhs, par_rhs);
}

const char*
	str_ptr(str* par_str) {
		__str *str = par_str;
		return str->ptr + str->off_front;
}

u64_t
	str_len(str* par_str) {
		__str* str = par_str;
		return str->off_back - str->off_front;
}