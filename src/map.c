#include "map.h"

obj_trait map_trait     = {
    .on_new   = &map_new  ,
    .on_clone = &map_clone,
    .on_ref   = 0         ,
    .on_del   = &map_del  ,
    .size     = sizeof(map)
};

obj_trait* map_t = &map_trait;

bool_t    
    map_new
        (map* par_map, u32_t par_count, va_list par) {
            par_map->key = va_arg(par, map_key*);
            mem_res* res = (par_count == 1) ? get_mem_res() : va_arg(par, mem_res*);
            if (!res)                 return false_t;
            if (!par_map)             return false_t;

            if (!par_map->key->eq)    return false_t;
            if (!par_map->key->eq_va) return false_t;

            if (!par_map->key->lt)    return false_t;
            if (!par_map->key->lt_va) return false_t;
            
            if (!par_map->key->gt)    return false_t;
            if (!par_map->key->gt_va) return false_t;

            return make_at(&par_map->map, list_t) from (res);
}

bool_t    
    map_clone
        (map* par, map* par_clone)   {
            par->key = par_clone->key;

            if (par->key)                              return false_t;
            if (!clone_at(&par->map, &par_clone->map)) return false_t;

            return true_t;
}

void
    map_del
        (map* par)         {
            del (&par->map);
}

map_elem*
    map_push
        (map* par, obj* par_push)               {
            if (!par)                   return 0;
            if (trait_of(par) != map_t) return 0;

            list_for (&par->map, push_it)    {
                obj *push = list_get(push_it);
                if (!push) continue;
                if (par->key->lt(push, par_push)) list_push(&par->map, par_push, list_prev(push_it));
                if (par->key->eq(push, par_push)) return 0;
            }

            return list_push_back(&par->map, par_push);
}

void      
    map_pop
        (map* par, map_elem* par_pop)         {
            if (!par)                   return;
            if (trait_of(par) != map_t) return;

            list_pop(&par->map, par_pop);
}

map_elem*
    map_find
        (map* par_map, u32_t par_count, ...)        {
            if (!par_map)                   return 0;
            if (trait_of(par_map) != map_t) return 0;

            va_list  par;
            va_start(par, par_count); map_elem* ret = map_find_va(par_map, par_count, par);
            va_end  (par)           ;
            return   ret;
}

map_elem*
    map_find_va
        (map* par_map, u32_t par_count, va_list par) {
            if (!par_map)                   return 0;
            if (trait_of(par_map) != map_t) return 0;

            list_for (&par_map->map, find_it) {
                obj *find = list_get(find_it);
                if (!find)                                     continue      ;
                if (par_map->key->eq_va(find, par_count, par)) return find_it;
            }

            return 0;
}

obj*
    map_get
        (map* par, map_elem* par_elem)               {
            if (!par)                        return 0;
            if (!par_elem)                   return 0;

            if (trait_of(par) != map_t)      return 0;
            if (par_elem->list != &par->map) return 0;

            return par_elem->elem;
}

map_elem* 
    map_begin
        (map* par)                              {
            if (!par)                   return 0;
            if (trait_of(par) != map_t) return 0;

            return list_begin(&par->map);
}

map_elem* 
    map_end
        (map* par)                              {
            if (!par)                   return 0;
            if (trait_of(par) != map_t) return 0;

            return list_end(&par->map);
}

map_elem*
    map_next
        (map_elem* par)                         {
            if (!par)                   return 0;
            if (trait_of(par) != map_t) return 0;

            return list_next(par);
}
map_elem*
    map_prev
        (map_elem* par)                         {
            if (!par)                   return 0;
            if (trait_of(par) != map_t) return 0;

            return list_prev(par);
}