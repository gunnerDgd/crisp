#include "str.h"

obj_trait __str_trait     = {
	.on_new	  = &__str_new	,
	.on_clone = &__str_clone,
	.on_ref   =			   0,
	.on_del   = &__str_del  ,
	.size	  = sizeof(__str)
};

bool_t
	__str_new
		(__str* par_str, u32_t par_count, va_list par) {
			par_str->res = (par_count == 0) ? get_mem_res() : va_arg(par, mem_res*);
			if (!par_str->res) return false_t;
			
			par_str->mem = mem_new(par_str->res, 16);
			if (!par_str->mem) return false_t;
		
			mem_set(par_str->mem, 0x00, 16);
			par_str->front = 0 ;
			par_str->back  = 0 ;
			par_str->size  = 16;
			par_str->len   = 0 ;

			return true_t;
}

bool_t
	__str_clone
		(__str* par, __str* par_clone)		    {
			if (!par_clone->res)  return false_t;
			if (!par_clone->mem)  return false_t;
			if (!par_clone->size) return false_t;

			par->res  = par_clone->res;
			par->size = par_clone->size;
			par->mem  = mem_new(par->res, par->size);

			mem_copy(par->mem, par_clone->mem, par->size);
			par->len   = par_clone->len  ;
			par->front = par_clone->front;
			par->back  = par_clone->back ;
			return true_t;
}

void
	__str_del
		(__str* par)				   {
			mem_del(par->res, par->mem);
}

void
	__str_rsv_back
		(__str* par, u64_t par_rsv)				        {
			u64_t rsv_size = par->size << 1		        ; if (rsv_size < par_rsv) rsv_size = par_rsv + par->size;
			u8_t* rsv	   = mem_new(par->res, rsv_size);
			if  (!rsv) return;

			mem_set (rsv, 0x00, rsv_size)							   ;
			mem_copy(rsv + par->front, par->mem + par->front, par->len);
			mem_del								 (par->res  , par->mem);

			par->mem  = rsv		;
			par->size = rsv_size;
}

void
	__str_rsv_front
		(__str* par, u64_t par_rsv)				        {
			u64_t rsv_size = par->size << 1			    ; if (rsv_size < par_rsv) rsv_size = par_rsv + par->size;
			u8_t* rsv	   = mem_new(par->res, rsv_size);

			mem_copy(rsv + par->front + par_rsv, par->mem + par->front, par->len);
			mem_del										   (par->res  , par->mem);

			par->mem    = rsv	  ;
			par->size   = rsv_size;
			par->front += par_rsv ;
			par->back  += par_rsv ;
}

void
	__str_push_back
		(__str* par, __str* par_push)		   {
			__str_push_back_cstr			   (
				par							   ,
				par_push->mem + par_push->front, 
				par_push->len
			);
}

void
	__str_push_back_cstr
		(__str* par, const char* par_push, u64_t par_len) {
			if((par->back + par_len + 1) > par->size)
				__str_rsv_back(par, par_len + 1);

			mem_copy(par->mem + par->back, par_push, par_len);
			par->back += par_len;
			par->len  += par_len;
}

void
	__str_push_front
		(__str* par, __str* par_push)	  {
			__str_push_front_cstr		  (
				par						  ,
				par->mem + par_push->front,
				par_push->len
			);
}

void
	__str_push_front_cstr
		(__str* par, const char* par_push, u64_t par_len) {
			if((par->back + par_len) > par->size)
				__str_rsv_back(par, par_len);

			par->front -= par_len;
			par->len   += par_len;
			mem_copy(par->mem + par->front, par_push, par_len);
}

void
	__str_push_at
		(__str* par, u64_t par_off, __str* par_push) {
			__str_push_at_cstr				   (
				par							   ,
				par_off						   ,
				par_push->mem + par_push->front, 
				par_push->len
			);
}

void
	__str_push_at_cstr
		(__str* par, u64_t par_off, const char* par_push, u64_t par_len) {
			if (par_off > par->len)							{
				__str_push_back_cstr(par, par_push, par_len);
				return;
			}

			if (par_off == 0)								 {
				__str_push_front_cstr(par, par_push, par_len);
				return;
			}

			u64_t ret_off = par->front;
			u8_t* ret	  = mem_new(par->res, par_len + par->size + 1); if (!ret) return;

			par->size = par_len + par->size + 1;
			mem_set (ret		  , 0x00						   , par->size)			   ;
			mem_copy(ret + ret_off, par->mem + ret_off			   , par_off)			   ; ret_off += par_off;
			mem_copy(ret + ret_off, par_push					   , par_len)			   ; ret_off += par_len;
			mem_copy(ret + ret_off, par->mem + par->front + par_off, (par->back - par_off));

			par->back += par_len;
			par->len  += par_len; mem_del(par->res, par->mem);
			par->mem   = ret	;
			
}

