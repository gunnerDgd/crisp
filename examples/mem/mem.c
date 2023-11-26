#include <mem.h>
#include <stdio.h>
#include <stdlib.h>

bool_t cstd_mem_res_new() { return true_t; }
void   cstd_mem_res_del() { return true_t; }

void*  cstd_mem_new(mem_res* par, u64_t par_size) { return malloc(par_size); }
void   cstd_mem_del(mem_res* par, void* par_del)  { free(par_del); }

mem_res_trait cstd_mem_res_trait = {
	.on_new = &cstd_mem_res_new,
	.on_del = &cstd_mem_res_del,

	.on_mem_new = &cstd_mem_new,
	.on_mem_del = &cstd_mem_del
};

mem_res cstd_mem_res;

int main() {
	mem_res_new(&cstd_mem_res, &cstd_mem_res_trait, 0);
	set_mem_res(&cstd_mem_res);

	i8_t* ret = mem_new(0, 1);
	*ret = 5;
	printf("%d\n", *ret);
}