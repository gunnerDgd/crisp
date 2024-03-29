#include "list.h"

obj_trait list_trait = make_trait (
    list_new    ,
    list_clone  ,
    null_t      ,
    list_del    ,
    sizeof(list),
    null_t
);

obj_trait* list_t = &list_trait;

bool_t
    list_new
        (list* par_list, u32_t par_count, va_list par)           {
            switch (par_count)                                   {
                case 0 : par_list->mem = get_mem()        ; break;
                case 1 : par_list->mem = va_arg(par, mem*); break;
                default: return false_t;
            }

            if (!par_list->mem)                             return false_t;
            if (!par_list->mem->on_new)                     return false_t;
            if (!par_list->mem->on_del)                     return false_t;

            if (!make_at(&par_list->begin, node) from(0))   return false_t;
            if (!make_at(&par_list->end  , node) from(0))   return false_t;
            if (!next_as(&par_list->begin, &par_list->end)) return false_t;
            return true_t;
}

bool_t
    list_clone
        (list* par, list* par_clone)                                    {
            if (!par_clone->mem)                          return false_t;
            if (!par_clone->mem->on_new)                  return false_t;
            if (!par_clone->mem->on_del)                  return false_t;

            if (!make_at(&par->begin, node) from(0))      return false_t;
            if (!make_at(&par->end  , node) from(0))      return false_t;

            if (!next_as(&par->begin, &par_clone->end))   return false_t;
            if (!prev_as(&par->end  , &par_clone->begin)) return false_t;

            par->mem = par_clone->mem;
            list_for(par_clone, push)                        {
                node* ret = make (node) from (1, value(push));
                list_push_back(par, ret);
            }

            return true_t;
}

void
    list_del
        (list* par)                               {
            while(next(&par->begin) != &par->end) {
                list_pop_back(par);
            }
}

node*
    list_push_back
        (list* par, obj* par_push)                    {
            if (!par_push)               return null_t;
            if (!par)                    return null_t;
            if (trait_of(par) != list_t) return null_t;
            
            node *ret = obj_new(par->mem, node_t, 1, par_push);
            if (!ret)                    return null_t;
            if (trait_of(ret) != node_t) return null_t;

            prev_as(ret, prev(&par->end));
            prev_as(&par->end, ret)      ;
            return  ret;
}

node*
    list_push_front
        (list* par, obj* par_push)                    {
            if (!par_push)               return null_t;
            if (!par)                    return null_t;
            if (trait_of(par) != list_t) return null_t;
            
            node *ret = obj_new(par->mem, node_t, 1, par_push);
            if (!ret)                    return null_t;
            if (trait_of(ret) != node_t) return null_t;
            
            next_as(ret, next(&par->begin));
            next_as(&par->begin, ret)      ;
            return  ret;
}

obj*
    list_pop_front
        (list* par)                                   {
            if (!par)                    return null_t;
            if (trait_of(par) != list_t) return null_t;
            if (list_empty(par))         return null_t;

            node *ret_cur = next (&par->begin);
            obj  *ret     = value(ret_cur)    ;
            if (use_count(ret) == 1) {
                del(ret_cur);
                return 0;
            }

            del   (ret_cur);
            return ret     ;
}

obj*
    list_pop_back
        (list* par)                                   {
            if (!par)                    return null_t;
            if (trait_of(par) != list_t) return null_t;
            if (list_empty(par))         return null_t;

            node *ret_cur = prev (&par->end);
            obj  *ret     = value(ret_cur)  ;
            if (use_count(ret) == 1) {
                del (ret_cur);
                return null_t;
            }

            del   (ret_cur);
            return ret     ;
}

bool_t
    list_empty
        (list* par)                                   {
            if (!par)                    return true_t;
            if (trait_of(par) != list_t) return true_t;

            return next(&par->begin) == &par->end;
}

node*
    list_begin
        (list* par)                                   {
            if (!par)                    return null_t;
            if (trait_of(par) != list_t) return null_t;
            return par->begin.next;
}

node*
    list_end
        (list* par)                                   {
            if (!par)                    return null_t;
            if (trait_of(par) != list_t) return null_t;
            return &par->end;
}