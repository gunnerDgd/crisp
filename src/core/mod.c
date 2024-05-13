#include "obj.h"
#include "mod.h"

bool_t
    mod_do_new
        (struct mod* mod)                          {
            for (u64_t i = 0 ; mod[i].trait ; ++i) {
                if (trait_of(mod[i].mod)) {
                    ref (mod[i].mod);
                    continue;
                }

                if (!obj_new_at(mod[i].mod,mod[i].trait, 0)) return false_t;
            }

            return true_t;
}

void
    mod_do_del
        (struct mod* mod)                          {
            for (u64_t i = 0 ; mod[i].trait ; ++i) {
                del (mod[i].mod);
            }
}