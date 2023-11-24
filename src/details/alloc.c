#include "alloc.h"

bool_t
	__alloc_new
		(__alloc* par, __alloc_trait* par_trait) {
			if(!par)	   return false_t;
			if(!par_trait) return false_t;

			par->trait = par_trait;

			return par->trait->on_new(par);
}

bool_t
	__alloc_clone
		(__alloc* par, __alloc* par_clone)		{
			if(!par_clone)		  return false_t;
			if(!par_clone->trait) return false_t;
			
			par->trait = par_clone->trait;

			return par->trait->on_clone(par, par_clone);
}

void
	__alloc_del
		(__alloc* par)			   {
			par->trait->on_del(par);
			par->trait			= 0;
}