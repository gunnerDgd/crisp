#include "list.h"

obj_trait list_trait = make_trait (
    list_new    ,
    list_clone  ,
    null_t      ,
    list_del    ,
    sizeof(list),
    null_t
);

obj_trait* list_t = &list_trait;

bool_t
    list_new
        (list* self, u32_t count, va_list arg)               {
            mem* mem = null_t; if (count > 0) mem = get_mem();
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t;

            if (!make_at(&self->begin, node) from(0)) return false_t;
            if (!make_at(&self->end  , node) from(0)) return false_t;
            if (!next_as(&self->begin, &self->end))   return false_t;
            return true_t;
}

bool_t
    list_clone
        (list* self, list* clone)                                   {
            if (trait_of(clone->mem) != mem_t)        return false_t;
            if (!make_at(&self->begin, node) from(0)) return false_t;
            if (!make_at(&self->end  , node) from(0)) return false_t;

            if (!next_as(&self->begin, &clone->end))   return false_t;
            if (!prev_as(&self->end  , &clone->begin)) return false_t;
            self->mem = clone->mem;

            list_for(clone, push) list_push_back(self, value(push));
            return true_t;
}

void
    list_del
        (list* self)                                       {
            for ( ; list_empty(self) ; list_pop_back(self));
}

node*
    list_push_back
        (list* par, obj* par_push)                    {
            if (trait_of(par) != list_t) return null_t;
            node *ret = (node*) obj_new               (
                par->mem,
                node_t  ,
                1       ,
                par_push
            );

            if (trait_of(ret) != node_t) return null_t;
            prev_as(ret, prev(&par->end));
            prev_as(&par->end, ret)      ;
            return  ret;
}

node*
    list_push_front
        (list* par, obj* par_push)                    {
            if (trait_of(par) != list_t) return null_t;
            node *ret = (node*) obj_new               (
                par->mem,
                node_t  ,
                1       ,
                par_push
            );

            if (trait_of(ret) != node_t) return null_t;
            next_as(ret, next(&par->begin));
            next_as(&par->begin, ret)      ;
            return  ret;
}

node*
    list_move_back
        (list* par, obj* par_push)                   {
            node* ret = list_push_back(par, par_push);

            if (trait_of(ret) != node_t) return null_t;
            del(par_push);
            return ret;
}

node*
    list_move_front
        (list* par, obj* par_push)                    {
            node* ret = list_push_front(par, par_push);

            if (trait_of(ret) != node_t) return null_t;
            del(par_push);
            return ret;
}

obj*
    list_pop_front
        (list* par)                                   {
            if (trait_of(par) != list_t) return null_t;
            if (list_empty(par))         return null_t;

            node *ret_cur = next (&par->begin);
            obj  *ret     = value(ret_cur)    ;
            if (use_count(ret) == 1) {
                del(ret_cur);
                return 0;
            }

            del   (ret_cur);
            return ret     ;
}

obj*
    list_pop_back
        (list* par)                                   {
            if (trait_of(par) != list_t) return null_t;
            if (list_empty(par))         return null_t;

            node *ret_cur = prev (&par->end);
            obj  *ret     = value(ret_cur)  ;
            if (use_count(ret) == 1) {
                del (ret_cur);
                return null_t;
            }

            del   (ret_cur);
            return ret     ;
}

bool_t
    list_empty
        (list* par)                                   {
            if (trait_of(par) != list_t) return true_t;
            return next(&par->begin) == &par->end;
}

node*
    list_begin
        (list* par)                                   {
            if (trait_of(par) != list_t) return null_t;
            return par->begin.next;
}

node*
    list_end
        (list* par)                                   {
            if (trait_of(par) != list_t) return null_t;
            return &par->end;
}