#ifndef __STR_H__
#define __STR_H__

#include "obj.h"
#include "bit.h"

extern struct obj_trait* str_t;
typedef struct	         str  {
	obj	  head ;
	u64_t front, 
		  back ,
		  size ,
		  len  ;
	mem*  res  ;
	u8_t* mem  ;
}	str;

bool_t      str_new			   (str*, u32_t, va_list);
bool_t      str_clone		   (str*, str*)          ;
void        str_del			   (str*)		         ;

void        str_rsv_back	   (str*, u64_t);
void	    str_rsv_front	   (str*, u64_t);

void        str_push_back	   (str*, str*)		  ;
void        str_push_front	   (str*, str*)		  ;
void        str_push		   (str*, u64_t, str*);

void        str_push_front_cstr(str*, cstr_t)		;
void        str_push_back_cstr (str*, cstr_t)		;
void        str_push_cstr	   (str*, u64_t, cstr_t);

void        str_pop_front	   (str*, u64_t)       ;
void        str_pop_back	   (str*, u64_t)	   ;
void        str_pop		       (str*, u64_t, u64_t);

u64_t       str_find		   (str*, u64_t, str*)  ;
u64_t       str_find_cstr	   (str*, u64_t, cstr_t);

bool_t      str_eq		       (str*, str*)  ;
bool_t      str_gt		       (str*, str*)  ;
bool_t      str_lt		       (str*, str*)  ;

bool_t      str_eq_cstr	       (str*, cstr_t);
bool_t      str_gt_cstr	       (str*, cstr_t);
bool_t      str_lt_cstr        (str*, cstr_t);

bool_t      str_starts	       (str*, str*)  ;
bool_t	    str_ends		   (str*, str*)  ;

bool_t      str_starts_cstr    (str*, cstr_t);
bool_t	    str_ends_cstr      (str*, cstr_t);

bool_t      str_empty          (str*);
u64_t       str_len            (str*);
const char* str_as_raw         (str*);
cstr_t	    str_as_cstr        (str*);

#endif