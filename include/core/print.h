#ifndef CORE_PRINT_H
#define CORE_PRINT_H

#include "type.h"

void println_va(const char*, va_list);
void println   (const char*, ...)    ;

void print_va  (const char*, va_list);
void print     (const char*, ...)    ;

#endif
