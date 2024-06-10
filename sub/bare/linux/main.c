#include "abi.h"
#include "proc.h"
#include "fs.h"

int  do_run();
void _start()     {
    exit(do_run());
}