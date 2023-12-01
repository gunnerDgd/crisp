#include "list.h"

obj_trait __list_trait     = {
    .on_new   = &__list_new  ,
    .on_clone = &__list_clone,
    .on_ref   =             0,
    .on_del   = &__list_del  ,
    .size     = sizeof(__list)
};

bool_t
    __list_new
        (__list* par_list, u32_t par_count, va_list par) {
            par_list->res  = (par_count == 0) ? get_mem_res() : va_arg(par, mem_res*);
            if (!par_list->res) 
                return false_t;

            par_list->begin.next = &par_list->end;
            par_list->begin.prev =              0;
            par_list->begin.elem =              0;

            par_list->end.prev   = &par_list->begin;
            par_list->end.next   = 0               ;
            par_list->end.elem   = 0               ;

            return true_t;
}

bool_t
    __list_clone
        (__list* par, __list* par_clone)        {
            if (!par_clone->res) return false_t;

            par->begin.next = &par->end;
            par->begin.prev = 0        ;

            par->end.prev   = &par->begin   ;
            par->end.next   = 0             ;
            par->res        = par_clone->res;

            __list_elem *push = par_clone->begin.next;
            while (push != &par_clone->end) 
                __list_push_back(par, push->elem);

            return true_t;
}

void
    __list_del
        (__list* par)                           {
            while(par->begin.next != &par->end)
                __list_pop_front(par);
}

__list_elem*
    __list_push_back
        (__list* par, obj* par_push) {
            if (!par->res) return 0; __list_elem* ret = mem_new(par->res, sizeof(__list_elem));
            if (!ret)      return 0;

            ret->elem = ref(par_push);
            ret->list = par          ;

            ret->next = &par->end	  ;
            ret->prev =  par->end.prev;

            par->end.prev->next = ret;
            par->end.prev       = ret;

            return ret;
}

__list_elem*
    __list_push_front
        (__list* par, obj* par_push) {
            if (!par->res)  return 0;
            __list_elem *ret = mem_new(par->res, sizeof(__list_elem));
            if (!ret) return 0;

            ret->elem = ref(par_push);
            ret->list = par;

            ret->next =  par->begin.next;
            ret->prev = &par->begin     ;
            
            par->begin.next->prev = ret;
            par->begin.next       = ret;

            return ret;
}

__list_elem*
    __list_push
        (__list* par, obj* par_push, __list_elem* par_at)                          {
            if(!par->res)                   return                                0;
            if(par_at->list != par)         return                                0;
            if(par_at       == &par->end)   return __list_push_back (par, par_push);
            if(par_at       == &par->begin) return __list_push_front(par, par_push);

            __list_elem *ret = mem_new(par->res, sizeof(__list_elem));
            if (!ret) return 0;

            ret->prev = par_at       ;
            ret->next = par_at->next ;

            ret->elem = ref(par_push);
            ret->list = par          ; par_at->next = ret;

            return ret;
}

obj*
    __list_pop_front
        (__list* par)                         {
            __list_elem *pop = par->begin.next;
            if (pop == &par->end)
                return 0;

            pop->prev->next = pop->next;
            pop->next->prev = pop->prev;

            obj*   ret = (del(pop->elem)) ? pop->elem : 0; mem_del(par->res, pop);
            return ret;

}

obj*
    __list_pop_back
        (__list* par)                       {
            __list_elem *pop = par->end.prev;
            if (pop == &par->begin)
                return 0;
            
            pop->prev->next = pop->next;
            pop->next->prev = pop->prev;

            obj*   ret = (del(pop->elem)) ? pop->elem : 0; mem_del(par->res, pop);
            return ret;
}

obj*
    __list_pop
        (__list* par, __list_elem* par_at)                         {
            if (par_at == &par->begin) return __list_pop_front(par);
            if (par_at == &par->end)   return __list_pop_back (par);
            if (par_at->list != par)   return 0;

            par_at->prev->next = par_at->next;
            par_at->next->prev = par_at->prev;

            obj*   ret = (del(par_at->elem)) ? par_at->elem : 0; mem_del(par->res, par_at);
            return ret;
}

bool_t
    __list_empty
        (__list* par) {
            return par->begin.next == &par->end;
}