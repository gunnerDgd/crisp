#include <str.h>
#include <obj.h>
#include <stdio.h>

int main() {
	str* str = make(str_t) from (1, NULL);
	str_init(str, 0);

	str_push_back_cstr(str, "Hello ", 6);
	str_push_back_cstr(str, "World" , 5);
	str_pop_at		  (str, 5, 6);
	printf("Bool : %s\n", ptr_raw(str_ptr(str)));

	del(str);
}