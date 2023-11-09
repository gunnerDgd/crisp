#include "coro.h"
#include "details/coro.h"

obj_trait* coro_t = &__coro_trait;

bool_t 
	coro_init
		(coro* par, void(*par_fn)(coro*, void*), void* par_arg, alloc* par_alloc) {
			if (!par_alloc) par_alloc = get_alloc();
			if (!par_alloc) return false_t;

			return __coro_init(par, par_fn, par_arg); 
}
bool_t coro_init_as_clone(coro* par, coro* par_arg) { return __coro_init_as_clone(par, par_arg); }
void   coro_deinit		 (coro* par)				{		 __coro_deinit       (par)		   ; }
void*  coro_yield		 (coro* par, void* par_arg) { return __coro_yield		 (par, par_arg); }