#ifndef __PRESET_SIG_H__
#define __PRESET_SIG_H__

#include "env.h"

#include "../../../obj.h"
#include "../../../list.h"
#include "../../../it.h"

extern obj_trait __sig_hndl_trait;
typedef struct   __sig_hndl		 {
	obj      head		 ;
	bool_t (*hndl)(void*);
	void    *par		 ;
}	__sig_hndl			 ;

#define __sig_dbg  0
#define __sig_segv 1
#define __sig_int  2
#define __sig_fdiv 3

u64_t  __sig_main  (void*);
bool_t __sig_init  ()     ;
void   __sig_deinit()     ;

it     __sig_hndl_add(u64_t, __sig_hndl*);
void   __sig_hndl_del(u64_t, it)		 ;

#endif