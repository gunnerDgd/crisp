#include <obj.h>
#include <mem.h>
#include <bit.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct type {
	obj   head ;
	u64_t value;
}	type;

bool_t type_new	 (obj* par_obj, u32_t par_count, va_list par) { printf("Object Created\n")		   ; return true_t; }
bool_t type_clone(obj* par    , obj* par_clone)				  { printf("Object Created As Clone\n"); return true_t; }
bool_t type_ref  (obj* par)									  { printf("Object Referenced\n")	   ; return true_t; }
void   type_del  (obj* par)									  { printf("Object Destroyed\n")	   ; }

obj_trait type_trait = make_trait (
	type_new    ,
	type_clone  ,
	type_ref    ,
	type_del    ,
	sizeof(type),
	null_t
);

obj_trait* type_t = &type_trait;

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem		     = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

int main()			  {
	set_mem(&cstd_mem);
	obj* TestObj = make(type) from (0);

	ref (TestObj); printf("Use Count : %llu\n", use_count(TestObj));
	del (TestObj); printf("Use Count : %llu\n", use_count(TestObj));
	del (TestObj);
}