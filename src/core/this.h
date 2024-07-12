#ifndef CORE_THIS_H
#define CORE_THIS_H

#include "obj.h"
#include "mod.h"

struct task;

extern obj_trait *this_t;
struct            this  {
    obj          head;
    struct task *task;
    any_t      (*run)(any_t);
    any_t        arg;
    any_t        ret;
};

#ifdef CRISP_TLS
#ifdef PRESET_COMPILER_GCC
extern __thread struct this this;
#endif

#ifdef PRESET_COMPILER_MSVC
extern __declspec(thread) struct this this;
#endif

#endif

#endif