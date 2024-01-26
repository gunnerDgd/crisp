#include "node.h"
#include "atom.h"

obj_trait node_trait     = {
    .on_new   = &node_new  ,
    .on_clone = &node_clone,
    .on_ref   = 0          ,
    .on_del   = &node_del  ,
    .size     = sizeof(node)
};

obj_trait* node_t = &node_trait;

bool_t 
    node_new
        (node* par_cur, u32_t par_count, va_list par)                             {
            obj* node     = 0        ; if (par_count > 0) node = va_arg(par, obj*);
            par_cur->node = ref(node);
            par_cur->next = 0        ;
            par_cur->prev = 0        ;
            return true_t;
}

bool_t 
    node_clone
        (node* par, node* par_clone) {
            return false_t;
}

void   
    node_del
        (node* par)                                   {
            if (par->prev) par->prev->next = par->next;
            if (par->next) par->next->prev = par->prev;
            del(par->node);
}

obj* 
    node_value
        (node* par)                              {
            if (!par)                    return 0;
            if (trait_of(par) != node_t) return 0;
            return par->node;
}

node*
    node_next
        (node* par, node* par_next)                       {
            if (!par)                             return 0;
            if (trait_of(par) != node_t)          return 0;
            if (par_next)                                 {
                if (trait_of(par_next) != node_t) return 0;
                par     ->next = par_next;
                par_next->prev = par     ;
                return par_next;
            }

            return par->next;
}

node*
    node_prev
        (node* par, node* par_prev)                       {
            if (!par)                             return 0;
            if (trait_of(par) != node_t)          return 0;
            if (par_prev)                                 {
                if (trait_of(par_prev) != node_t) return 0;
                par     ->prev = par_prev;
                par_prev->next = par     ;
                return par_prev;
            }

            return par->prev;
}