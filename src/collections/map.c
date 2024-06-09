#include "map.h"

obj_trait map_trait = make_trait (
    map_new    ,
    map_clone  ,
    null_t     ,
    map_del    ,
    sizeof(map),
    null_t
);

obj_trait* map_t = &map_trait;

bool_t    
    map_new
        (map* par_map, u32_t par_count, va_list par)                      {
            mem *mem = null_t; if (par_count > 1) mem = va_arg(par, void*);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t ;

            if (!make_at(&par_map->map, list) from(1, mem)) return false_t;
            return true_t;
}

bool_t    
    map_clone
        (map* par, map* par_clone)                                   {
            if (!clone_at(&par->map, &par_clone->map)) return false_t;
            return true_t;
}

void
    map_del
        (map* par)         {
            del (&par->map);
}

node*
    map_push
        (map* self, obj* push)                        {
            if (trait_of(self) != map_t) return null_t;
            list_for (&self->map, pos)                    {
                if (op_eq(push, value(pos))) return null_t;
                if (op_gt(push, value(pos))) continue;
                node *cur = make (node) from (1, push);

                if (trait_of(cur) != node_t) return null_t;
                return next_as(cur, pos);
            }
            return list_push_back(&self->map, push);
}

node*
    map_move
        (map* self, obj* move)                          {
            if (trait_of (self) != map_t)  return null_t;
            node *ret = map_push (self, move);

            if (trait_of(ret) != node_t) return null_t;
            del (move);
            return ret;
}

void      
    map_pop
        (map* self, any_t key)                 {
            if (trait_of(self) != map_t) return;

            node *pop = map_find(self, key);
            if (trait_of(pop) != node_t) return;
            del(pop);
}

node*
    map_find
        (map* self, any_t key)                        {
            if (trait_of(self) != map_t) return null_t;
            list_for (&self->map, pos)                  {
                if (op_ne_arg(value(pos), key)) continue;
                return pos;
            }

            return map_end(self);
}

bool_t    
    map_empty
        (map* par)                                    {
            if (trait_of(par) != map_t) return false_t;
            return list_empty(&par->map);
}

node*
    map_begin
        (map* par)                                   {
            if (trait_of(par) != map_t) return null_t;
            return list_begin(&par->map);
}

node*
    map_end
        (map* par)                                   {
            if (trait_of(par) != map_t) return null_t;
            return list_end(&par->map);
}