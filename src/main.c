#include "core.h"

int run  ();
int main (int argc, char** argv)                 {
    if (!make_at(&core, core) from (0)) return -1;
#ifdef PRESET_FEATURE_LIBC
#include "libc.h"
    if (!make_at(&libc, libc) from (0)) return -2;
#endif
    if (!mod_new())                     return -3;

    if (!obj_new_at(&this, this_t, 2, run, null_t)) return -4;
    del(&this);
    mod_del ();
    return   0;
}