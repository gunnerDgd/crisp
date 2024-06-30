#include "list.h"

static bool_t
    do_new
        (list* self, u32_t count, va_list arg)                        {
            mem* mem = null_t; if (count > 0) mem = va_arg(arg, any_t);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;

            if (!make_at(&self->begin, pos) from(0)) return false_t;
            if (!make_at(&self->end  , pos) from(0)) return false_t;
            if (!next_as(&self->begin, &self->end))  return false_t;
            return true_t;
}

static bool_t
    do_clone
        (list* self, list* clone)                                  {
            if (trait_of(clone->mem) != mem_t)       return false_t;
            if (!make_at(&self->begin, pos) from(0)) return false_t;
            if (!make_at(&self->end  , pos) from(0)) return false_t;

            if (!next_as(&self->begin, &clone->end))   return false_t;
            if (!prev_as(&self->end  , &clone->begin)) return false_t;
            self->mem = clone->mem;

            list_for(clone, push) list_push_back(self, as_any(push));
            return true_t;
}

static void
    do_del
        (list* self)                                        {
            for ( ; !list_empty(self) ; list_pop_back(self));
}

static obj_trait
    do_obj = make_trait (
        do_new      ,
        do_clone    ,
        null_t      ,
        do_del      ,
        sizeof(list),
        null_t
);

obj_trait* list_t = &do_obj;

pos*
    list_push_back
        (list* par, any_t push)                       {
            if (trait_of(par) != list_t) return null_t;
            pos *ret = (pos*) obj_new  (
                par->mem,
                pos_t   ,
                1       ,
                push
            );

            if (trait_of(ret) != pos_t) return null_t;
            prev_as(ret, prev(&par->end));
            prev_as(&par->end, ret)      ;
            return  ret;
}

pos*
    list_push_front
        (list* self, any_t push)                       {
            if (trait_of(self) != list_t) return null_t;
            pos *ret = (pos*) obj_new   (
                self->mem,
                pos_t    ,
                1        ,
                push
            );

            if (trait_of(ret) != pos_t) return null_t;
            next_as(ret, next(&self->begin));
            next_as(&self->begin, ret)      ;
            return  ret;
}

pos*
    list_move_back
        (list* self, any_t* push)                 {
            pos* ret = list_push_back(self, *push);

            if (trait_of(ret) != pos_t) return null_t;
            *push = null_t;
            return ret;
}

pos*
    list_move_front
        (list* self, any_t* push)                 {
            pos* ret = list_push_front(self, push);

            if (trait_of(ret) != pos_t) return null_t;
            *push = null_t;
            return ret;
}

any_t
    list_pop_front
        (list* par)                                   {
            if (trait_of(par) != list_t) return null_t;
            if (list_empty(par))         return null_t;
            any_t ret;
            pos  *pos;

            pos = next  (&par->begin);
            ret = as_any(pos);
            return ret;
}

any_t
    list_pop_back
        (list* par)                                   {
            if (trait_of(par) != list_t) return null_t;
            if (list_empty(par))         return null_t;
            any_t ret;
            pos  *pos;

            pos = prev  (&par->end);
            ret = as_any(pos);
            return ret;
}

bool_t
    list_empty
        (list* par)                                   {
            if (trait_of(par) != list_t) return true_t;
            return next(&par->begin) == &par->end;
}

pos*
    list_begin
        (list* self)                                   {
            if (trait_of(self) != list_t) return null_t;
            return next(&self->begin);
}

pos*
    list_end
        (list* self)                                   {
            if (trait_of(self) != list_t) return null_t;
            return &self->end;
}