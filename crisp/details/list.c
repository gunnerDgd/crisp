#include "list.h"

c_bool_t
    list_init(list_t* par_list, alloc_t* par_alloc) {
        par_list->begin.next = &par_list->end;
        par_list->begin.prev =              0;

        par_list->end.prev   = &par_list->begin;
        par_list->end.next   =                0;

        par_list->alloc      = par_alloc;

        return true;
}

c_bool_t
    list_init_as_clone(list_t* par_list, list_t* par_list_clone) {
        if(!par_list_clone->alloc) return false;

        list_init(par_list, par_list_clone->alloc);
        list_element_t *push_cur = par_list_clone->begin.next;

        while(push_cur->next)
            list_push_back(par_list, obj_init_as_clone(push_cur->elem));
}

c_bool_t
    list_deinit(list_t* par_deinit) {
        while(list_pop_front(par_deinit));
}

list_element_t*
    list_push_back(list_t* par_list, obj_t* par_object) {
        if(!par_list->alloc) return 0;

        mem_t          *ret_mem   = mem_init(par_list->alloc, sizeof(list_element_t)); if(!ret_mem) return 0;
        list_element_t *ret       = mem_ptr (ret_mem);

                        ret->mem  =  ret_mem;
                        ret->next = &par_list->end;
                        ret->prev =  par_list->end.prev;

                        ret->elem =  obj_init_as_ref(par_object);
                        ret->list =  par_list;
                                     par_list->end.prev = ret;

        return          ret;
}

list_element_t*
    list_push_front(list_t* par_list, obj_t* par_object) {
        mem_t          *ret_mem   = mem_init(par_list->alloc, sizeof(list_element_t)); if(!ret_mem) return 0;
        list_element_t *ret       = mem_ptr (ret_mem);

                        ret->next =  par_list->begin.next;
                        ret->prev = &par_list->begin;

                        ret->elem = obj_init_as_ref(par_object);
                        ret->list = par_list;
                                    par_list->begin.next = ret;

        return          ret;
}

list_element_t*
    list_push_at(list_t* par_list, obj_t* par_object, list_element_t* par_at) {
        if(!par_at)                   return 0;
        if (par_at->list != par_list) return 0;

        mem_t          *ret_mem   = mem_init(par_list->alloc, sizeof(list_element_t)); if(!ret_mem) return 0;
        list_element_t *ret       = mem_ptr (ret_mem);

                        ret->mem  = ret_mem     ;
                        ret->prev = par_at      ;
                        ret->next = par_at->next;

                        ret->elem = obj_init_as_ref(par_object);
                        ret->list = par_list;
                                    par_at->next = ret;

        return          ret;
}

obj_t*
    list_pop_front(list_t* par_list) {
        list_element_t *ret_elem = par_list->begin.next; if (ret_elem == &par_list->end) return 0;
        obj_t          *ret      = ret_elem->elem;

                        ret_elem->prev->next = ret_elem->next;
                        ret_elem->next->prev = ret_elem->prev;

        mem_deinit(ret_elem->mem);
        return (obj_deinit(ret)) ? 0 : ret;
}

obj_t*
    list_pop_back(list_t* par_list) {
        list_element_t *ret_elem = par_list->end.prev; if (ret_elem == &par_list->begin) return 0;
        obj_t          *ret      = ret_elem->elem;

                        ret_elem->prev->next = ret_elem->next;
                        ret_elem->next->prev = ret_elem->prev;

        mem_deinit(ret_elem->mem);
        return    (obj_deinit(ret)) ? 0 : ret;
}

obj_t*
    list_pop_at(list_t* par_list, list_element_t* par_pop) {
        obj_t *ret = par_pop->elem; if (par_pop->list != par_list) return 0;
                     par_pop->prev->next = par_pop->next;
                     par_pop->next->prev = par_pop->prev;

        mem_deinit(par_pop->mem);
        return (obj_deinit(ret)) ? 0 : ret;
}