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
	str *Str = make(str) from(0);

	cstr_t cstr0 = cstr("Hello ");
	cstr_t cstr1 = cstr("World") ;
	cstr_t cstr2 = cstr(" ")	 ;

	str_push_back_cstr(Str, cstr0);
	str_push_back_cstr(Str, cstr1);

	printf("Before Pop At : %s\n", str_as_raw(Str)); str_pop(Str, 5, 1);
	printf("After Pop At : %s\n" , str_as_raw(Str));

	str_push_cstr(&Str, 5, cstr2, 1);
	printf("After Push At : %s\n", str_as_raw(Str))								  ;
	printf("Find Result : %s\n"  , str_as_raw(Str) + str_find_cstr(Str, 0, cstr1));

	del(Str);
}