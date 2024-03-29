#ifndef __NODE_H__
#define __NODE_H__

#include "../core.h"

extern obj_trait *node_t     ;
typedef struct    node       {
    obj           head       ;
    struct node  *prev, *next;
    obj          *node       ;
}   node;

bool_t node_new  (node*, u32_t, va_list);
bool_t node_clone(node*, node*)         ;
void   node_del  (node*)                ;

obj*   node_value(node*)                ;
node*  node_next (node*, node*)         ;
node*  node_prev (node*, node*)         ;

#ifndef __cplusplus
#define next(par)               node_next (par, 0)
#define next_as(par, par_next)  node_next (par, par_next)
#define prev(par)               node_prev (par, 0)
#define prev_as(par, par_prev)  node_prev (par, par_prev)
#define value(par)              node_value(par)
#define value_as(par, par_type) ((par_type)node_value(par))
#endif

#endif