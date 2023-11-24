#include "ptr.h"
#include "details/ptr.h"
#include "details/mem.h"

ptr 
	ptr_null() {
		ptr    ret = { .ptr = { 0, 0 } };
		return ret;
}

bool_t
	ptr_same
		(ptr par, ptr par_cmp) {
			return par.ptr[0] == par_cmp.ptr[0] && par.ptr[1] == par_cmp.ptr[1];
}

ptr
	ptr_seek
		(ptr par, i64_t par_off)							 {
			if (null(par))					return ptr_null();
			if (!((__ptr*)&par)->mem)		return ptr_null();
			if (!__ptr_seek(&par, par_off)) return ptr_null();
			return par;
}

void* 
	ptr_raw 
		(ptr par)							  { 
			if (null(par))			  return 0;
			if (!((__ptr*)&par)->mem) return 0;
			return ((__ptr*)&par)->mem->ptr + ((__ptr*)&par)->cur; 
}
void* 
	ptr_mem 
		(ptr par)							  {
			if (null(par))			  return 0;
			if (!((__ptr*)&par)->mem) return 0;
			return ((__ptr*)&par)->mem; 
}

u64_t 
	ptr_size
		(ptr par)							  { 
			if (null(par))			  return 0;
			if (!((__ptr*)&par)->mem) return 0;
			return ((__ptr*)&par)->mem->size - ((__ptr*)&par)->cur; 
}

u64_t 
	ptr_cur 
		(ptr par)							  { 
			if (null(par))			  return 0;
			if (!((__ptr*)&par)->mem) return 0;
			return ((__ptr*)&par)->cur; 
}

u64_t
	ptr_dist
		(ptr par, ptr par_cmp)						   {
			if (ptr_same(par, ptr_null()))	   return 0;
			if (ptr_same(par_cmp, ptr_null())) return 0;

			u8_t* ptr = ptr_raw(par), *ptr_cmp = ptr_raw(par_cmp);
			return (ptr < ptr_cmp) 
				 ? (ptr_cmp - ptr) 
				 : (ptr - ptr_cmp);
}

ptr
	ptr_rd8
		(ptr par_ptr, u8_t* par_buf)						    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr					      ;
			if   (!ptr->mem)			 return ptr_null();
			if   (ptr_size(par_ptr) < 1) return ptr_null();

			if (!ptr->mem->trait->rd8(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur += 1 ;
			return par_ptr;
}

ptr
	ptr_rd16
		(ptr par_ptr, u16_t* par_buf)							{
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr							    ;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < 2)	   return ptr_null();

			if (!ptr->mem->trait->rd16(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur += 2 ;
			return par_ptr;
}

ptr
	ptr_rd32
		(ptr par_ptr, u32_t* par_buf)						    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr								;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < 4)	   return ptr_null();

			if (!ptr->mem->trait->rd32(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur += 4 ;
			return par_ptr;
}

ptr
	ptr_rd64
		(ptr par_ptr, u64_t* par_buf)						    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr								;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < 8)	   return ptr_null();

			if (!ptr->mem->trait->rd64(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur +=  8;
			return par_ptr;
}

ptr
	ptr_read
		(ptr par_ptr, void* par_buf, u64_t par_len)			    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr							    ;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < par_len) return ptr_null();

			u64_t ret = ptr->mem->trait->copy (par_buf, ptr->mem->ptr + ptr->cur, par_len);
			if  (!ret) return ptr_null();

			ptr->cur += ret;
			return par_ptr ;
}

ptr
	ptr_wr8
		(ptr par_ptr, u8_t par_buf)							    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr							    ;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < 1)	   return ptr_null();

			if (!ptr->mem->trait->wr8(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur  += 1;
			return par_ptr;
}

ptr
	ptr_wr16
		(ptr par_ptr, u16_t par_buf)						    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr							    ;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < 2)	   return ptr_null();

			if (!ptr->mem->trait->wr16(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur  += 2;
			return par_ptr;
}

ptr
	ptr_wr32
		(ptr par_ptr, u32_t par_buf)						    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr							    ;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < 4)	   return ptr_null();

			if (!ptr->mem->trait->wr32(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur  += 1;
			return par_ptr;
}

ptr
	ptr_wr64
		(ptr par_ptr, u64_t par_buf)							{
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr							    ;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < 8)	   return ptr_null();

			if (!ptr->mem->trait->wr64(ptr->mem->ptr + ptr->cur, par_buf))
				return ptr_null();

			ptr->cur  += 8;
			return par_ptr;
}

