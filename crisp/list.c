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

c_list_elem_t
    c_list_push_back(c_list_t* par_list, c_object_t par_object) {
        c_handle_init(c_list_elem_t, ret, list_push_back(par_list, par_object.ptr));
        return        ret;
}

c_list_elem_t
    c_list_push_front(c_list_t* par_list, c_object_t par_object) {
        c_handle_init(c_list_elem_t, ret, list_push_front(par_list, par_object.ptr));
        return ret;
}

c_list_elem_t
    c_list_push_at(c_list_t* par_list, c_object_t par_push, c_list_elem_t par_push_at) {
        c_handle_init(c_list_elem_t, ret, list_push_at(par_list, c_handle_ptr(par_push), c_handle_ptr(par_push_at)));
        return        ret;
}

c_object_t
    c_list_pop_front(c_list_t* par_list) {
        c_handle_init(c_object_t, ret, list_pop_front(par_list));
        return ret;
}

c_object_t
    c_list_pop_back(c_list_t* par_list) {
        c_handle_init(c_object_t, ret, list_pop_back(par_list));
        return ret;
}

c_object_t
    c_list_pop_at(c_list_t* par_list, c_list_elem_t par_pop_at) {
        c_handle_init(c_object_t, ret, list_pop_at(par_list, c_handle_ptr(par_pop_at)));
        return ret;
}

c_list_elem_t
    c_list_elem_next(c_list_elem_t par_elem) {
        list_element_t *ret_elem = c_handle_typed_ptr(par_elem, list_element_t*);
        c_handle_init(c_list_elem_t, ret, 0);

        if(!ret_elem) return ret;
        ret.ptr = ret_elem->next;

        return ret;
}

c_list_elem_t
    c_list_elem_prev(c_list_elem_t par_elem) {
        list_element_t *ret_elem = c_handle_typed_ptr(par_elem, list_element_t*);
        c_handle_init(c_list_elem_t, ret, 0);

        if(!ret_elem) return ret;
        ret.ptr = ret_elem->prev;

        return ret;
}

c_object_t
    c_list_elem_object(c_list_elem_t par_elem) {
        list_element_t *ret_elem = c_handle_typed_ptr(par_elem, list_element_t*);
        c_handle_init(c_object_t, ret, 0);

        if(!ret_elem) return ret;
        c_handle_ptr(par_elem) = ret_elem->elem;
        return ret;
}