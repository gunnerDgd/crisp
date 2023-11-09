#include "list.h"


__obj_trait __list_trait                = {
    .init          = &__list_init         ,
    .init_as_clone = &__list_init_as_clone,
    .init_as_ref   =                     0,
    .deinit        = &__list_deinit       ,
    .name          =                     0,
    .size          = &__list_size
};

bool_t
    __list_init
        (__list* par_list, u32_t par_count, va_list par) {
            __alloc* alloc = (par_count == 0) ? global_alloc : va_arg(par, __alloc*);

            par_list->begin.next = &par_list->end;
            par_list->begin.prev =              0;

            par_list->end.prev   = &par_list->begin;
            par_list->end.next   =                0;
            par_list->alloc      = alloc;

            return true_t;
}

bool_t
    __list_init_as_clone
        (__list* par, __list* par_clone) {
            if(!par_clone->alloc) return false_t;

            par->begin.next = &par->end;
            par->begin.prev =         0;

            par->end.prev   =      &par->begin;
            par->end.next   =                0;
            par->alloc      = par_clone->alloc;

            __list_elem *push_cur = par_clone->begin.next;
            while(push_cur->next)
                __list_push_back(par, __obj_init_as_clone(push_cur->elem));

            return true_t;
}

void
    __list_deinit
        (__list* par) {
            while(par->begin.next != &par->end)
                __list_pop_front(par);
}

u64_t
    __list_size() {
        return sizeof(__list);
}

__list_elem*
    __list_push_back
        (__list* par, __obj* par_push) {
            if(!par->alloc) return 0;

            __mem       *ret_mem   = __mem_init(par->alloc, sizeof(__list_elem)); if(!ret_mem) return 0;
            __list_elem *ret       = ret_mem->ptr      ;
                         ret->mem  = ret_mem		   ;
                         ret->next = &par->end	   ;
                         ret->prev =  par->end.prev;

                         ret->elem = __obj_init_as_ref(par_push);
                         ret->list = par;
                                     par->end.prev->next = ret;
                                     par->end.prev       = ret;

            return       ret;
}

__list_elem*
    __list_push_front
        (__list* par, __obj* par_push) {
            __mem       *ret_mem   = __mem_init(par->alloc, sizeof(__list_elem)); if(!ret_mem) return 0;
            __list_elem *ret       = ret_mem->ptr;
                         
                         ret->mem  = ret_mem         ;
                         ret->next =  par->begin.next;
                         ret->prev = &par->begin     ;

                         ret->elem = __obj_init_as_ref(par_push);
                         ret->list = par;
                                     par->begin.next->prev = ret;
                                     par->begin.next       = ret;

        return       ret;
}

__list_elem*
    __list_push_at
        (__list* par, __obj* par_push, __list_elem* par_at) {
            if(!par_at)              return 0;
            if (par_at->list != par) return 0;

            __mem       *ret_mem   = __mem_init(par->alloc, sizeof(__list_elem)); if(!ret_mem) return 0;
            __list_elem *ret       = ret_mem->ptr;

                         ret->mem  = ret_mem     ;
                         ret->prev = par_at      ;
                         ret->next = par_at->next;

                         ret->elem = __obj_init_as_ref(par_push);
                         ret->list = par;
                                     par_at->next = ret;

            return       ret;
}

void
    __list_pop_front
        (__list* par) {
            __list_elem *ret_elem = par->begin.next; if (ret_elem == &par->end) return;
            __obj       *ret      = ret_elem->elem ;

                         ret_elem->prev->next = ret_elem->next;
                         ret_elem->next->prev = ret_elem->prev;

            __mem_deinit(ret_elem->mem);
            __obj_deinit(ret);
}

void
    __list_pop_back
        (__list* par) {
            __list_elem *ret_elem = par->end.prev; if (ret_elem == &par->begin) return;
            __obj       *ret      = ret_elem->elem;
                         ret_elem->prev->next = ret_elem->next;
                         ret_elem->next->prev = ret_elem->prev;

            __mem_deinit(ret_elem->mem);
            __obj_deinit(ret);
}

void
    __list_pop_at
        (__list* par, __list_elem* par_at) {
            __obj *ret = par_at->elem                     ; if (par_at->list != par) return;
                         par_at->prev->next = par_at->next;
                         par_at->next->prev = par_at->prev;

            __mem_deinit(par_at->mem);
            __obj_deinit(ret);
}

bool_t
    __list_empty
        (__list* par) {
            return par->begin.next == &par->end;
}