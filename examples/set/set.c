#include <stdio.h>
#include <stdlib.h>

#include <set.h>

typedef struct test {
	obj   head ;
	u64_t value;
}	test;

bool_t test_new	 (obj* par_obj, u32_t par_count, va_list par) { return true_t; }
bool_t test_clone(obj* par    , obj* par_clone)				  { return true_t; }
bool_t test_ref  (obj* par)									  { return true_t; }
void   test_del  (obj* par)									  {  }

obj_trait test_t		 = {
	.on_new	  = &test_new  ,
	.on_clone = &test_clone,
	.on_ref   = &test_ref  ,
	.on_del	  = &test_del  ,
	.size	  = sizeof(test)
};

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem		     = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

int main() {
	set_mem(&cstd_mem);
	set* set = make (set_t) from (0);
	for (int i = 0; i < 256; ++i) set_rel(set, make(&test_t) from(0));

	obj* acq = 0;
	acq = set_acq(set); if (!acq) return -1;
	acq = set_acq(set); if (!acq) return -1;
	acq = set_acq(set); if (!acq) return -1;
	acq = set_acq(set); if (!acq) return -1;
	acq = set_acq(set); if (!acq) return -1;
}