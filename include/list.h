#ifndef __LIST_H__
#define __LIST_H__

#include "alloc.h"
#include "obj.h"
#include "iter.h"

extern obj_trait* list_t;
typedef struct    list { u64_t handle[16]; } list;

iter   list_push_back (list*, obj*)      ;
iter   list_push_front(list*, obj*)      ;
iter   list_push_at   (list*, obj*, iter);

void   list_pop_front(list*)	  ;
void   list_pop_back (list*)	  ;
void   list_pop_at   (list*, iter);

iter   list_iter (list*);
bool_t list_empty(list*);

#endif
