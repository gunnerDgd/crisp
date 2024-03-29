#ifndef __MTX_H__
#define __MTX_H__

#ifdef PRESET_FEATURE_THREAD

#ifdef PRESET_LINUX
#include "linux/mtx.h"
#endif

#ifdef PRESET_WIN32
#include "win32/mtx.h"
#endif

#endif
#endif