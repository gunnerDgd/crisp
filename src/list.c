#include "list.h"

obj_trait list_trait     = {
    .on_new   = &list_new  ,
    .on_clone = &list_clone,
    .on_ref   =           0,
    .on_del   = &list_del  ,
    .size     = sizeof(list)
};

obj_trait* list_t = &list_trait;

bool_t
    list_new
        (list* par_list, u32_t par_count, va_list par)                              {
            par_list->res = (par_count == 1) ? va_arg(par, mem_res*) : get_mem_res();
            if (!par_list->res)             return false_t;
            if (!par_list->res->on_new)     return 0      ;
            if (!par_list->res->on_del)     return 0      ;
            if (!par_list->res->on_mem_new) return 0      ;
            if (!par_list->res->on_mem_del) return 0      ;

            par_list->begin.next = &par_list->end;
            par_list->begin.prev =              0;
            par_list->begin.elem =              0;

            par_list->end.prev   = &par_list->begin;
            par_list->end.next   = 0               ;
            par_list->end.elem   = 0               ;

            return true_t;
}

bool_t
    list_clone
        (list* par, list* par_clone)           {
            if (!par)            return false_t;
            if (!par_clone)      return false_t;
            if (!par_clone->res) return false_t;

            par->begin.next = &par->end;
            par->begin.prev = 0        ;

            par->end.prev   = &par->begin   ;
            par->end.next   = 0             ;
            par->res        = par_clone->res;

            list_elem *push = par_clone->begin.next;
            while     (push != &par_clone->end) list_push_back(par, push->elem);

            return true_t;
}

void
    list_del
        (list* par)                            {
            while(par->begin.next != &par->end)
                list_pop_front(par);
}

list_elem*
    list_push_back
        (list* par, obj* par_push)               {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_push)               return 0;
            if (!trait_of(par_push))     return 0;

            if (!par->res) return 0; list_elem* ret = mem_new(par->res, sizeof(list_elem));
            if (!ret)      return 0;

            ret->elem = ref(par_push);
            ret->list = par          ;

            ret->next = &par->end     ;
            ret->prev =  par->end.prev;

            par->end.prev->next = ret;
            par->end.prev       = ret;

            return ret;
}

list_elem*
    list_push_front
        (list* par, obj* par_push)               {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_push)               return 0;
            if (!trait_of(par_push))     return 0;

            if (!par->res) return 0; list_elem *ret = mem_new(par->res, sizeof(list_elem));
            if (!ret)      return 0;

            ret->elem = ref(par_push);
            ret->list = par;

            ret->next =  par->begin.next;
            ret->prev = &par->begin     ;
            
            par->begin.next->prev = ret;
            par->begin.next       = ret;

            return ret;
}

list_elem*
    list_push
        (list* par, obj* par_push, list_elem* par_at) {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_at)                 return 0;
            if (!par_push)               return 0;
            if (!trait_of(par_push))     return 0;

            if (!par->res)               return 0;
            if (par_at->list != par)     return 0;
            if (par_at == &par->end)     return list_push_back (par, par_push);
            if (par_at == &par->begin)   return list_push_front(par, par_push);

            list_elem* ret = mem_new(par->res, sizeof(list_elem));
            if (!ret) return 0;

            ret->prev = par_at      ;
            ret->next = par_at->next;

            ret->elem = ref(par_push);
            ret->list = par          ; par_at->next = ret;

            return ret;
}

obj*
    list_pop_front
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            list_elem *pop = par->begin.next;
            if (pop == &par->end)   return 0;
            if (pop == &par->begin) return 0;
            if (pop->list != par)   return 0;

            pop->prev->next = pop->next;
            pop->next->prev = pop->prev;

            obj*   ret = (del(pop->elem)) ? pop->elem : 0; mem_del(par->res, pop);
            return ret;
}

obj*
    list_pop_back
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            list_elem *pop = par->end.prev;
            if (pop == &par->begin) return 0;
            if (pop == &par->end)   return 0;
            if (pop->list != par)   return 0;
                        
            pop->prev->next = pop->next;
            pop->next->prev = pop->prev;

            obj*   ret = (del(pop->elem)) ? pop->elem : 0; mem_del(par->res, pop);
            return ret;
}

obj*
    list_pop
        (list* par, list_elem* par_at)           {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;
            if (!par_at)                 return 0;

            if (par_at == &par->begin) return list_pop_front(par);
            if (par_at == &par->end)   return list_pop_back (par);
            if (par_at->list != par)   return 0;

            par_at->prev->next = par_at->next;
            par_at->next->prev = par_at->prev;

            obj*   ret = (del(par_at->elem)) ? par_at->elem : 0; mem_del(par->res, par_at);
            return ret;
}


bool_t
    list_empty
        (list* par)                                   {
            if (!par)                    return true_t;
            if (trait_of(par) != list_t) return true_t;

            return par->begin.next == &par->end;
}

list_elem*
    list_begin
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return par->begin.next;
}

list_elem*
    list_end
        (list* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != list_t) return 0;

            return &par->end;
}

list_elem*
    list_next
        (list_elem* par)                                      {
            if (!par)                   return 0              ;
            if (!par->list)             return 0              ;
            if (par == &par->list->end) return &par->list->end;

            return par->next;
}

list_elem*
    list_prev
        (list_elem* par)                                  {
            if (!par)                           return   0;
            if (!par->list)                     return   0;
            if (trait_of(par->list) != list_t)  return   0;
            if (par->prev == &par->list->begin) return par;

            return par->prev;
}

obj*
    list_get
        (list_elem* par)                               {
            if (!par)                          return 0;
            if (!par->list)                    return 0;
            if (trait_of(par->list) != list_t) return 0;

            if (par == &par->list->begin)      return 0;
            if (par == &par->list->end)        return 0;

            return par->elem;
}

obj*
    list_set
        (list_elem* par, obj* par_set)                 {
            obj *ret = (del(par->elem)) ? par->elem : 0;

            if (!par)                          return 0;
            if (!par->list)                    return 0;
            if (trait_of(par->list) != list_t) return 0;
            if (!par_set)                      return 0;

            if (par == &par->list->begin)      return 0;
            if (par == &par->list->end)        return 0;

            par->elem = ref(par_set);
            return ret;
}