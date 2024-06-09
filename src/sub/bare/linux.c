#include "../../core.h"

#include <string.h>

int  run   ();
void _start()                                 {
    if (!make_at(&core, core) from (0)) return;
    if (!mod_new())                     return;
    bool_t res = obj_new_at                   (
        &this ,
        this_t,
        2     ,
        run   ,
        null_t
    );

    if (!res) return;
    del(&this);
    mod_del ();

    asm                 (
        "movl $1  ,%eax;"
        "xorl %ebx,%ebx;"
        "int  $0x80"
    );
}