#include "str.h"

#include <stdlib.h>
#include <string.h>

c_bool_t
	str_init(str_t* par_str, alloc_t* par_str_alloc) {
		par_str->alloc     = par_str_alloc;
		par_str->alloc_mem = mem_init(par_str->alloc, 16); if (!par_str->alloc_mem) return false;
		
		par_str->off_back  = 0;
		par_str->off_front = 0;

		par_str->ptr       = mem_ptr(par_str->alloc_mem);

		return true;
}

c_bool_t
	str_init_as_clone(str_t* par_str, str_t* par_str_clone) {
		par_str->alloc     = par_str_clone->alloc;
		par_str->alloc_mem = mem_init(par_str->alloc, par_str->alloc_mem->handle.size); if (!par_str->alloc_mem) return false;
		par_str->ptr       = mem_ptr (par_str->alloc_mem);

		memcpy(par_str->ptr, par_str_clone->ptr + par_str_clone->off_front, (par_str_clone->off_back - par_str_clone->off_front));
		 
		par_str->off_front = 0;
		par_str->off_back  = par_str_clone->off_back - par_str_clone->off_front;

		return true;
}

c_bool_t
	str_deinit(str_t* par_str) {
		if(!mem_deinit(par_str->alloc_mem)) return false;

		par_str->alloc	   = 0;
		par_str->alloc_mem = 0;

		par_str->off_back  = 0;
		par_str->off_front = 0;
		
		par_str->ptr       = 0;

		return true;
}

void
	str_reserve_back(str_t* par_str, c_u64_t par_rsv) {
		mem_t *mem = par_str->alloc_mem,
			  *mem_new;
		
		par_rsv = (mem->handle.size > par_rsv) ? (mem->handle.size << 1) : (mem->handle.size + par_rsv);
		mem_new = mem_init(par_str->alloc, par_rsv);
		
		memcpy	  (mem_ptr(mem_new), mem_ptr(mem), mem->handle.size);
		mem_deinit(mem);
		
		par_str->alloc_mem = mem_new;
		par_str->ptr       = mem_ptr(mem_new);
}

void
	str_reserve_front(str_t* par_str, c_u64_t par_rsv) {
		mem_t *mem = par_str->alloc_mem,
			  *mem_new;
		
		par_str->off_front += par_rsv;
		par_rsv = (mem->handle.size > par_rsv) ? (mem->handle.size << 1) : (mem->handle.size + par_rsv);

		mem_new = mem_init(par_str->alloc, par_rsv);
		memcpy	  (mem_ptr(mem_new) + par_str->off_front, mem_ptr(mem), mem->handle.size);
		mem_deinit(mem);

		par_str->alloc_mem = mem_new;
		par_str->ptr       = mem_ptr(mem_new);
}

void
	str_push_back(str_t* par_str, str_t* par_push) {
		mem_t  *mem_str	     = par_str ->alloc_mem,
			   *mem_str_push = par_push->alloc_mem;

		c_u64_t len_str		 = par_str ->off_back - par_str ->off_front,
				len_str_push = par_push->off_back - par_push->off_front;

		if ((mem_str->handle.size - par_str->off_back) > len_str_push) {
			memcpy(par_str->ptr + par_str->off_back, par_push->ptr + par_str->off_front, len_str_push);
			par_str->off_back += len_str_push;
			
			return;
		}

		str_reserve_back(par_str, len_str_push);
		memcpy		    (par_str->ptr + par_str->off_front, par_push->ptr + par_push->off_front, len_str_push);

		par_str->off_back  = len_str + len_str_push;
}

void
	str_push_back_cstr(str_t* par_str, const char* par_cstr) {
		mem_t  *mem_str		 = par_str->alloc_mem;
		c_u64_t len_str	 	 = par_str->off_back - par_str->off_front,
				len_str_push = strlen(par_cstr);

		if ((mem_str->handle.size - par_str->off_back) > len_str_push) {
			memcpy(par_str->ptr + par_str->off_back, par_cstr, len_str_push);
			par_str->off_back += len_str_push;

			return;
		}

		str_reserve_back(par_str, len_str_push);
		memcpy		    (par_str->ptr + par_str->off_front, par_cstr, len_str_push);

		par_str->off_back  = len_str + len_str_push;
}

