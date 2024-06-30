#ifndef COLLECTIONS_STR_H
#define COLLECTIONS_STR_H

#include "seq.h"

extern obj_trait* str_t;
typedef struct    str  {
	obj	head;
	seq str ;
}	str;

void  str_prep_front(str* self, u64_t prep);
void  str_prep_back (str* self, u64_t prep);

void  str_push      (str* self, const char* push, u64_t len, u64_t off);
void  str_push_front(str* self, const char* push, u64_t len);
void  str_push_back (str* self, const char* push, u64_t len);

void  str_pop       (str* self, u64_t len, u64_t off);
void  str_pop_front (str* self, u64_t len);
void  str_pop_back  (str* self, u64_t len);

u64_t  str_find     (str* self, u64_t off, const char* find, u64_t len);
bool_t str_begin    (str* self, const char* cmp, u64_t len);
bool_t str_end      (str* self, const char* cmp, u64_t len);

bool_t      str_empty(str* self);
u64_t       str_len  (str* self);
const char* str_ptr  (str* self);

#endif