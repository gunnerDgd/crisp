#ifndef __CORE_H__
#define __CORE_H__

#include "core/atom.h"
#include "core/bit.h"
#include "core/endian.h"

#include "core/mem.h"
#include "core/box.h"

#include "core/macro.h"

#include "core/cpu.h"
#include "core/task.h"
#include "core/this.h"
#include "core/fut.h"

#include "core/type.h"
#include "core/obj.h"
#include "core/ops.h"

extern obj_trait* core_t;
struct            core  {
    obj  head;
    mem *mem ;
};

extern struct core core;
bool_t core_new  (struct core*, u32_t, va_list);
bool_t core_clone(struct core*, struct core*)  ;
bool_t core_ref  (struct core*)                ;
void   core_del  (struct core*)                ;

#endif