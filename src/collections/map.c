#include "map.h"

static bool_t
    do_new
        (map* self, u32_t count, va_list arg)                         {
            mem *mem = null_t; if (count > 1) mem = va_arg(arg, any_t);
            if (trait_of(mem) != mem_t) mem = get_mem();
            if (trait_of(mem) != mem_t) return false_t ;

            if (!make_at(&self->map, list) from(1, mem)) return false_t;
            return true_t;
}

static bool_t
    do_clone
        (map* self, map* clone)                                   {
            if (!clone_at(&self->map, &clone->map)) return false_t;
            return true_t;
}

static void
    do_del
        (map* self)         {
            del (&self->map);
}

static obj_trait
    do_obj = make_trait (
        do_new     ,
        do_clone   ,
        null_t     ,
        do_del     ,
        sizeof(map),
        null_t
);

obj_trait* map_t = &do_obj;



pos*
    map_push
        (map* self, any_t push)                       {
            if (trait_of(self) != map_t) return null_t;
            list_for (&self->map, cur)                  {
                if (eq(push, as_any(cur))) return null_t;
                if (gt(push, as_any(cur))) continue;
                pos *new = make (pos) from (1, push);

                if (trait_of(new) != pos_t) return null_t;
                return next_as(new, cur);
            }
            return list_push_back(&self->map, push);
}

pos*
    map_move
        (map* self, any_t* move)                        {
            if (trait_of (self) != map_t)  return null_t;
            pos *ret = map_push (self, move);

            if (trait_of(ret) != pos_t) return null_t;
            *move = null_t;
            return ret;
}

void      
    map_pop
        (map* self, any_t key)                 {
            if (trait_of(self) != map_t) return;

            pos *pop = map_find(self, key);
            if (trait_of(pop) != pos_t) return;
            del(pop);
}

pos*
    map_find
        (map* self, any_t key)                        {
            if (trait_of(self) != map_t) return null_t;
            list_for (&self->map, pos)                {
                if (ne_arg(as_any(pos), key)) continue;
                return pos;
            }

            return map_end(self);
}

bool_t map_empty(map* self) { if (trait_of(self) != map_t) return false_t; return list_empty(&self->map); }
pos*   map_begin(map* self) { if (trait_of(self) != map_t) return null_t;  return list_begin(&self->map); }
pos*   map_end  (map* self) { if (trait_of(self) != map_t) return null_t;  return list_end  (&self->map); }