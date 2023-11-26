#include "atom.h"
#include "details/atom.h"

atom_u8_t  lock_add8 (atom_u8_t * par, atom_u8_t  par_add) { return __lock_add8 (par, par_add); }
atom_u16_t lock_add16(atom_u16_t* par, atom_u16_t par_add) { return __lock_add16(par, par_add); }
atom_u32_t lock_add32(atom_u32_t* par, atom_u32_t par_add) { return __lock_add32(par, par_add); }
atom_u64_t lock_add64(atom_u64_t* par, atom_u64_t par_add) { return __lock_add64(par, par_add); }

atom_u8_t  lock_sub8 (atom_u8_t * par, atom_u8_t  par_sub) { return __lock_sub8 (par, par_sub); }
atom_u16_t lock_sub16(atom_u16_t* par, atom_u16_t par_sub) { return __lock_sub16(par, par_sub); }
atom_u32_t lock_sub32(atom_u32_t* par, atom_u32_t par_sub) { return __lock_sub32(par, par_sub); }
atom_u64_t lock_sub64(atom_u64_t* par, atom_u64_t par_sub) { return __lock_sub64(par, par_sub); }

atom_u8_t  lock_inc8 (atom_u8_t * par) { return __lock_inc8 (par); }
atom_u16_t lock_inc16(atom_u16_t* par) { return __lock_inc16(par); }
atom_u32_t lock_inc32(atom_u32_t* par) { return __lock_inc32(par); }
atom_u64_t lock_inc64(atom_u64_t* par) { return __lock_inc64(par); }

atom_u8_t  lock_dec8 (atom_u8_t * par) { return __lock_dec8 (par); }
atom_u16_t lock_dec16(atom_u16_t* par) { return __lock_dec16(par); }
atom_u32_t lock_dec32(atom_u32_t* par) { return __lock_dec32(par); }
atom_u64_t lock_dec64(atom_u64_t* par) { return __lock_dec64(par); }

atom_u8_t  lock_cas8 (atom_u8_t * par, atom_u8_t  par_exp, atom_u8_t  par_exc) { return __lock_cas8 (par, par_exp, par_exc); }
atom_u16_t lock_cas16(atom_u16_t* par, atom_u16_t par_exp, atom_u16_t par_exc) { return __lock_cas16(par, par_exp, par_exc); }
atom_u32_t lock_cas32(atom_u32_t* par, atom_u32_t par_exp, atom_u32_t par_exc) { return __lock_cas32(par, par_exp, par_exc); }
atom_u64_t lock_cas64(atom_u64_t* par, atom_u64_t par_exp, atom_u64_t par_exc) { return __lock_cas64(par, par_exp, par_exc); }

atom_u8_t  lock_xchg8 (atom_u8_t * par, atom_u8_t  par_xchg) { return __lock_xchg8 (par, par_xchg); }
atom_u16_t lock_xchg16(atom_u16_t* par, atom_u16_t par_xchg) { return __lock_xchg16(par, par_xchg); }
atom_u32_t lock_xchg32(atom_u32_t* par, atom_u32_t par_xchg) { return __lock_xchg32(par, par_xchg); }
atom_u64_t lock_xchg64(atom_u64_t* par, atom_u64_t par_xchg) { return __lock_xchg64(par, par_xchg); }

atom_u8_t  cas8 (atom_u8_t * par, atom_u8_t  par_exp, atom_u8_t  par_exc) { return __cas8 (par, par_exp, par_exc); }
atom_u16_t cas16(atom_u16_t* par, atom_u16_t par_exp, atom_u16_t par_exc) { return __cas16(par, par_exp, par_exc); }
atom_u32_t cas32(atom_u32_t* par, atom_u32_t par_exp, atom_u32_t par_exc) { return __cas32(par, par_exp, par_exc); }
atom_u64_t cas64(atom_u64_t* par, atom_u64_t par_exp, atom_u64_t par_exc) { return __cas64(par, par_exp, par_exc); }

atom_u8_t  xchg8 (atom_u8_t * par, atom_u8_t  par_xchg) { return __xchg8 (par, par_xchg); }
atom_u16_t xchg16(atom_u16_t* par, atom_u16_t par_xchg) { return __xchg16(par, par_xchg); }
atom_u32_t xchg32(atom_u32_t* par, atom_u32_t par_xchg) { return __xchg32(par, par_xchg); }
atom_u64_t xchg64(atom_u64_t* par, atom_u64_t par_xchg) { return __xchg64(par, par_xchg); }