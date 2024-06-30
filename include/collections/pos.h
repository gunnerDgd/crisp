#ifndef COLLECTIONS_POS_H
#define COLLECTIONS_POS_H

#include "../core.h"

extern obj_trait *pos_t;
typedef struct    pos { u8_t pos[64]; } pos;

pos* pos_next (pos* self, pos* next);
pos* pos_prev (pos* self, pos* prev);

#ifndef __cplusplus
#define next(self)           pos_next ((self), null_t)
#define next_as(self, next)  pos_next ((self), (next))
#define prev(self)           pos_prev ((self), null_t)
#define prev_as(self, prev)  pos_prev ((self), (prev))
#endif

#endif