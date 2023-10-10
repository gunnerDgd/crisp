#include "crisp/str.h"
#include "crisp/alloc.h"

#include <stdio.h>

int main() {
	str     		    str;
	str_init		  (&str, get_default_alloc());
	str_push_back_cstr(&str, "Hello World");

	printf("String Length : %d\nString Value : %s", str_len(&str), str_ptr(&str));
}