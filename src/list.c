#include "list.h"

#include "details/list.h"
#include "details/list_it.h"

obj_trait* list_t = &__list_trait;

it
    list_push_back
        (list* par, obj* par_object) {
            it    ret;
            __it *ret_it = &ret;

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

            ret_it->it        = __list_push_at(par, par_push, ((__it*)par_at)->it);
            ret_it->it_parent = par;
            ret_it->trait     = &__list_it_trait;

            return ret;
}

void
    list_pop_front
        (list* par) {
            __list_pop_front(par);
}

void
    list_pop_back
        (list* par) {
            __list_pop_back(par);
}

void
    list_pop_at
        (list* par, it* par_at) {
            __it        *it      = par_at                      ;
            __list_elem *it_next = ((__list_elem*)it->it)->next;

            __list_pop_at(par, it->it);
            it->it = it_next;
}

it
	list_begin
        (list* par) {
            it ret;
            __list_it_begin(par, &ret);
        
            return ret;
}

it
	list_end
        (list* par) {
            it ret;
            __list_it_end(par, &ret);

            return ret;
}

bool_t
    list_empty
        (list* par) {
            return __list_empty(par);
}