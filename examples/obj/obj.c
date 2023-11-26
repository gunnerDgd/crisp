#include <obj.h>
#include <mem.h>

#include <stdio.h>
#include <stdlib.h>

#include <intrin.h>

bool_t TestObjInit		 (obj* par_obj, u32_t par_count, va_list par) { printf("Object Created\n")									  ; return true_t; }
bool_t TestObjInitAsClone(obj* par    , obj* par_clone)				  { printf("Object Created As Clone\n")							  ; return true_t; }
bool_t TestObjInitAsRef  (obj* par)									  { printf("Object Referenced (Use Count : %d)\n", use_count(par)); return true_t; }
void   TestObjDeInit     (obj* par)									  { printf("Object Destroyed\n"); }

obj_trait TestObjTrait		     = {
	.on_new	  = &TestObjInit	   ,
	.on_clone = &TestObjInitAsClone,
	.on_ref   = &TestObjInitAsRef  ,
	.on_del	  = &TestObjDeInit	   ,
	.size	  = sizeof(obj) + 8
};

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

	obj* TestObj = make(&TestObjTrait) from (0);
	ref (TestObj);

	del (TestObj); printf("Object Dereferenced (Use Count : %d)\n", use_count(TestObj));
	del (TestObj);
}