#ifdef PRESET_FEATURE_THREAD
#include "thd.h"

void
    thd_do_run
        (thd* self)                            {
            if (trait_of(self) != thd_t) return;
            if (this)                    return;
            this = (struct this*) obj_new      (
                null_t     ,
                this_t    ,
                2         ,
                self->func,
                self->arg
            );

            self->ret  = this->ret;
            self->stat = fut_ready;
            del(this);
}

u64_t
    thd_do_poll
        (thd* self)                                    {
            if (trait_of(self) != thd_t) return fut_err;
            return self->stat;
}

void*
    thd_do_ret
        (thd* self)                                   {
            if (trait_of(self) != thd_t) return null_t;
            return self->ret;
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
            any_t func = null_t; if (par_count > 0) func = va_arg(par, any_t);
            any_t arg  = null_t; if (par_count > 1) arg  = va_arg(par, any_t);
            if (!func) return false_t;
            self->stat = fut_pend;
            self->func = func    ;
            self->arg  = arg     ;

            if (pthread_create(&self->thd, null_t, (void*(*)(void*))thd_do_run, self)) return false_t;
            return true_t;
}

bool_t
    thd_clone
        (thd* par, thd* par_clone) {
            return false_t;
}

void
    thd_del
        (thd* par)                        {
            pthread_join(par->thd, null_t);
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
