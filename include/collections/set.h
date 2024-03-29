#ifndef __COLLECTIONS_SET_H__
#define __COLLECTIONS_SET_H__

#include "../core.h"

extern obj_trait* set_t;
typedef struct    set { u8_t set[64]; } set;

obj* set_acq(set*)      ;
void set_rel(set*, obj*);

#endif