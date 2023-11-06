#include <str.h>
#include <stdio.h>

int main() {
	str Str;
	str_init(&Str, 0);

	str_push_back_cstr(&Str, "Hello ", 6);
	str_push_back_cstr(&Str, "World" , 5);
	printf("Bool : %s\n", ptr_raw(str_ptr(&Str)));
	str_pop_at		  (&Str, 5, 1);

	printf("Bool : %s\n", ptr_raw(str_ptr(&Str)));
}