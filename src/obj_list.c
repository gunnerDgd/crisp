#include "obj_list.h"
#include "details/obj_list.h"

obj_trait* obj_list_t = &__obj_list_trait;

obj_list_elem
    obj_list_push_back
        (obj_list* par, obj* par_push)               {
            if (!par)                        return 0;
            if (trait_of(par) != obj_list_t) return 0;

            return __obj_list_push_back(par, par_push);
}

obj_list_elem
    obj_list_push_front
        (obj_list* par, obj* par_push)              {
            if (!par)                        return 0;
            if (trait_of(par) != obj_list_t) return 0;

            return __obj_list_push_front(par, par_push);
}

obj_list_elem
    obj_list_push_at
        (obj_list* par, obj* par_push, obj_list_elem par_at) {
            if (!par)                        return 0;
            if (trait_of(par) != obj_list_t) return 0;
            if (!par_at)                     return 0;

            return __obj_list_push_at(par, par_push, par_at);
}

obj*
    obj_list_pop_front
        (obj_list* par)                              {
            if (!par)                        return 0;
            if (trait_of(par) != obj_list_t) return 0;

            return __obj_list_pop_front(par);
}

obj*
    obj_list_pop_back
        (obj_list* par)                              {
            if (!par)                        return 0;
            if (trait_of(par) != obj_list_t) return 0;

            return __obj_list_pop_back(par);
}

obj*
    obj_list_pop_at
        (obj_list* par, obj_list_elem par_at)        {
            if (!par)                        return 0;
            if (trait_of(par) != obj_list_t) return 0;

            return __obj_list_pop_at(par, par_at);
}


bool_t
    obj_list_empty
        (obj_list* par)                                   {
            if (!par)                        return true_t;
            if (trait_of(par) != obj_list_t) return true_t;

            return __obj_list_empty(par);
}

obj_list_elem obj_list_begin(obj_list* par) { return (par) ?  ((__obj_list*)par)->begin.next : 0; }
obj_list_elem obj_list_end  (obj_list* par) { return (par) ? &((__obj_list*)par)->end        : 0; }

obj_list_elem
    obj_list_next(obj_list_elem par)  {
        __obj_list_elem* ret = par;

        if(!ret)                    return 0;
        if(!ret->list)              return 0;
        if (ret == &ret->list->end) return 0;

        return ret->next;
}

obj_list_elem
    obj_list_prev(obj_list_elem par)  {
        __obj_list_elem* ret = par;

        if (!ret)                           return 0;
        if (!ret->list)                     return 0; 
        if (ret->prev == &ret->list->begin) return 0;

        return ret->prev;
}

obj*
    obj_list_get(obj_list_elem par)   {
        __obj_list_elem* ret = par;

        if (!ret)       return 0;
        if (!ret->list) return 0;

        return ret->elem;
}

obj*
    obj_list_set
        (obj_list_elem par, obj* par_set)             {
            __obj_list_elem *ret_elem = par           ;
            obj             *ret      = ret_elem->elem;

            if (!ret_elem)       return 0;
            if (!ret_elem->list) return 0;

            del   (ret); ret_elem->elem = ref(par_set);
            return ret ;
}