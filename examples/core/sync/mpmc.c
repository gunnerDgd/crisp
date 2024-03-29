#include <core.h>
#include <core/sync.h>
#include <thread.h>

#include <stdio.h>

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

int run()								{
	mpmc  *mpmc_1 = make (mpmc) from (0);
	u64_t  sum    = 0					;
	thd   *rx [8];
	thd   *tx [8];
	u64_t  ret[8];

	for(int i = 0 ; i < 8 ; ++i)			       {
		rx[i] = make (thd) from (2, rx_thd, mpmc_1);
		tx[i] = make (thd) from (2, tx_thd, mpmc_1);
	}

	for(int i = 0 ; i < 8 ; ++i)			{
		fut   *fut = thd_fut(rx[i]);
		while (fut_poll(fut) == fut_pend);
		sum += (u64_t) fut_ret (fut);

		del (rx[i]);
		del (fut)  ;
	}

	printf("%d\n", sum);
}