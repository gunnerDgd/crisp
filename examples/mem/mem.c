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
	reg_t a = 0;
	printf("%d ", a); printf("%d\n", btr(&a, 1));
	printf("%d ", a); printf("%d\n", btr(&a, 1));
	printf("%d\n", a);
	
	i8_t* ret = new(i8_t);
	*ret = 5;

	printf("%d\n", *ret);
	drop  (ret);
}