ptr
	ptr_write
		(ptr par_ptr, void* par_buf, u64_t par_len)			    {
			if (ptr_same(par_ptr, ptr_null())) return ptr_null();
			__ptr* ptr = &par_ptr					            ;
			if   (!ptr->mem)				   return ptr_null();
			if   (ptr_size(par_ptr) < par_len) return ptr_null();

			u64_t ret = ptr->mem->trait->copy(ptr->mem->ptr + ptr->cur, par_buf, par_len);
			if  (!ret) return ptr_null();

			ptr->cur += ret;
			return  par_ptr;
}

u64_t
	ptr_set_as
		(ptr par_ptr, u8_t par_op, u64_t par_len)     {
			if(ptr_same(par_ptr, ptr_null())) return 0;
			if(ptr_size(par_ptr) < par_len)   return 0;

			return ((__ptr*)&par_ptr)->mem->trait->set_as (
				ptr_raw(par_ptr),
				par_op			,
				par_len
			);
}

u64_t
	ptr_copy
		(ptr par_ptr, ptr par_ptr_op, u64_t par_len)	  {
			if (ptr_same(par_ptr   , ptr_null())) return 0;
			if (ptr_same(par_ptr_op, ptr_null())) return 0;
			if (ptr_size(par_ptr) < par_len)	  return 0;
			if (ptr_size(par_ptr) < par_len)	  return 0;

			return ((__ptr*)&par_ptr)->mem->trait->copy (
				ptr_raw(par_ptr)   ,
				ptr_raw(par_ptr_op),
				par_len
			);
}

u64_t
	ptr_move
		(ptr par_ptr, ptr par_ptr_op, u64_t par_len)	  {
			if (ptr_same(par_ptr   , ptr_null())) return 0;
			if (ptr_same(par_ptr_op, ptr_null())) return 0;
			if (ptr_size(par_ptr) < par_len)	  return 0;
			if (ptr_size(par_ptr) < par_len)	  return 0;

			return ((__ptr*)&par_ptr)->mem->trait->move (
				ptr_raw(par_ptr)   ,
				ptr_raw(par_ptr_op),
				par_len
			);
}

ptr
	ptr_find
		(ptr par, void* par_cmp, u64_t par_len)			    {
			if(ptr_same(par, ptr_null()))  return ptr_null();
			if(!par_cmp)				   return ptr_null();
			if(ptr_size(par) < par_len)    return ptr_null();

			for (u64_t off = 0 ; off < ptr_size(par) - par_len ; ++off) {
				ptr off_ptr = ptr_seek(par, off);
				if (ptr_eq(off_ptr, par_cmp, par_len))
					return off_ptr;
			}

			return ptr_null();
}

bool_t
	ptr_eq
		(ptr par, void* par_op, u64_t par_len)	         {
			if (ptr_same(par, ptr_null())) return false_t;
			if (ptr_size(par) < par_len)   return false_t;
			if (ptr_size(par) < par_len)   return false_t;

			__ptr* ptr = &par		   ;
			return ptr->mem->trait->eq (
				   ptr_raw(par),
				   par_op      ,
				   par_len
			);
}

bool_t
	ptr_gt
		(ptr par, void* par_op, u64_t par_len)	       {
			if (ptr_size(par) < par_len) return false_t;
			if (ptr_size(par) < par_len) return false_t;

			__ptr* ptr = &par		   ;
			return ptr->mem->trait->gt (
				   ptr_raw(par),
				   par_op      ,
				   par_len
			);
}

bool_t
	ptr_lt
		(ptr par, void* par_op, u64_t par_len)	       {
			if (ptr_size(par) < par_len) return false_t;
			if (ptr_size(par) < par_len) return false_t;

			__ptr* ptr = &par		   ;
			return ptr->mem->trait->lt (
				   ptr_raw(par),
				   par_op      ,
				   par_len
			);
}