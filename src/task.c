#include "task.h"
#include "alloc.h"

#ifdef PRESET_X86_64
#include "details-arch/x86_64/task.h"
#endif

obj_trait* task_t = &__task_trait;

bool_t 
	task_init
		(obj* par, alloc* par_alloc, void(*par_fn)(task*, void*), void* par_fn_arg) {
			if (!par_alloc) par_alloc = get_alloc();
			if (!par_alloc) return false_t;

			return __task_init(par, par_alloc, par_fn, par_fn_arg);
}

bool_t 
	task_init_as_clone
		(obj* par, obj* par_clone) {
			return __task_init_as_clone(par, par_clone);
}

void
	task_deinit
		(obj* par) {
			__task_deinit(par);
}

bool_t task_run  (obj* par) { return __task_run  (par); }
bool_t task_yield(obj* par) { return __task_yield(par); }