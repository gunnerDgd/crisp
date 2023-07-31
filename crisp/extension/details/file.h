#ifndef CRISP_EXTENSION_DETAILS_FILE_H
#define CRISP_EXTENSION_DETAILS_FILE_H

#include <crisp/type.h>
#include <crisp/type_atomic.h>

typedef struct file_t {
#ifdef CRISP_PRESET_LINUX
    int handle;
#endif
}   file_t;

c_bool_t
    file_open
        ();

#endif
