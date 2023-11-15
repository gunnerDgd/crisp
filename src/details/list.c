#include "list.h"

obj_trait __list_trait                  = {
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
            alloc* par_alloc = (par_count == 0) ? get_alloc() : va_arg(par, alloc*);
            if (!par_alloc)
                return false_t;

            par_list->begin.next = &par_list->end;
            par_list->begin.prev =              0;

            par_list->end.prev   = &par_list->begin;
            par_list->end.next   =                0;
            par_list->alloc      = par_alloc       ;

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
                __list_push_back(par, clone(push_cur->elem));

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
        (__list* par, obj* par_push) {
            if(!par->alloc) return 0;

            mem ret_mem = mem_init(par->alloc, sizeof(__list_elem)); 
            if(!ret_mem) return 0;

            __list_elem *ret       = ptr_as(mem_ptr(ret_mem, 0), __list_elem*);
                         ret->mem  = ret_mem	   ;
                         ret->next = &par->end	   ;
                         ret->prev =  par->end.prev;

                         ret->elem = ref(par_push);
                         ret->list = par;
                                     par->end.prev->next = ret;
                                     par->end.prev       = ret;

            return       ret;
}

__list_elem*
    __list_push_front
        (__list* par, obj* par_push) {
            mem ret_mem = mem_init(par->alloc, sizeof(__list_elem)); 
            if(!ret_mem) return 0;

            __list_elem *ret       = ptr_as(mem_ptr(ret_mem, 0), __list_elem*);
                         ret->mem  = ret_mem         ;
                         ret->next =  par->begin.next;
                         ret->prev = &par->begin     ;

                         ret->elem = ref(par_push);
                         ret->list = par;
                                     par->begin.next->prev = ret;
                                     par->begin.next       = ret;

        return       ret;
}

__list_elem*
    __list_push_at
        (__list* par, obj* par_push, __list_elem* par_at) {
            if(!par_at)              return 0;
            if (par_at->list != par) return 0;

            mem ret_mem = __mem_init(par->alloc, sizeof(__list_elem)); 
            if(!ret_mem) return 0;

            __list_elem *ret       = ptr_as(mem_ptr(ret_mem, 0), __list_elem*);
                         ret->mem  = ret_mem     ;
                         ret->prev = par_at      ;
                         ret->next = par_at->next;

                         ret->elem = ref(par_push);
                         ret->list = par;
                                     par_at->next = ret;

            return       ret;
}

void
    __list_pop_front
        (__list* par) {
            __list_elem *ret_elem = par->begin.next; 
            if (ret_elem == &par->end) 
                return;

            obj *ret = ret_elem->elem;
                       ret_elem->prev->next = ret_elem->next;
                       ret_elem->next->prev = ret_elem->prev;

            mem_deinit(ret_elem->mem);
            del       (ret)          ;
}

void
    __list_pop_back
        (__list* par) {
            __list_elem *ret_elem = par->end.prev; 
            if (ret_elem == &par->begin)
                return;
            
            obj *ret = ret_elem->elem;
                       ret_elem->prev->next = ret_elem->next;
                       ret_elem->next->prev = ret_elem->prev;

            mem_deinit(ret_elem->mem);
            del       (ret)          ;
}

void
    __list_pop_at
        (__list* par, __list_elem* par_at) {
            obj *ret = par_at->elem; 
            if (par_at->list != par)
                return;

            par_at->prev->next = par_at->next;
            par_at->next->prev = par_at->prev;

            mem_deinit(par_at->mem);
            del       (ret)        ;
}

bool_t
    __list_empty
        (__list* par) {
            return par->begin.next == &par->end;
}