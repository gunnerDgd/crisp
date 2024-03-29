#include <stdio.h>
#include <stdlib.h>

#include <set.h>

typedef struct val {
	obj   head ;
	u64_t value;
}	val;

bool_t val_new	(obj* par_obj, u32_t par_count, va_list par) { return true_t; }
bool_t val_clone(obj* par    , obj* par_clone)				 { return true_t; }
bool_t val_ref  (obj* par)									 { return true_t; }
void   val_del  (obj* par)									 {  }

obj_trait val_trait = make_trait (
	val_new    ,
	val_clone  ,
	val_ref    ,
	val_del    ,
	sizeof(val),
	null_t
);

obj_trait* val_t = &val_trait;

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem		     = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

int main()			  {
	set_mem(&cstd_mem);
	set* Set = make (set) from (0);
	for (int i = 0; i < 256; ++i) set_rel(Set, make(val) from(0));

	obj* acq = 0;
	acq = set_acq(Set); if (!acq) return -1;
	acq = set_acq(Set); if (!acq) return -1;
	acq = set_acq(Set); if (!acq) return -1;
	acq = set_acq(Set); if (!acq) return -1;
	acq = set_acq(Set); if (!acq) return -1;
}