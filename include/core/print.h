#ifndef __PRINT_H__
#define __PRINT_H__

#include "type.h"

void println_va(const char*, va_list);
void println   (const char*, ...)    ;

void print_va  (const char*, va_list);
void print     (const char*, ...)    ;

#endif
