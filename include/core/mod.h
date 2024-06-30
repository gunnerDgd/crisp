#ifndef CORE_MOD_H
#define CORE_MOD_H

struct obj_trait;
struct obj      ;

struct mod                 {
    struct obj_trait *trait;
    struct obj       *mod  ;
};

bool_t mod_do_new(struct mod*);
void   mod_do_del(struct mod*);

#define dep(name) { (obj_trait*)name##_t, (obj*)&name },
#define use(...)               \
    bool_t mod_new()         { \
        struct mod mod[] =   { \
            __VA_ARGS__        \
            { null_t, null_t } \
        };                     \
        return mod_do_new(mod);\
    }                          \
                               \
    void mod_del()           { \
        struct mod mod[] =   { \
            __VA_ARGS__        \
            { null_t, null_t } \
        };                     \
        mod_do_del(mod);       \
    }

#endif
