#include "str.h"

obj_trait __str_trait				   = {
	.init		   = &__str_init		 ,
	.init_as_clone = &__str_init_as_clone,
	.init_as_ref   =					0,
	.deinit		   = &__str_deinit		 ,
	.name		   =					0,
	.size		   = &__str_size
};

bool_t
	__str_init
		(__str* par_str, u32_t par_count, va_list par) {
			alloc* par_alloc  = (par_count == 0) ? get_alloc() : va_arg(par, alloc*);
			if   (!par_alloc)
				return false_t;
			
			par_str->alloc = par_alloc;
			par_str->mem   = mem_init(par_str->alloc, 16); 
			if (!par_str->mem)
				return false_t;
		
			par_str->front = mem_ptr(par_str->mem, 0);
			par_str->back  = mem_ptr(par_str->mem, 0);
			par_str->len   = 0;

			return true_t;
}

bool_t
	__str_init_as_clone
		(__str* par, __str* par_clone)						{
			par->alloc = par_clone->alloc					;
			par->mem   = mem_init_as_clone(par_clone->alloc);
			if (!par->mem) 
				return false_t;

			par->front = par_clone->front;
			par->back  = par_clone->back ;
			par->len   = par_clone->len  ;

			return true_t;
}

void
	__str_deinit
		(__str* par_str)			{
			mem_deinit(par_str->mem);
			return true_t;
}

u64_t
	__str_size() {
		return sizeof(__str);
}

void
	__str_rsv_back
		(__str* par, u64_t par_rsv)			   {
			u64_t rsv_off = ptr_cur(par->front);
			mem   rsv_mem					   ;
			u64_t rsv = mem_size(par->mem) << 1;
			if (rsv < par_rsv)
				rsv = par_rsv + mem_size(par->mem);

			rsv_mem = mem_init(par->alloc, rsv + 1);
			if(!ptr_copy(mem_ptr(rsv_mem, rsv_off), par->front, par->len)) {
				mem_deinit(rsv_mem);
				return;
			}

			mem_deinit(par->mem);
			par->mem   = rsv_mem					   ;
			par->front = mem_ptr (par->mem, rsv_off)   ;
			par->back  = ptr_seek(par->front, par->len);
}

void
	__str_rsv_front
		(__str* par, u64_t par_rsv)						 {
			u64_t rsv_off = par_rsv + ptr_cur(par->front);
			u64_t rsv	  = mem_size(par->mem) << 1		 ;
			mem   rsv_mem;

			if (rsv < par_rsv)
				rsv = par_rsv + mem_size(par->mem);

			rsv_mem = mem_init(par->alloc, rsv + 1);
			if(!ptr_copy(mem_ptr(rsv_mem, rsv_off), par->front, par->len)) {
				mem_deinit(rsv_mem);
				return;
			}

			mem_deinit(par->mem);
			par->mem   = rsv_mem					   ;
			par->front = mem_ptr (par->mem, rsv_off)   ;
			par->back  = ptr_seek(par->front, par->len);
}

void
	__str_push_back
		(__str* par, __str* par_push) {
			__str_push_back_cstr(par, ptr_raw(par_push->front), par_push->len);
}

void
	__str_push_back_cstr
		(__str* par, const char* par_push, u64_t par_len) {
			if((mem_size(par->mem) - ptr_cur(par->back) + 1) < par_len)
				__str_rsv_back(par, par_len);

			ptr_write(par->back, par_push, par_len);
			par->len += par_len;
			par->back = ptr_seek(par->back, par_len);

			ptr_wr8(par->back, 0x00);
}

void
	__str_push_front
		(__str* par, __str* par_push) {
			__str_push_front_cstr(par, ptr_raw(par_push->front), par_push->len);
}

void
	__str_push_front_cstr
		(__str* par, const char* par_push, u64_t par_len) {
			if((mem_size(par->mem) - ptr_cur(par->back) + 1) < par_len)
				__str_rsv_back(par, par_len);

			par->front = ptr_seek(par->front, (-1) * par_len); ptr_write(par->front, par_push, par_len);
			par->len  += par_len;

			ptr_wr8(par->back, 0x00);
}

void
	__str_push_at
		(__str* par, u64_t par_off, __str* par_push) {
			__str_push_at_cstr(par, par_off, ptr_raw(par_push->front), par_push->len);
}

