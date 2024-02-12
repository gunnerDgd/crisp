#include <obj.h>
#include <sync/mpmc.h>

#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

void* cstd_mem_new(mem* par, u64_t par_size) { return malloc(par_size); }
void  cstd_mem_del(mem* par, void* par_del)  { free(par_del); }

mem cstd_mem		     = {
	.on_new = &cstd_mem_new,
	.on_del = &cstd_mem_del
};

typedef struct val {
	obj   head ;
	u64_t value;
}	val;

bool_t val_new	(val* par_obj, u32_t par_count, va_list par) { par_obj->value = va_arg(par, u64_t); return true_t; }
bool_t val_clone(val* par    , val  *par_clone)			     { return true_t; }
bool_t val_ref  (val* par)								     { return true_t; }
void   val_del  (val* par)								     {  }

obj_trait val_trait = make_trait (
	val_new    ,
	val_clone  ,
	val_ref    ,
	val_del    ,
	sizeof(val),
	null_t
);

obj_trait *val_t = &val_trait;

void tx_thd(mpmc* par)				  {
	for (int i = 1 ; i <= 1000 ; ++i) {
		mpmc_enq(par, make(val) from(1, i));
	}
}

u64_t rx_thd(mpmc* par)				  {
	u64_t ret = 0;
	for (int i = 1 ; i <= 1000 ; ++i) {
		val   *deq = (val*) mpmc_deq(par);
		ret += deq->value;
	}

	return ret;
}

int main()			  {
	set_mem(&cstd_mem);
	mpmc  *Mpmc = make (mpmc) from (0);
	u64_t  sum  = 0					  ;
	HANDLE rx [8];
	HANDLE tx [8];
	u64_t  ret[8];

	for(int i = 0 ; i < 8 ; ++i)				      {
		rx[i] = CreateThread(0, 0, rx_thd, Mpmc, 0, 0);
		tx[i] = CreateThread(0, 0, tx_thd, Mpmc, 0, 0);
	}

	for(int i = 0 ; i < 8 ; ++i)			{
		WaitForSingleObject(rx[i], INFINITE);
		WaitForSingleObject(tx[i], INFINITE);
		GetExitCodeThread  (rx[i], &ret[i]) ;

		sum += ret[i];
	}

	printf("%d\n", sum);
}