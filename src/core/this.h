#ifndef __THIS_H__
#define __THIS_H__

#include "obj.h"

struct task;

extern obj_trait *this_t;
struct            this  {
    obj          head;
    struct task *task;
};

#ifdef PRESET_FEATURE_THREAD
#ifdef PRESET_COMPILER_GCC
extern __thread struct this *this;
#endif
#else
extern struct this          *this;
#endif

bool_t this_new  (struct this*, u32_t, va_list);
bool_t this_clone(struct this*, struct this*)  ;
bool_t this_ref  (struct this*)                ;
void   this_del  (struct this*)                ;

#endif