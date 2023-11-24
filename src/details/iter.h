#ifndef __DETAILS_ITER_H__
#define __DETAILS_ITER_H__

#include "../type.h"
#include "../type_atomic.h"

typedef struct __iter_trait		  {
	void* (*on_next)(void*)		  ;
	void* (*on_get) (void*)		  ;
	void* (*on_set) (void*, void*);
}	__iter_trait;

extern __iter_trait __iter_npos;
typedef struct      __iter     {
	void	     *iter ;
	__iter_trait *trait;
}	__iter;

bool_t __iter_npos_next(void*);
void*  __iter_npos_get (void*);
void*  __iter_npos_set (void*, void*);

bool_t __iter_next(__iter*);
void*  __iter_get (__iter*);
void*  __iter_set (__iter*, void*);

#endif