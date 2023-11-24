#include "iter.h"

__iter_trait __iter_npos	  = {
	.on_next = &__iter_npos_next,
	.on_get  = &__iter_npos_get ,
	.on_set  = &__iter_npos_set
};

bool_t __iter_npos_next(void* par)			      { return false_t; }
void*  __iter_npos_get (void* par)				  { return 0	  ; }
void*  __iter_npos_set (void* par, void* par_set) { return 0	  ; }

bool_t
	__iter_next
		(__iter* par_it)	  {
			if(!par_it->trait)
				return false_t;

			par_it->iter = par_it->trait->on_next(par_it->iter);
			return par_it->iter != 0;
}

void*
	__iter_get
		(__iter* par_it)	  {
			if(!par_it->trait) 
				return false_t;

			return par_it->trait->on_get(par_it->iter);
}

void*
	__iter_set
		(__iter* par_it, void* par_set) {
			if(!par_it->trait) 
				return false_t;

			return par_it->trait->on_set(par_it->iter, par_set);
}