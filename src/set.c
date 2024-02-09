#include "set.h"
#include "bit.h"

obj_trait set_root_trait     = {
    .on_new   = &set_root_new  ,
    .on_clone = &set_root_clone,
    .on_ref   = 0              ,
    .on_del   = &set_root_del  ,
    .size     = sizeof(set_root)
};

obj_trait *set_root_t = &set_root_trait;

bool_t 
    set_root_new
        (set_root* par_root, u32_t par_count, va_list par)       {
            mem_set(par_root->node, 0x00, sizeof(par_root->node));
            mem_set(par_root->sub , 0x00, sizeof(par_root->sub)) ;

            par_root->sub_count =  0;
            par_root->free      =  0;
            par_root->use       = -1;
            return true_t;
}

bool_t 
    set_root_clone
        (set_root* par, set_root* par_clone) {
            return false_t;
}

void   
    set_root_del
        (set_root* par)                                                  {
            for (u64_t i = 0; i < par->sub_count ; ++i) del(par->sub [i]);
            for (u64_t i = 0; i < PRESET_ARCH_BIT; ++i) del(par->node[i]);
}

obj* 
    set_root_acq
        (set_root* par)                              {
            if (!par)                        return 0;
            if (trait_of(par) != set_root_t) return 0;
            if (!par->free)                                  {
                for (u64_t i = 0 ; i < par->sub_count ; ++i) {
                    obj *acq = set_root_acq(par->sub[i]);
                    if  (acq) return acq;
                }

                return 0;
            }

            u64_t acq_idx = bsr(par->free) ; if (acq_idx >= 64) return 0;
            par->free    ^= shl(1, acq_idx);
            par->use     |= shl(1, acq_idx);
            
            obj   *acq = par->node[acq_idx]; par->node[acq_idx] = 0;
            del   (acq);
            return acq;
}

bool_t 
    set_root_rel
        (set_root* par, obj* par_rel)                {
            if (!par)                        return 0;
            if (trait_of(par) != set_root_t) return 0;
            if (!par->use)                                    {
                if (par->sub_count >= PRESET_ARCH_BIT)        {
                    for (u64_t i = 0; i < PRESET_ARCH_BIT; ++i)
                        if (set_root_rel(par->sub[i], par_rel))
                            return true_t;
                }
                
                set_root* root = make(set_root_t) from(0);
                if (!root)                        return false_t;
                if (trait_of(root) != set_root_t) return false_t;

                par->sub[par->sub_count] = root;
                par->sub_count++;
                return set_root_rel(root, par_rel);
            }

            u64_t rel_idx = bsr(par->use)  ; if (rel_idx >= PRESET_ARCH_BIT) return 0;
            par->use     ^= shl(1, rel_idx);
            par->free    |= shl(1, rel_idx);

            par->node[rel_idx] = ref(par_rel);
            return true_t;
}

obj_trait set_trait     = {
    .on_new   = &set_new  ,
    .on_clone = &set_clone,
    .on_ref   = 0         ,
    .on_del   = &set_del  ,
    .size     = sizeof(set)
};

obj_trait *set_t = &set_trait;

bool_t 
    set_new
        (set* par_set, u32_t par_count, va_list par) {
            par_set->set = make (set_root_t) from (0);

            if (!par_set->set) return false_t;
            return true_t;
}

bool_t 
    set_clone
        (set* par, set* par_clone) {
            return false_t;
}

void   
    set_del
        (set* par)       {
            del(par->set);
}

obj* 
    set_acq
        (set* par)                              {
            if (!par)                   return 0;
            if (trait_of(par) != set_t) return 0;
            return set_root_acq(par->set);
}

void   
    set_rel
        (set* par, obj* par_rel)                       {
            if (!par_rel)                        return;
            if (!par)                            return;
            if (trait_of(par) != set_t)          return;

            if (set_root_rel(par->set, par_rel)) return; set_root* root = make (set_root_t) from (0);
            if (!root)                           return;
            root->sub_count = 1       ;
            root->sub[0]    = par->set;
            par ->set       = root     ;
}