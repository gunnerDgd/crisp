#include "list.h"
#include "details/list.h"

c_bool_t
    c_list_init(c_list_t* par_list, c_alloc_t* par_alloc) {
        return list_init(par_list, par_alloc);
}

c_bool_t
    c_list_init_as_clone(c_list_t* par_list, c_list_t* par_list_clone) {
        return list_init_as_clone(par_list, par_list_clone);
}

c_bool_t
    c_list_deinit(c_list_t* par_list) {
        return list_deinit(par_list);
}

c_list_iter_t
    c_list_push_back(c_list_t* par_list, c_obj_t par_object) {
        return list_push_back(par_list, par_object);
}

c_list_iter_t
    c_list_push_front(c_list_t* par_list, c_obj_t par_object) {
        return list_push_front(par_list, par_object);
}

c_list_iter_t
    c_list_push_at(c_list_t* par_list, c_obj_t par_push, c_list_iter_t par_push_at) {
        return list_push_at(par_list, par_push, par_push_at);
}

c_obj_t
    c_list_pop_front(c_list_t* par_list) {
        return list_pop_front(par_list);
}

c_obj_t
    c_list_pop_back(c_list_t* par_list) {
        return list_pop_back(par_list);
}

c_obj_t
    c_list_pop_at(c_list_t* par_list, c_list_iter_t par_pop_at) {
        return list_pop_at(par_list, par_pop_at);
}

c_list_iter_t
	c_list_iter_begin(c_list_t* par_list) {
		list_t* list = par_list;
		return (list->begin.next->elem) ? list->begin.next : 0;
}

c_list_iter_t
	c_list_iter_end(c_list_t* par_list) {
		list_t* list = par_list;
		return &list->end;
}

c_list_iter_t
    c_list_iter_next(c_list_iter_t par_elem) {
        list_element_t *ret_elem = par_elem;
		return (ret_elem) ? ret_elem->next : 0;
}

c_list_iter_t
    c_list_iter_prev(c_list_iter_t par_elem) {
        list_element_t *ret_elem = par_elem;
		return (ret_elem->next) ? ret_elem : 0;
}

c_obj_t*
    c_list_iter_object(c_list_iter_t par_elem) {
        return (par_elem) ? ((list_element_t*)par_elem)->elem : 0;
}