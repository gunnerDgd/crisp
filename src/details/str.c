#include "str.h"

#include <stdlib.h>
#include <string.h>

bool_t
	__str_init(__str* par_str, __alloc* par_str_alloc) {
		par_str->alloc     = par_str_alloc;
		par_str->alloc_mem = __mem_init(par_str->alloc, 16); if (!par_str->alloc_mem) return false_t;
		
		par_str->off_back  = 0;
		par_str->off_front = 0;

		par_str->ptr       = __mem_ptr(par_str->alloc_mem);

		return true_t;
}

bool_t
	__str_init_as_clone(__str* par_str, __str* par_str_clone) {
		par_str->alloc     = par_str_clone->alloc;
		par_str->alloc_mem = __mem_init(par_str->alloc, par_str->alloc_mem->alloc_size); if (!par_str->alloc_mem) return false_t;
		par_str->ptr       = __mem_ptr (par_str->alloc_mem);

		memcpy(par_str->ptr, par_str_clone->ptr + par_str_clone->off_front, (par_str_clone->off_back - par_str_clone->off_front));
		 
		par_str->off_front = 0;
		par_str->off_back  = par_str_clone->off_back - par_str_clone->off_front;

		return true_t;
}

bool_t
	__str_deinit(__str* par_str) {
		__mem_deinit(par_str->alloc_mem);

		par_str->alloc	   = 0;
		par_str->alloc_mem = 0;

		par_str->off_back  = 0;
		par_str->off_front = 0;
		
		par_str->ptr       = 0;

		return true_t;
}

void
	__str_reserve_back(__str* par_str, u64_t par_rsv) {
		__mem *mem = par_str->alloc_mem,
			  *mem_new;
		
		par_rsv = (mem->alloc_size > par_rsv) ? (mem->alloc_size << 1) : (mem->alloc_size + par_rsv);
		mem_new = __mem_init(par_str->alloc, par_rsv);

		memcpy	    (mem_new->ptr, mem->ptr, mem->alloc_size);
		__mem_deinit(mem);
		
		par_str->alloc_mem = mem_new;
		par_str->ptr       = __mem_ptr(mem_new);
}

void
	__str_reserve_front(__str* par_str, u64_t par_rsv) {
		__mem *mem = par_str->alloc_mem,
			  *mem_new;
		
		par_str->off_front += par_rsv;
		par_rsv = (mem->alloc_size > par_rsv) ? (mem->alloc_size << 1) : (mem->alloc_size + par_rsv);

		mem_new = __mem_init(par_str->alloc, par_rsv);
		memcpy	    (mem_new->ptr + par_str->off_front, mem->ptr, mem->alloc_size);
		__mem_deinit(mem);

		par_str->alloc_mem = mem_new;
		par_str->ptr       = __mem_ptr(mem_new);
}

void
	__str_push_back(__str* par_str, __str* par_push) {
		__mem  *mem_str	     = par_str ->alloc_mem,
			   *mem_str_push = par_push->alloc_mem;

		u64_t len_str		 = par_str ->off_back - par_str ->off_front,
				len_str_push = par_push->off_back - par_push->off_front;

		if ((mem_str->alloc_size - par_str->off_back) > len_str_push) {
			memcpy(par_str->ptr + par_str->off_back, par_push->ptr + par_str->off_front, len_str_push);
			par_str->off_back += len_str_push;
			
			return;
		}

		__str_reserve_back(par_str, len_str_push);
		memcpy		    (par_str->ptr + par_str->off_front, par_push->ptr + par_push->off_front, len_str_push);

		par_str->off_back  = len_str + len_str_push;
}

void
	__str_push_back_cstr(__str* par_str, const char* par_cstr) {
		__mem  *mem_str		 = par_str->alloc_mem;
		u64_t   len_str	 	 = par_str->off_back - par_str->off_front,
				len_str_push = strlen(par_cstr);

		if ((mem_str->alloc_size - par_str->off_back) > len_str_push) {
			memcpy(par_str->ptr + par_str->off_back, par_cstr, len_str_push);
			par_str->off_back += len_str_push;

			return;
		}

		__str_reserve_back(par_str, len_str_push);
		memcpy		    (par_str->ptr + par_str->off_front, par_cstr, len_str_push);

		par_str->off_back  = len_str + len_str_push;
}

void
	__str_push_front(__str* par_str, __str* par_push) {
		__mem  *mem_str	     = par_str ->alloc_mem,
			   *mem_str_push = par_push->alloc_mem;

		u64_t   len_str		 = par_str ->off_back - par_str ->off_front,
				len_str_push = par_push->off_back - par_push->off_front;

		if (par_str->off_front < len_str_push) __str_reserve_front(par_str, len_str_push);

		par_str->off_front -= len_str_push;
		memcpy(par_str->ptr + par_str->off_front, par_push->ptr + par_push->off_front, len_str_push);
}

