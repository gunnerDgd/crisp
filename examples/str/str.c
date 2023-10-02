#include <str.h>
#include <stdio.h>

int main() {
	str Str;
	str_init(&Str, 0);

	str_push_back_cstr(&Str, "Hello ", 6);
	str_push_back_cstr(&Str, "World" , 5);

	printf("Bool : %d\n", str_eq_from_cstr(&Str, "Hello World", 11));
}