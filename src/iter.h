#ifndef __ITER_H__
#define __ITER_H__

#include "type.h"
#include "type_atom.h"

typedef struct iter { u64_t it[2]; } iter;

iter   iter_npos()           ;
bool_t iter_same(iter, iter) ;
iter   iter_next(iter)       ;
void*  iter_get (iter)       ;
void*  iter_set (iter, void*);

#define npos(par)             iter_same(par, iter_npos())
#define next(par)		      iter_next(par)
#define get(par)		      iter_get (par)
#define get_as(par, par_type) ((par_type)get(par))
#define set(par)		      iter_set (par)

#endif