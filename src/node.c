#include "node.h"
#include "atom.h"

obj_trait node_trait = make_trait (
    node_new    ,
    node_clone  ,
    null_t      ,
    node_del    ,
    sizeof(node),
    null_t
);

obj_trait* node_t = &node_trait;

bool_t 
    node_new
        (node* par_cur, u32_t par_count, va_list par)                             {
            obj* node     = null_t   ; if (par_count > 0) node = va_arg(par, obj*);
            par_cur->node = ref(node);
            par_cur->next = null_t   ;
            par_cur->prev = null_t   ;
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
        (node* par)                                   {
            if (!par)                    return null_t;
            if (trait_of(par) != node_t) return null_t;
            return par->node;
}

node*
    node_next
        (node* par, node* par_next)                            {
            if (!par)                             return null_t;
            if (trait_of(par) != node_t)          return null_t;
            if (par_next)                                      {
                if (trait_of(par_next) != node_t) return null_t;
                par     ->next = par_next;
                par_next->prev = par     ;
                return par_next;
            }

            return par->next;
}

node*
    node_prev
        (node* par, node* par_prev)                            {
            if (!par)                             return null_t;
            if (trait_of(par) != node_t)          return null_t;
            if (par_prev)                                      {
                if (trait_of(par_prev) != node_t) return null_t;
                par     ->prev = par_prev;
                par_prev->next = par     ;
                return par_prev;
            }

            return par->prev;
}