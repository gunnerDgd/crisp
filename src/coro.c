#include "coro.h"
#include "details/coro.h"

obj_trait* coro_t = &__coro_trait;

void*  coro_yield(coro* par, void* par_arg) { return __coro_yield(par, par_arg); }