#ifndef __CORE_MOD_H__
#define __CORE_MOD_H__

#include "type.h"

struct obj_trait;
struct obj      ;

struct mod                 {
    struct obj_trait *trait;
    struct obj       *mod  ;
};

bool_t mod_new();
bool_t mod_del();

#endif
