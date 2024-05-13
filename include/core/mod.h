#ifndef __CORE_MOD_H__
#define __CORE_MOD_H__

struct obj_trait;
struct obj      ;

struct mod                 {
    struct obj_trait *trait;
    struct obj       *mod  ;
};

#define dep(name) { name##_t, &name }
#define use(...)              \
    bool_t mod_new()         {\
        struct mod mod[] =   {\
            __VA_ARGS__      ,\
            { null_t, null_t }\
        };                    \
        for (u64_t i = 0 ; ; ++i)   {\
            if (!mod[i].trait) break;\
            obj_new_at              (\
                mod[i].mod  ,        \
                mod[i].trait,        \
                0                    \
            );                       \
        }             \
        return true_t;\
    }                 \
    void mod_del()           {\
        struct mod mod[] =   {\
            __VA_ARGS__      ,\
            { null_t, null_t }\
        };                    \
        for (u64_t i = 0 ; ; ++i)   {\
            if (!mod[i].trait) break;\
            obj_del(mod[i].mod);     \
        }                            \
    }

#endif
