#include "list.h"

#include "details/list.h"
#include "details/iter.h"

obj_trait* list_t = &__list_trait;

iter
    list_push_back
        (list* par, obj* par_object) {
            iter    ret            ;
            __iter *ret_iter = &ret;

            if (!par)                    return iter_npos();
            if (trait_of(par) != list_t) return iter_npos();

            ret_iter->iter  = __list_push_back(par, par_object);
            ret_iter->trait = &__list_iter_trait;

            return ret;
}

iter
    list_push_front
        (list* par, obj* par_object) {
            iter    ret            ;
            __iter* ret_iter = &ret;

            if (!par)                    return iter_npos();
            if (trait_of(par) != list_t) return iter_npos();

            ret_iter->iter  = __list_push_front(par, par_object);
            ret_iter->trait = &__list_iter_trait;

            return ret;
}

iter
    list_push_at
        (list* par, obj* par_push, iter par_at) {
            iter    ret          ;
            __iter *ret_it = &ret;

            if (!par)                    return iter_npos();
            if (trait_of(par) != list_t) return iter_npos();

            ret_it->iter  = __list_push_at(par, par_push, ((__iter*)&par_at)->iter);
            ret_it->trait = &__list_iter_trait;

            return ret;
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

            __list_pop_back(par)  ;
}

void
    list_pop_at
        (list* par, iter par_at)                                 {
            __iter      *it      = &par_at                       ;
            __list_elem *it_next = ((__list_elem*)it->iter)->next;

            if (!par)                    return;
            if (trait_of(par) != list_t) return;

            __list_pop_at(par, it->iter);
}

iter
	list_iter
        (list* par)                                        {
            if (!par)                    return iter_npos();
            if (trait_of(par) != list_t) return iter_npos();
            
            iter   ret; __list_iter(par, &ret);
            return ret;
}

bool_t
    list_empty
        (list* par) {
            if (!par)                    return true_t;
            if (trait_of(par) != list_t) return true_t;

            return __list_empty(par);
}