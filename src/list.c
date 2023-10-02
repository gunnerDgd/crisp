#include "list.h"
#include "details/list.h"

bool_t
    list_init(list* par_list, alloc* par_alloc) {
        return __list_init(par_list, par_alloc);
}

bool_t
    list_init_as_clone(list* par_list, list* par_list_clone) {
        return __list_init_as_clone(par_list, par_list_clone);
}

void
    list_deinit(list* par_list) {
        __list_deinit(par_list);
}

list_iter
    list_push_back(list* par_list, obj* par_object) {
        return __list_push_back(par_list, par_object);
}

list_iter
    list_push_front(list* par_list, obj* par_object) {
        return __list_push_front(par_list, par_object);
}

list_iter
    list_push_at(list* par_list, obj* par_push, list_iter par_push_at) {
        return __list_push_at(par_list, par_push, par_push_at);
}

void
    list_pop_front(list* par_list) {
        __list_pop_front(par_list);
}

void
    list_pop_back(list* par_list) {
        __list_pop_back(par_list);
}

void
    list_pop_at(list* par_list, list_iter par_pop_at) {
        __list_pop_at(par_list, par_pop_at);
}

list_iter
	list_iter_begin(list* par_list) {
		__list* list = par_list;
		return (list->begin.next->elem) ? list->begin.next : 0;
}

list_iter
	list_iter_end(list* par_list) {
		__list* list = par_list;
		return &list->end;
}

list_iter
    list_iter_next(list_iter par_elem) {
        __list_elem *ret_elem = par_elem;
		return 	    (ret_elem) ? ret_elem->next : 0;
}

list_iter
    list_iter_prev(list_iter par_elem) {
        __list_elem *ret_elem = par_elem;
		return      (ret_elem->next) ? ret_elem : 0;
}

obj*
    list_iter_object(list_iter par_elem) {
        return (par_elem) ? ((__list_elem*)par_elem)->elem : 0;
}