void 
	__str_pop_front
		(__str* par, u64_t par_len)							 {
			par->front = ((par->front + par_len) > par->back)
					   ?  (par->front + par_len)
					   :   par->back;

			par->len -= (par->back - par->front);
}

void 
	__str_pop_back
		(__str* par, u64_t par_len) {
			par->back = ((par_len > par->len))
					  ?  (par->back - par_len)
					  :   par->front;

			par->len -= par_len;
}

void 
	__str_pop_at
		(__str* par, u64_t par_off, u64_t par_len) {
			if(par_off > par->len)		    {
				__str_pop_back(par, par_len);
				return;
			}

			if (par_off == 0)				 {
				__str_pop_front(par, par_len);
				return;
			}

			if ((par_off + par_len) > par->len)
				return;

			mem_copy									 (
				par->mem + par->front + par_off			 , 
				par->mem + par->front + par_off + par_len,
				par->len - par_off - par_len
			);

			par->len  -= par_len;
			par->back -= par_len;
			mem_set(par->mem + par->back, 0x00, par->len - par->back);
}

u64_t
	__str_find
		(__str* par, u64_t par_off, __str* par_find) {
			return __str_find_cstr			   (
				par							   ,
				par_off						   ,
				par_find->mem + par_find->front, 
				par_find->len
			);
}

u64_t
	__str_find_cstr
		(__str* par, u64_t par_off, const char* par_find, u64_t par_len) {
			return mem_find					   (
				par->mem + par->front + par_off,
				par_find					   ,
				par->len - par_off			   ,
				par_len
			);
}

bool_t 
	__str_eq_cstr
		(__str *par, const char* par_cmp, u64_t par_len) { 
			return mem_eq			 (
				par->mem + par->front, 
				par_cmp				 ,
				par_len
			); 
}

bool_t 
	__str_gt_cstr
		(__str* par, const char* par_cmp, u64_t par_len) { 
			return mem_gt			 (
				par->mem + par->front, 
				par_cmp,
				par_len
			); 
}

bool_t 
	__str_lt_cstr
		(__str* par, const char* par_cmp, u64_t par_len) { 
			return mem_lt			 (
				par->mem + par->front, 
				par_cmp				 , 
				par_len
			); 
}

bool_t 
	__str_eq
		(__str * par, __str* par_cmp)		 { 
			return __str_eq_cstr		     (
				par							 ,
				par_cmp->mem + par_cmp->front,
				par_cmp->len); 
}

bool_t 
	__str_gt
		(__str * par, __str* par_cmp)		 { 
			return __str_gt_cstr		     (
				par							 ,
				par_cmp->mem + par_cmp->front,
				par_cmp->len); 
}

bool_t 
	__str_lt
		(__str * par, __str* par_cmp)		 { 
			return __str_lt_cstr		     (
				par							 ,
				par_cmp->mem + par_cmp->front,
				par_cmp->len); 
}

bool_t 
	__str_starts
		(__str* par, __str* par_cmp)		 { 
			return __str_starts_cstr		 (
				par							 ,
				par_cmp->mem + par_cmp->front, 
				par_cmp->len
			);
}


bool_t 
	__str_starts_cstr
		(__str* par, const char* par_cmp, u64_t par_len) {
			if(par_len > par->len)
				return false_t;

			return mem_eq			 (
				par->mem + par->front, 
				par_cmp				 ,
				par_len
			);
}

bool_t 
	__str_ends_cstr
		(__str* par, const char* par_cmp, u64_t par_len) {
			if(par_len > par->len) 
				return false_t;

			return mem_eq					  (
				par->mem + par->back - par_len, 
				par_cmp						  ,
				par_len
			);
}

bool_t 
	__str_ends
		(__str* par, __str* par_cmp)		 {
			return __str_ends_cstr			 (
				par							 ,
				par_cmp->mem + par_cmp->front, 
				par_cmp->len
			);
}


bool_t __str_empty(__str* par) { return par->front == par->back; }
u64_t  __str_len  (__str* par) { return par->len; }