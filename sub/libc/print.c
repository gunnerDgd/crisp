#include "../../src/core.h"
#include <stdio.h>

void println_va(const char* str, va_list arg) { vprintf(str, arg); printf("\n"); }
void print_va  (const char* str, va_list arg) { vprintf(str, arg); }

void
    println
        (const char* str, ...) {
            va_list  arg;
            va_start(arg, str); println_va(str, arg);
            va_end  (arg);
}

void
    print
        (const char* str, ...) {
            va_list  arg;
            va_start(arg, str); print_va(str, arg);
            va_end  (arg);
}