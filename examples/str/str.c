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

	cstr_t cstr0 = cstr("Hello ");
	cstr_t cstr1 = cstr("World") ;
	cstr_t cstr2 = cstr(" ")	 ;

	str_push_back_cstr(&str, cstr0);
	str_push_back_cstr(&str, cstr1);

	printf("Before Pop At : %s\n", str_as_raw(&str)); str_pop(&str, 5, 1);
	printf("After Pop At : %s\n" , str_as_raw(&str));

	str_push_cstr(&str, 5, cstr2, 1);
	printf("After Push At : %s\n", str_as_raw(&str))								;
	printf("Find Result : %s\n"  , str_as_raw(&str) + str_find_cstr(&str, 0, cstr1));

	del(&str);
}