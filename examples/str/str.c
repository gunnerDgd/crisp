#include <str.h>
#include <obj.h>

#include <stdio.h>
#include <stdlib.h>

bool_t cstd_mem_res_new() { return true_t; }
void   cstd_mem_res_del() { return true_t; }

void*  cstd_mem_new(mem_res* par, u64_t par_size) { return malloc(par_size); }
void   cstd_mem_del(mem_res* par, void* par_del)  { free(par_del); }

mem_res_trait cstd_mem_res_trait = {
	.on_new		= &cstd_mem_res_new,
	.on_del		= &cstd_mem_res_del,
	.on_mem_new = &cstd_mem_new	   ,
	.on_mem_del = &cstd_mem_del
};

mem_res cstd_mem_res;

int main()											  {
	mem_res_new(&cstd_mem_res, &cstd_mem_res_trait, 0);
	set_mem_res(&cstd_mem_res);

	str str;
	make_at(str, str_t) from(0);

	str_push_back_cstr(&str, "Hello ", 6);
	str_push_back_cstr(&str, "World" , 5);

	printf("Before Pop At : %s\n", str_ptr(&str)); str_pop_at(&str, 5, 1);
	printf("After Pop At : %s\n" , str_ptr(&str));

	str_push_at_cstr(&str, 5, " ", 1);
	printf("After Push At : %s\n", str_ptr(&str))									  ;
	printf("Find Result : %s\n"  , str_ptr(&str) + str_find_cstr(&str, 0, "World", 5));

	del(&str);
}