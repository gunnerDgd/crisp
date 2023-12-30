#include <obj.h>
#include <mem.h>

#include <stdio.h>
#include <stdlib.h>


typedef struct test {
	obj   head ;
	u64_t value;
}	test;

bool_t test_new	 (obj* par_obj, u32_t par_count, va_list par) { printf("Object Created\n")		   ; return true_t; }
bool_t test_clone(obj* par    , obj* par_clone)				  { printf("Object Created As Clone\n"); return true_t; }
bool_t test_ref  (obj* par)									  { printf("Object Referenced\n")	   ; return true_t; }
void   test_del  (obj* par)									  { printf("Object Destroyed\n")	   ; }

obj_trait test_t		 = {
	.on_new	  = &test_new  ,
	.on_clone = &test_clone,
	.on_ref   = &test_ref  ,
	.on_del	  = &test_del  ,
	.size	  = sizeof(test)
};

bool_t cstd_mem_res_new() { return true_t; }
void   cstd_mem_res_del() { return true_t; }

void*  cstd_mem_new(mem_res* par, u64_t par_size) { return malloc(par_size); }
void   cstd_mem_del(mem_res* par, void* par_del)  { free(par_del); }

mem_res cstd_mem_res = {
	.on_new = &cstd_mem_res_new,
	.on_del = &cstd_mem_res_del,

	.on_mem_new = &cstd_mem_new,
	.on_mem_del = &cstd_mem_del
};

int main() {
	mem_res_new(&cstd_mem_res, 0);
	set_mem_res(&cstd_mem_res)   ;

	obj* TestObj = make(&test_t) from (0);
	ref (TestObj); printf("Object Referenced (Use Count : %d)\n", use_count(TestObj));

	del (TestObj); printf("Object Dereferenced (Use Count : %d)\n", use_count(TestObj));
	del (TestObj);
}