void
	str_push_front(str_t* par_str, str_t* par_push) {
		mem_t  *mem_str	     = par_str ->alloc_mem,
			   *mem_str_push = par_push->alloc_mem;

		c_u64_t len_str		 = par_str ->off_back - par_str ->off_front,
				len_str_push = par_push->off_back - par_push->off_front;

		if (par_str->off_front < len_str_push) str_reserve_front(par_str, len_str_push);

		par_str->off_front -= len_str_push;
		memcpy(par_str->ptr + par_str->off_front, par_push->ptr + par_push->off_front, len_str_push);
}

void
	str_push_front_cstr(str_t* par_str, const char* par_push) {
		
}

void
	str_push_at(str_t* par_str, c_u64_t par_off, str_t* par_push) {
		mem_t  *mem_str = par_str->alloc_mem,
			   *mem;

		c_u64_t len		 = (par_str ->off_back - par_str ->off_front),
			    len_push = (par_push->off_back - par_push->off_front);

		mem = mem_init(par_str->alloc, len + len_push); if (!mem) return;
		par_str->off_back = 0;
		
		memcpy(mem_ptr(mem)					   , par_str ->ptr + par_str ->off_front, par_off)					; par_str->off_back += par_off;
		memcpy(mem_ptr(mem) + par_str->off_back, par_push->ptr + par_push->off_front, len_push)					; par_str->off_back += len_push;
		memcpy(mem_ptr(mem) + par_str->off_back, par_str ->ptr + par_str ->off_front + par_off, (len - par_off)); par_str->off_back += (len - par_off);

		mem_deinit(mem);
}

void
	str_push_at_cstr(str_t* par_str, c_u64_t par_off, const char* par_push) {
		mem_t  *mem_str = par_str->alloc_mem,
			   *mem;

		c_u64_t len		 = (par_str ->off_back - par_str ->off_front),
			    len_push = strlen(par_push);

		mem = mem_init(par_str->alloc, len + len_push); if (!mem) return;
		par_str->off_back = 0;
		
		memcpy(mem_ptr(mem)					   , par_str ->ptr + par_str ->off_front, par_off)					; par_str->off_back += par_off;
		memcpy(mem_ptr(mem) + par_str->off_back, par_push							, len_push)					; par_str->off_back += len_push;
		memcpy(mem_ptr(mem) + par_str->off_back, par_str ->ptr + par_str ->off_front + par_off, (len - par_off)); par_str->off_back += (len - par_off);

		mem_deinit(mem);
}

c_u64_t
	str_find(str_t* par_str, c_u64_t par_off, str_t* par_find) {
		c_u64_t len		 = (par_str ->off_back - par_str ->off_front),
				len_find = (par_find->off_back - par_find->off_front);

		if (len < len_find) return -1;
		
		char* ptr_find = par_str->ptr + par_str->off_front;
		for(c_u64_t it = 0 ; it < (len - len_find) ; ++it)
			if (strncmp(ptr_find, par_find->ptr, len_find) == 0) return it;
		return -1;
}

c_u64_t
	str_find_cstr(str_t* par_str, c_u64_t par_off, const char* par_find) {
		c_u64_t len		 = (par_str ->off_back - par_str ->off_front),
				len_find = strlen(par_find);

		if (len < len_find) return -1;
		
		char* ptr_find = par_str->ptr + par_str->off_front;
		for(c_u64_t it = 0 ; it < (len - len_find) ; ++it)
			if (strncmp(ptr_find, par_find, len_find) == 0) return it;
		return -1;
}

c_bool_t
	str_eq(str_t *par_lhs, str_t* par_rhs) {
		c_u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
				len_rhs = (par_rhs->off_back - par_rhs->off_front);

		return (len_lhs != len_rhs) ? false : (strncmp(par_lhs->ptr, par_rhs->ptr, len_lhs) == 0);
}

c_bool_t
	str_gt(str_t *par_lhs, str_t* par_rhs) {
		c_u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
				len_rhs = (par_rhs->off_back - par_rhs->off_front);
		int         res = strncmp(par_lhs->ptr, par_rhs->ptr, max(len_lhs, len_rhs));

		return (res) ? (res > 0) : (len_lhs > len_rhs);
}

c_bool_t
	str_lt(str_t *par_lhs, str_t* par_rhs) {
		c_u64_t len_lhs = (par_lhs->off_back - par_lhs->off_front),
				len_rhs = (par_rhs->off_back - par_rhs->off_front);
		int         res = strncmp(par_lhs->ptr, par_rhs->ptr, max(len_lhs, len_rhs));

		return (res) ? (res < 0) : (len_lhs < len_rhs);
}