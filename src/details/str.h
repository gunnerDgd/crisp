#ifndef __DETAILS_STR_H__
#define __DETAILS_STR_H__

#include "../mem.h"
#include "../obj.h"

extern obj_trait __str_trait;
typedef struct	   __str      {
	obj	     head		;
	mem_res *res		;
	u8_t	*mem		;
	u64_t	 front, back;
	u64_t    size , len ;
}	__str;

bool_t __str_new  (__str*, u32_t, va_list);
bool_t __str_clone(__str*, __str*)        ;
void   __str_del  (__str*)		          ;

void   __str_rsv_back (__str*, u64_t);
void   __str_rsv_front(__str*, u64_t);

void __str_push_back (__str*, __str*)		;
void __str_push_front(__str*, __str*)		;
void __str_push_at	 (__str*, u64_t, __str*);

void __str_pop_front (__str*, u64_t)	   ;
void __str_pop_back	 (__str*, u64_t)	   ;
void __str_pop_at	 (__str*, u64_t, u64_t);

u64_t  __str_find(__str*, u64_t, __str*);
bool_t __str_eq  (__str*, __str*)	    ;
bool_t __str_gt  (__str*, __str*)		;
bool_t __str_lt  (__str*, __str*)		;

bool_t __str_starts(__str*, __str*);
bool_t __str_ends  (__str*, __str*);

void __str_push_back_cstr (__str*, const char*, u64_t)		 ;
void __str_push_front_cstr(__str*, const char*, u64_t)		 ;
void __str_push_at_cstr	  (__str*, u64_t, const char*, u64_t);

u64_t  __str_find_cstr(__str*, u64_t, const char*, u64_t);
bool_t __str_eq_cstr  (__str*, const char*, u64_t)		 ;
bool_t __str_gt_cstr  (__str*, const char*, u64_t)		 ;
bool_t __str_lt_cstr  (__str*, const char*, u64_t)		 ;

bool_t __str_starts_cstr(__str*, const char*, u64_t);
bool_t __str_ends_cstr  (__str*, const char*, u64_t);

bool_t __str_empty(__str*);
u64_t  __str_len  (__str*);

#endif