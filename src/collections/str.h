#ifndef __STR_H__
#define __STR_H__

#include "seq.h"

extern struct obj_trait* str_t;
typedef struct	         str  {
	obj	head;
	seq str ;
}	str;

bool_t      str_new			   (str*, u32_t, va_list);
bool_t      str_clone		   (str*, str*)          ;
void        str_del			   (str*)		         ;

void	    str_prep_front	   (str*, u64_t);
void        str_prep_back	   (str*, u64_t);

void        str_push_back	   (str*, str*)		  ;
void        str_push_front	   (str*, str*)		  ;
void        str_push		   (str*, str*, u64_t);

void        str_push_front_cstr(str*, const char*, u64_t)		;
void        str_push_back_cstr (str*, const char*, u64_t)		;
void        str_push_cstr	   (str*, const char*, u64_t, u64_t);

void        str_pop_front	   (str*, u64_t)       ;
void        str_pop_back	   (str*, u64_t)	   ;
void        str_pop		       (str*, u64_t, u64_t);

u64_t       str_find		   (str*, u64_t, str*)              ;
u64_t       str_find_cstr	   (str*, u64_t, const char*, u64_t);

bool_t      str_eq		       (str*, str*)  ;
bool_t      str_gt		       (str*, str*)  ;
bool_t      str_lt		       (str*, str*)  ;

bool_t      str_eq_cstr	       (str*, const char*, u64_t);
bool_t      str_gt_cstr	       (str*, const char*, u64_t);
bool_t      str_lt_cstr        (str*, const char*, u64_t);

bool_t      str_begin	       (str*, str*);
bool_t	    str_end		       (str*, str*);

bool_t      str_begin_cstr     (str*, const char*, u64_t);
bool_t	    str_end_cstr       (str*, const char*, u64_t);

bool_t      str_empty          (str*);
u64_t       str_len            (str*);
const char* str_ptr            (str*);

#endif