#include <mem.h>
#include <bit.h>

#include <stdio.h>
#include <stdlib.h>

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem		     = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

int main()			     {
	set_mem(&cstd_mem)   ;
	
	i8_t* ret = new(i8_t);
	*ret = 5;

	printf("%d\n", *ret);
	drop  (ret);
}