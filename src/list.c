#include "list.h"

#include "details/list.h"
#include "details/list_it.h"

obj_trait* list_t = &__list_trait;

it
    list_push_back
        (list* par, obj* par_object) {
            it    ret;
            __it *ret_it = &ret;

            if (!par)                    return npos();
            if (trait_of(par) != list_t) return npos();

            ret_it->it        = __list_push_back(par, par_object);
            ret_it->it_parent = par;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

it
    list_push_front
        (list* par, obj* par_object) {
            it    ret;
            __it *ret_it = &ret;

            if (!par)                    return npos();
            if (trait_of(par) != list_t) return npos();

            ret_it->it        = __list_push_front(par, par_object);
            ret_it->it_parent = par;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

it
    list_push_at
        (list* par, obj* par_push, it* par_at) {
            it    ret;
            __it *ret_it = &ret;

            if (!par)                              return npos();
            if (trait_of(par) != list_t)           return npos();
            if (!ret_it->it_parent || !ret_it->it) return npos();

            ret_it->it        = __list_push_at(par, par_push, ((__it*)par_at)->it);
            ret_it->it_parent = par;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

void
    list_pop_front
        (list* par) {
            if (!par)                    return;
            if (trait_of(par) != list_t) return;

            __list_pop_front(par);
}

void
    list_pop_back
        (list* par) {
            if (!par)                    return;
            if (trait_of(par) != list_t) return;

            __list_pop_back(par);
}

void
    list_pop_at
        (list* par, it* par_at)                                {
            __it        *it      = par_at                      ;
            __list_elem *it_next = ((__list_elem*)it->it)->next;

            if (!par)                      return;
            if (trait_of(par) != list_t)   return;
            if (!it->it_parent || !it->it) return;

            __list_pop_at(par, it->it);
            it->it = it_next;
}

it
	list_begin
        (list* par)                                   {
            if (!par)                    return npos();
            if (trait_of(par) != list_t) return npos();
            
            it     ret; __list_it_begin(par, &ret);
            return ret;
}

it
	list_end
        (list* par) {
            it ret;

            if (!par)                    return npos();
            if (trait_of(par) != list_t) return npos();

            __list_it_end(par, &ret);
            return ret;
}

bool_t
    list_empty
        (list* par) {
            if (!par)                    return true_t;
            if (trait_of(par) != list_t) return true_t;

            return __list_empty(par);
}