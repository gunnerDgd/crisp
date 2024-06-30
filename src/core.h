#ifndef CORE_H
#define CORE_H

#include "core/atom.h"
#include "core/bit.h"
#include "core/endian.h"
#include "core/mod.h"

#include "core/mem.h"
#include "core/box.h"

#include "core/macro.h"
#include "core/print.h"

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

#endif