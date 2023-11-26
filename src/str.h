#ifndef __STR_H__
#define __STR_H__

#include "type.h"

extern struct obj_trait* str_t;
typedef struct			 str  { u64_t handle[16]; } str;

void str_rsv_back (str*, u64_t);
void str_rsv_front(str*, u64_t);

void str_push_back	    (str*, str*);
void str_push_back_cstr (str*, const char*, u64_t);
void str_push_front	    (str*, str*);
void str_push_front_cstr(str*, const char*, u64_t);
void str_push_at		(str*, u64_t, str*);
void str_push_at_cstr	(str*, u64_t, const char*, u64_t);

void str_pop_front(str*, u64_t)		  ;
void str_pop_back (str*, u64_t)		  ;
void str_pop_at   (str*, u64_t, u64_t);

u64_t str_find	   (str*, u64_t, str*)			    ;
u64_t str_find_cstr(str*, u64_t, const char*, u64_t);

bool_t str_eq		   (str*, str*)				 ;
bool_t str_eq_cstr(str*, const char*, u64_t);
bool_t str_gt		   (str*, str*);
bool_t str_gt_cstr(str*, const char*, u64_t);
bool_t str_lt		   (str*, str*);
bool_t str_lt_cstr(str*, const char*, u64_t);

bool_t str_starts	  (str*, str*)              ;
bool_t str_starts_cstr(str*, const char*, u64_t);
bool_t str_ends		  (str*, str*)              ;
bool_t str_ends_cstr  (str*, const char*, u64_t);

bool_t      str_empty(str*);
u64_t       str_len  (str*);
const char* str_ptr  (str*);

#endif