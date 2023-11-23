#include "sig.h"
#include <Windows.h>

PVOID sig_hndl_main;
list  sig_hndl  [4];

u64_t
	__sig_main(void* par)												   {
		PEXCEPTION_POINTERS excp     = par								   ;
		u64_t				excp_idx = excp->ExceptionRecord->ExceptionCode;

		switch (excp_idx)													  {
			case EXCEPTION_BREAKPOINT		    : excp_idx = __sig_dbg ; break;
			case EXCEPTION_GUARD_PAGE		    :
			case EXCEPTION_ACCESS_VIOLATION     :
			case EXCEPTION_ARRAY_BOUNDS_EXCEEDED: excp_idx = __sig_segv; break;
			default								: 
				return EXCEPTION_CONTINUE_SEARCH;
		}

		list_for(&sig_hndl[excp_idx], hndl_it) {
			__sig_hndl* hndl = get(hndl_it);
			
			if (hndl->hndl(hndl->par))
				return EXCEPTION_CONTINUE_EXECUTION;
		}

		return EXCEPTION_CONTINUE_SEARCH;
}

bool_t 
	__sig_init()									  {
		for(u64_t i = 0 ; i < 4 ; ++i)
			if (!make_at(sig_hndl[i], list_t) from(0))
				return false_t;

		if (!(sig_hndl_main = AddVectoredExceptionHandler(1, __sig_main)))
			return false_t;

		return true_t;
}

void
	__sig_deinit()							         {
		RemoveVectoredExceptionHandler(sig_hndl_main);
		for (u64_t i = 0; i < 4; ++i)
			del(&sig_hndl[i]);

		return;
}

it     
	__sig_hndl_add
		(u64_t par_idx, __sig_hndl* par)						  {
			if (!par)								 return npos();
			if (!trait_of(par) != &__sig_hndl_trait) return npos();
			if (par_idx > 3)						 return npos();

			return list_push_back(&sig_hndl[par_idx], par);
}

void
	__sig_hndl_del
		(it par)					    {
			list_pop_at(&sig_hndl, &par);
}