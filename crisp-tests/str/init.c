#include "crisp/str.h"
#include "crisp/alloc.h"

#include <stdio.h>

int main() {
	c_str_t     		  str;
	c_str_init			(&str, c_global_alloc());
	c_str_push_back_cstr(&str, "Hello World");

	printf("String Length : %d\nString Value : %s", c_str_len(&str), c_str_ptr(&str));
}