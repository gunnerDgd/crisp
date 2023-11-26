#include "list.h"

obj_trait __list_trait     = {
    .on_new   = &__list_new  ,
    .on_clone = &__list_clone,
    .on_ref   =             0,
    .on_del   = &__list_del  ,
    .size     = sizeof(__list)
};

__iter_trait __list_iter_trait = {
	.on_next = &__list_iter_next ,
	.on_get  = &__list_iter_get  ,
	.on_set  = &__list_iter_set
};

bool_t
    __list_new
        (__list* par_list, u32_t par_count, va_list par)                            {
            par_list->res = (par_count == 0) ? get_mem_res() : va_arg(par, mem_res*);
            if (!par_list->res) return false_t;

            par_list->begin.next = &par_list->end;
            par_list->begin.prev =              0;

            par_list->end.prev   = &par_list->begin;
            par_list->end.next   = 0               ;

            return true_t;
}

bool_t
    __list_clone
        (__list* par, __list* par_clone)        {
            if (!par_clone->res) return false_t;

            par->begin.next = &par->end;
            par->begin.prev = 0        ;

            par->end.prev   = &par->begin   ;
            par->end.next   = 0             ;
            par->res        = par_clone->res;

            __list_elem *push = par_clone->begin.next;
            while (push->next)
                __list_push_back(par, clone(push->elem));

            return true_t;
}

void
    __list_del
        (__list* par)                           {
            while(par->begin.next != &par->end)
                __list_pop_front(par);
}

u64_t
    __list_size() {
        return sizeof(__list);
}

__list_elem*
    __list_push_back
        (__list* par, obj* par_push)                                 {
            __list_elem *ret = mem_new(par->res, sizeof(__list_elem));
            if (!ret) return 0;

            ret->next = &par->end	  ;
            ret->prev =  par->end.prev;

            ret->elem = ref(par_push);
            ret->list = par;

            par->end.prev->next = ret;
            par->end.prev       = ret;

            return ret;
}

__list_elem*
    __list_push_front
        (__list* par, obj* par_push)                                 {
            __list_elem *ret = mem_new(par->res, sizeof(__list_elem));
            if (!ret) return 0;

            ret->next =  par->begin.next;
            ret->prev = &par->begin     ;

            ret->elem = ref(par_push);
            ret->list = par;
            
            par->begin.next->prev = ret;
            par->begin.next       = ret;

            return ret;
}

__list_elem*
    __list_push_at
        (__list* par, obj* par_push, __list_elem* par_at)            {
            __list_elem *ret = mem_new(par->res, sizeof(__list_elem));
            if (!ret) return 0;

            ret->prev = par_at       ;
            ret->next = par_at->next ;

            ret->elem = ref(par_push);
            ret->list = par          ; par_at->next = ret;

            return ret;
}

void
    __list_pop_front
        (__list* par)                              {
            __list_elem *ret_elem = par->begin.next; 
            if (ret_elem == &par->end) 
                return;

            obj *ret = ret_elem->elem;
                       ret_elem->prev->next = ret_elem->next;
                       ret_elem->next->prev = ret_elem->prev;

            mem_del(par->res, ret_elem);
            del    (ret)               ;
}

void
    __list_pop_back
        (__list* par)                            {
            __list_elem *ret_elem = par->end.prev; 
            if (ret_elem == &par->begin)
                return;
            
            obj *ret = ret_elem->elem;
                       ret_elem->prev->next = ret_elem->next;
                       ret_elem->next->prev = ret_elem->prev;

            mem_del(par->res, ret_elem);
            del    (ret)               ;
}

void
    __list_pop_at
        (__list* par, __list_elem* par_at) {
            obj *ret = par_at->elem; 
            if (par_at->list != par)
                return;

            par_at->prev->next = par_at->next;
            par_at->next->prev = par_at->prev;

            mem_del(par->res, par_at);
            del    (ret)             ;
}

bool_t
    __list_empty
        (__list* par) {
            return par->begin.next == &par->end;
}

void
	__list_iter
		(__list* par, __iter* par_it)	  	  {
			par_it->iter  =  par->begin.next  ;
			par_it->trait = &__list_iter_trait;
}

void*
	__list_iter_next
		(__list_elem* par) {
			if (par->next == &par->list->end)
				return 0;

			return par->next;
}

void* 
	__list_iter_get
		(__list_elem* par)				{ 
			return (par) ? par->elem : 0;
}

void*
	__list_iter_set
		(__list_elem* par, void* par_set) {
			if (par == &par->list->end)
				return 0;

			void*  ret = par->elem; par->elem = par_set;
			return ret;
}