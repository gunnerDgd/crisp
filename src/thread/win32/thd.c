#ifdef PRESET_FEATURE_THREAD
#include "thd.h"
#include <Windows.h>

void
    thd_do_run
        (thd* self)                              {
            if (trait_of(self) != thd_t) goto err;
            if (!mod_new())              goto err;

            if (!obj_new_at(&this, this_t, 2, self->func, self->arg)) goto err;
            self->stat = fut_ready;
            mod_del ();
            del(&this);
    err:    self->stat = fut_pend;
}

u64_t
    thd_do_poll
        (thd* par)                                    {
            if (trait_of(par) != thd_t) return fut_err;
            return par->stat;
}

void*
    thd_do_ret
        (thd* par)                                   {
            if (trait_of(par) != thd_t) return null_t;
            return par->ret;
}

fut_ops thd_fut_ops = make_fut_ops (
    thd_do_poll,
    thd_do_ret
);

obj_trait thd_trait = make_trait (
    thd_new    ,
    thd_clone  ,
    null_t     ,
    thd_del    ,
    sizeof(thd),
    null_t
);

obj_trait *thd_t = &thd_trait;

bool_t
    thd_new
        (thd* self, u32_t par_count, va_list par)                            {
            void* func = null_t; if (par_count > 0) func = va_arg(par, void*);
            void* arg  = null_t; if (par_count > 1) arg  = va_arg(par, void*);
            if (!func) return false_t;
            self->stat = fut_pend;
            self->func = func    ;
            self->arg  = arg     ;
            self->thd  = CreateThread (
                null_t    ,
                0         ,
                thd_do_run,
                self      ,
                0         ,
                null_t
            );

            return self->thd != INVALID_HANDLE_VALUE;
}

bool_t
    thd_clone
        (thd* par, thd* par_clone) {
            return false_t;
}

void
    thd_del
        (thd* par)                                 {
            WaitForSingleObject(par->thd, INFINITE);
            CloseHandle        (par->thd);
}

fut*
    thd_fut
        (thd* par)                                   {
            if (trait_of(par) != thd_t) return null_t;
            return make (fut) from                   (
                2           ,
                &thd_fut_ops,
                par
            );
}

#endif
