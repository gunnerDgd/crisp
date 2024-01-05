#ifndef __BIT_H__
#define __BIT_H__

#include "type.h"
#include "type_atom.h"

void  btc16     (u16_t*, u16_t);
void  btc32     (u32_t*, u32_t);
void  btc64     (u64_t*, u64_t);

void  btr16     (u16_t*, u16_t);
void  btr32     (u32_t*, u32_t);
void  btr64     (u64_t*, u64_t);

void  bts16     (u16_t*, u16_t);
void  bts32     (u32_t*, u32_t);
void  bts64     (u64_t*, u64_t);

u16_t bsf16     (u16_t);
u32_t bsf32     (u32_t);
u64_t bsf64     (u64_t);

u16_t bsr16     (u16_t);
u32_t bsr32     (u32_t);
u64_t bsr64     (u64_t);

void  lock_btc16(atom_u16_t*, u16_t);
void  lock_btc32(atom_u32_t*, u32_t);
void  lock_btc64(atom_u64_t*, u64_t);

void  lock_btr16(atom_u16_t*, u16_t);
void  lock_btr32(atom_u32_t*, u32_t);
void  lock_btr64(atom_u64_t*, u64_t);

void  lock_bts16(atom_u16_t*, u16_t);
void  lock_bts32(atom_u32_t*, u32_t);
void  lock_bts64(atom_u64_t*, u64_t);

#endif