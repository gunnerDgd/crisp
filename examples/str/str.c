#include <str.h>
#include <obj.h>

#include <stdio.h>
#include <stdlib.h>

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem		     = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

int main()			  {
	set_mem(&cstd_mem);
	str str			  ; if (!make_at(&str, str_t) from(0)) return false_t;

	str_push_back_cstr(&str, "Hello ", 6);
	str_push_back_cstr(&str, "World" , 5);

	printf("Before Pop At : %s\n", str_ptr(&str)); str_pop(&str, 5, 1);
	printf("After Pop At : %s\n" , str_ptr(&str));

	str_push_cstr(&str, 5, " ", 1);
	printf("After Push At : %s\n", str_ptr(&str))									  ;
	printf("Find Result : %s\n"  , str_ptr(&str) + str_find_cstr(&str, 0, "World", 5));

	del(&str);
}