void
	__str_push_at_cstr
		(__str* par, u64_t par_off, const char* par_push, u64_t par_len) {
			mem  ret = mem_init(par->alloc, mem_size(par->mem) + par_len);
			if (!ret)
				return;

			ptr off = ptr_seek(par->front, par_off),
				cur = mem_ptr (ret, 0);

			ptr_copy (cur, par->front, par_off); cur = ptr_seek(cur, par_off);
			ptr_write(cur, par_push, par_len)  ; cur = ptr_seek(cur, par_len);
			ptr_copy (cur, ptr_seek(par->front, par_off), par_len - par_off) ;

			mem_deinit(par->mem);
			par->len  += par_len						  ;
			par->mem   = ret						      ;
			par->front = mem_ptr(ret, 0)				  ;
			par->back  = mem_ptr(ret, par->len + par->len);
}

void 
	__str_pop_front
		(__str* par, u64_t par_len) {
			if ((ptr_dist(par->back, par->front) + 1) < par_len) {
				par->back = par->front;
				return;
			}

			par->front = ptr_seek(par->front, par_len);
}

void 
	__str_pop_back
		(__str* par, u64_t par_len) {
			if ((ptr_dist(par->back, par->front) + 1) < par_len) {
				par->back = par->front;
				return;
			}

			par->back = ptr_seek(par->back, (-1) * par_len);
			ptr_wr8(par->back, 0x00);
}

void 
	__str_pop_at
		(__str* par, u64_t par_off, u64_t par_len) {
			ptr begin = ptr_seek(par->front, par_off), end = ptr_seek(begin, par_len);
			ptr_copy(begin, end, (par->len - par_off - par_len));
			
			par->back = ptr_seek(par->back, (-1) * par_len);
			ptr_wr8(par->back, 0x00);
}

ptr
	__str_find
		(__str* par, u64_t par_off, __str* par_find) {
			return __str_find_from_cstr(par, par_off, ptr_raw(par_find->front), par_find->len);
}

ptr
	__str_find_from_cstr
		(__str* par, u64_t par_off, const char* par_find, u64_t par_len) {
			for (u64_t i = 0 ; i < (par->len - par_len) ; ++i)
				if (ptr_eq(ptr_seek(par->front, par_off + i), par_find, par_len))
					return ptr_seek(par->front, par_off + i);

			return ptr_null();
}

bool_t __str_eq			 (__str *par, __str* par_cmp)					  { return __str_eq_from_cstr(par, ptr_raw(par_cmp->front), par_cmp->len); }
bool_t __str_eq_from_cstr(__str *par, const char* par_cmp, u64_t par_len) { return ptr_eq(par->front, par_cmp, par_len); }

bool_t __str_gt			 (__str * par, __str* par_cmp)					  { return __str_gt_from_cstr(par, ptr_raw(par_cmp->front), par_cmp->len); }
bool_t __str_gt_from_cstr(__str *par, const char* par_cmp, u64_t par_len) { return ptr_gt(par->front, par_cmp, par_len); }

bool_t __str_lt			 (__str * par, __str* par_cmp)					   { return __str_lt_from_cstr(par, ptr_raw(par_cmp->front), par_cmp->len); }
bool_t __str_lt_from_cstr(__str * par, const char* par_cmp, u64_t par_len) { return ptr_lt(par->front, par_cmp, par_len); }

bool_t 
	__str_start_with
		(__str* par, __str* par_cmp) { 
			return __str_start_with_from_cstr(par, ptr_raw(par_cmp->front), par_cmp->len);
}


bool_t 
	__str_start_with_from_cstr
		(__str* par, const char* par_cmp, u64_t par_len) {
			return ptr_eq(par->front, par_cmp, par_len);
}
bool_t 
	__str_end_with
		(__str* par, __str* par_cmp) {
			return __str_end_with_from_cstr(par, ptr_raw(par_cmp->front), par_cmp->len);
}
bool_t 
	__str_end_with_from_cstr
		(__str* par, const char* par_cmp, u64_t par_len) {
			ptr cmp = ptr_seek(par->back, (-1) * par_len);
			return ptr_eq(cmp, par_cmp, par_len);
}

bool_t 
	__str_empty
		(__str* par) {
			return ptr_cur(par->front) == ptr_cur(par->back);
}