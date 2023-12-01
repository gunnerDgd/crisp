#include "list.h"
#include "details/list.h"

obj_trait* list_t = &__list_trait;

list_elem
    list_push_back
        (list* par, obj* par_push)               {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_push)               return 0;

            return __list_push_back(par, par_push);
}

list_elem
    list_push_front
        (list* par, obj* par_push)               {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_push)               return 0;

            return __list_push_front(par, par_push);
}

list_elem
    list_push
        (list* par, obj* par_push, list_elem par_at) {
            if (!par)                        return 0;
            if (trait_of(par) != list_t)     return 0;
            if (!par_at)                     return 0;
            if (!par_push)                   return 0;

            return __list_push(par, par_push, par_at);
}

obj*
    list_pop_front
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return __list_pop_front(par);
}

obj*
    list_pop_back
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return __list_pop_back(par);
}

obj*
    list_pop
        (list* par, list_elem par_at)            {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_at)                 return 0;

            return __list_pop(par, par_at);
}


bool_t
    list_empty
        (list* par)                                   {
            if (!par)                    return true_t;
            if (trait_of(par) != list_t) return true_t;

            return __list_empty(par);
}

list_elem
    list_begin
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return ((__list*)par)->begin.next;
}

list_elem 
    list_end
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return &((__list*)par)->end;
}

list_elem
    list_next
        (list_elem par)           {
            __list_elem* ret = par;

            if(!ret)                    return               0;
            if(!ret->list)              return               0;
            if (ret == &ret->list->end) return &ret->list->end;

            return ret->next;
}

list_elem
    list_prev
        (list_elem par)           {
            __list_elem* ret = par;

            if (!ret)                           return   0;
            if (!ret->list)                     return   0;
            if (ret->prev == &ret->list->begin) return ret;

        return ret->prev;
}

obj*
    list_get
        (list_elem par)           {
            __list_elem* ret = par;

            if (!ret)       return 0;
            if (!ret->list) return 0;

            return ret->elem;
}

obj*
    list_set
        (list_elem par, obj* par_set)             {
            __list_elem *ret_elem = par           ;
            obj         *ret      = ret_elem->elem;

            if (!ret_elem)       return 0;
            if (!ret_elem->list) return 0;
            if (!par_set)        return 0;

            del   (ret); ret_elem->elem = ref(par_set);
            return ret ;
}