void
	__str_push_front_cstr(__str* par_str, const char* par_push) {
		__mem  *mem_str	     = par_str ->alloc_mem;
		u64_t   len_str		 = par_str ->off_back - par_str ->off_front,
				len_str_push = strlen(par_push);

		if (par_str->off_front < len_str_push) __str_reserve_front(par_str, len_str_push);

		par_str->off_front -= len_str_push;
		memcpy(par_str->ptr + par_str->off_front, par_push, len_str_push);
}

void
	__str_push_at(__str* par_str, u64_t par_off, __str* par_push) {
		__mem  *mem_str = par_str->alloc_mem,
			   *mem;

		u64_t   len		 = (par_str ->off_back - par_str ->off_front),
			    len_push = (par_push->off_back - par_push->off_front);

		mem = __mem_init(par_str->alloc, len + len_push); if (!mem) return;
		par_str->off_back = 0;
		
		memcpy(mem->ptr					   , par_str ->ptr + par_str ->off_front, par_off)					; par_str->off_back += par_off;
		memcpy(mem->ptr + par_str->off_back, par_push->ptr + par_push->off_front, len_push)					; par_str->off_back += len_push;
		memcpy(mem->ptr + par_str->off_back, par_str ->ptr + par_str ->off_front + par_off, (len - par_off)); par_str->off_back += (len - par_off);

		__mem_deinit(mem);
}

void
	__str_push_at_cstr(__str* par_str, u64_t par_off, const char* par_push) {
		__mem  *mem_str = par_str->alloc_mem,
			   *mem;

		u64_t   len		 = (par_str ->off_back - par_str ->off_front),
			    len_push = strlen(par_push);

		mem = __mem_init(par_str->alloc, len + len_push); if (!mem) return;
		par_str->off_back = 0;
		
		memcpy(mem->ptr,  par_str->ptr + par_str ->off_front, par_off)										; par_str->off_back += par_off;
		memcpy(mem->ptr + par_str->off_back, par_push							, len_push)					; par_str->off_back += len_push;
		memcpy(mem->ptr + par_str->off_back, par_str ->ptr + par_str ->off_front + par_off, (len - par_off)); par_str->off_back += (len - par_off);

		__mem_deinit(mem);
}

u64_t
	__str_find(__str* par_str, u64_t par_off, __str* par_find) {
		u64_t len	   = (par_str ->off_back - par_str ->off_front),
			  len_find = (par_find->off_back - par_find->off_front);

		if (len < len_find) return -1;
		
		char* ptr_find = par_str->ptr + par_str->off_front;
		for(u64_t it = 0 ; it < (len - len_find) ; ++it)
			if (strncmp(ptr_find, par_find->ptr, len_find) == 0) return it;
		return -1;
}

u64_t
	__str_find_from_cstr(__str* par_str, u64_t par_off, const char* par_find) {
		u64_t len	   = (par_str ->off_back - par_str ->off_front),
			  len_find = strlen(par_find);

		if (len < len_find) return -1;
		
		char* ptr_find = par_str->ptr + par_str->off_front;
		for(u64_t it = 0 ; it < (len - len_find) ; ++it)
			if (strncmp(ptr_find, par_find, len_find) == 0) return it;
		return -1;
}

bool_t
	__str_eq(__str *par_lhs, __str* par_rhs) {
		u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
				len_rhs = (par_rhs->off_back - par_rhs->off_front);

		return (len_lhs != len_rhs) ? false_t : (strncmp(par_lhs->ptr, par_rhs->ptr, len_lhs) == 0);
}

bool_t
	__str_eq_from_cstr(__str *par_lhs, const char* par_rhs) {
		u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
			  len_rhs = strlen(par_rhs);

		return (len_lhs != len_rhs) ? false_t : (strncmp(par_lhs->ptr, par_rhs, len_lhs) == 0);
}

bool_t
	__str_gt(__str *par_lhs, __str* par_rhs) {
		u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
			  len_rhs = (par_rhs->off_back - par_rhs->off_front);
		int         res = strncmp(par_lhs->ptr, par_rhs->ptr, (len_lhs > len_rhs) ? len_lhs : len_rhs);

		return (res) ? (res > 0) : (len_lhs > len_rhs);
}

bool_t
	__str_gt_from_cstr(__str *par_lhs, const char* par_rhs) {
		u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
			  len_rhs = strlen(par_rhs)						    ;
		int       res = strncmp(par_lhs->ptr, par_rhs, (len_lhs > len_rhs) ? len_lhs : len_rhs);

		return (res) ? (res > 0) : (len_lhs > len_rhs);
}

bool_t
	__str_lt(__str *par_lhs, __str* par_rhs) {
		u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
			  len_rhs = (par_rhs->off_back - par_rhs->off_front);
		int       res = strncmp(par_lhs->ptr, par_rhs->ptr, (len_lhs > len_rhs) ? len_lhs : len_rhs);

		return (res) ? (res < 0) : (len_lhs < len_rhs);
}

bool_t
	__str_lt_from_cstr(__str *par_lhs, const char* par_rhs) {
		u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
			  len_rhs = strlen(par_rhs)						    ;
		int       res = strncmp(par_lhs->ptr, par_rhs, (len_lhs > len_rhs) ? len_lhs : len_rhs);

		return (res) ? (res < 0) : (len_lhs < len_rhs);
}