#ifndef __POSIX_THD_H__
#define __POSIX_THD_H__
#ifdef PRESET_FEATURE_THREAD

#include "../core.h"

extern obj_trait *thd_t;
typedef struct    thd  { u8_t thd[128]; } thd;

fut*   thd_fut(thd*);

#endif
#endif