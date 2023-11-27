#include "list.h"
#include "details/list.h"

obj_trait* list_t = &__list_trait;

list_elem
    list_push_back
        (list* par, void* par_push)              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return __list_push_back(par, par_push);
}

list_elem
    list_push_front
        (list* par, void* par_push)              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return __list_push_front(par, par_push);
}

list_elem
    list_push_at
        (list* par, void* par_push, list_elem par_at) {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_at)                 return 0;

            return __list_push_at(par, par_push, par_at);
}

void
    list_pop_front
        (list* par)                            {
            if (!par)                    return;
            if (trait_of(par) != list_t) return;

            __list_pop_front(par);
}

void
    list_pop_back
        (list* par)                            {
            if (!par)                    return;
            if (trait_of(par) != list_t) return;

            __list_pop_back(par);
}

void
    list_pop_at
        (list* par, list_elem par_at)          {
            if (!par)                    return;
            if (trait_of(par) != list_t) return;

            __list_pop_at(par, par_at);
}


bool_t
    list_empty
        (list* par)                                   {
            if (!par)                    return true_t;
            if (trait_of(par) != list_t) return true_t;

            return __list_empty(par);
}

list_elem list_begin(list* par) { return (par) ?  ((__list*)par)->begin.next : 0; }
list_elem list_end  (list* par) { return (par) ? &((__list*)par)->end        : 0; }

list_elem 
    list_next(list_elem par)  {
        __list_elem* ret = par;

        if (!ret)                   return 0;
        if (!ret->list)             return 0;
        if (ret == &ret->list->end) return 0;

        return ret->next;
}

list_elem 
    list_prev(list_elem par)  {
        __list_elem* ret = par;

        if (!ret)                           return 0;
        if (!ret->list)                     return 0;
        if (ret->prev == &ret->list->begin) return 0;

        return ret->prev;
}

void* 
    list_get(list_elem par)   {
        __list_elem* ret = par;

        if (!ret)       return 0;
        if (!ret->list) return 0;

        return ret->elem;
}

void
    list_set
        (list_elem par, void* par_set) {
            __list_elem* ret = par;

            if (!ret)       return 0;
            if (!ret->list) return 0;

            mem_copy(ret->elem, par_set, ret->list->size);
}