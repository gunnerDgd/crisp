#ifndef __CORE_MOD_H__
#define __CORE_MOD_H__

struct obj_trait;
struct obj      ;

struct mod                 {
    struct obj_trait *trait;
    struct obj       *mod  ;
};

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
};

#define dep(name) { (obj_trait*)name##_t, (obj*)&name }
#define use(...)               \
    bool_t mod_new()         { \
        struct mod mod[] =   { \
            __VA_ARGS__      , \
            { null_t, null_t } \
        };                     \
        return mod_do_new(mod);\
    }                          \
                               \
    void mod_del()           { \
        struct mod mod[] =   { \
            __VA_ARGS__      , \
            { null_t, null_t } \
        };                     \
        mod_do_del(mod);       \
    }

#endif
