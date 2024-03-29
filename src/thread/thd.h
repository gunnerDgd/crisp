#ifndef __THD_H__
#define __THD_H__

#ifdef PRESET_FEATURE_THREAD

#ifdef PRESET_LINUX
#include "linux/thd.h"
#endif

#ifdef PRESET_WIN32
#include "win32/thd.h"
#endif

#endif
#endif