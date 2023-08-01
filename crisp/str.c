#include "str.h"

#include "details/alloc.h"
#include "details/str.h"


c_bool_t
	c_str_init(c_str_t* par_str, c_alloc_t* par_alloc) {
		return str_init(par_str, par_alloc);
}

c_bool_t
	c_str_init_as_clone(c_str_t* par_str, c_str_t* par_str_clone) {
		return str_init_as_clone(par_str, par_str_clone);
}

c_bool_t
	c_str_deinit(c_str_t* par_str) {
		return str_deinit(par_str);
}

void
	c_str_reserve_back(c_str_t* par_str, c_u64_t par_size) {
		str_reserve_back(par_str, par_size);
}

void
	c_str_reserve_front(c_str_t* par_str, c_u64_t par_size) {
		str_reserve_front(par_str, par_size);
}

void
	c_str_push_back(c_str_t* par_str, c_str_t* par_size) {
		str_push_back(par_str, par_size);
}

void
	c_str_push_back_cstr(c_str_t* par_str, const char* par_push) {
		str_push_back_cstr(par_str, par_push);
}

void
	c_str_push_front(c_str_t* par_str, c_str_t* par_push) {
		str_push_front(par_str, par_push);
}

void
	c_str_push_front_cstr(c_str_t* par_str, const char* par_push) {
		str_push_front_cstr(par_str, par_push);
}

void
	c_str_push_at(c_str_t* par_str, c_u64_t par_off, c_str_t* par_push) {
		str_push_at(par_str, par_off, par_push);
}

void
	c_str_push_at_cstr(c_str_t* par_str, c_u64_t par_off, const char* par_push) {
		str_push_at_cstr(par_str, par_off, par_push);
}

c_u64_t
	c_str_find(c_str_t* par_str, c_u64_t par_off, c_str_t* par_find) {
		return str_find(par_str, par_off, par_find);
}

c_u64_t
	c_str_find_cstr(c_str_t* par_str, c_u64_t par_off, const char* par_find) {
		return str_find_cstr(par_str, par_off, par_find);
}

c_bool_t
	c_str_eq(c_str_t* par_lhs, c_str_t* par_rhs) {
		return str_eq(par_lhs, par_rhs);
}

c_bool_t
	c_str_gt(c_str_t* par_lhs, c_str_t* par_rhs) {
		return str_gt(par_lhs, par_rhs);
}

c_bool_t
	c_str_lt(c_str_t* par_lhs, c_str_t* par_rhs) {
		return str_lt(par_lhs, par_rhs);
}