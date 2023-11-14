#include "atomic.h"
#include "details/atomic.h"

atomic_u8_t  lock_add8 (atomic_u8_t * par, atomic_u8_t  par_add) { return __lock_add8 (par, par_add); }
atomic_u16_t lock_add16(atomic_u16_t* par, atomic_u16_t par_add) { return __lock_add16(par, par_add); }
atomic_u32_t lock_add32(atomic_u32_t* par, atomic_u32_t par_add) { return __lock_add32(par, par_add); }
atomic_u64_t lock_add64(atomic_u64_t* par, atomic_u64_t par_add) { return __lock_add64(par, par_add); }

atomic_u8_t  lock_sub8 (atomic_u8_t * par, atomic_u8_t  par_sub) { return __lock_sub8 (par, par_sub); }
atomic_u16_t lock_sub16(atomic_u16_t* par, atomic_u16_t par_sub) { return __lock_sub16(par, par_sub); }
atomic_u32_t lock_sub32(atomic_u32_t* par, atomic_u32_t par_sub) { return __lock_sub32(par, par_sub); }
atomic_u64_t lock_sub64(atomic_u64_t* par, atomic_u64_t par_sub) { return __lock_sub64(par, par_sub); }

atomic_u8_t  lock_inc8 (atomic_u8_t * par) { return __lock_inc8 (par); }
atomic_u16_t lock_inc16(atomic_u16_t* par) { return __lock_inc16(par); }
atomic_u32_t lock_inc32(atomic_u32_t* par) { return __lock_inc32(par); }
atomic_u64_t lock_inc64(atomic_u64_t* par) { return __lock_inc64(par); }

atomic_u8_t  lock_dec8 (atomic_u8_t * par) { return __lock_dec8 (par); }
atomic_u16_t lock_dec16(atomic_u16_t* par) { return __lock_dec16(par); }
atomic_u32_t lock_dec32(atomic_u32_t* par) { return __lock_dec32(par); }
atomic_u64_t lock_dec64(atomic_u64_t* par) { return __lock_dec64(par); }

atomic_u8_t  lock_cas8 (atomic_u8_t * par, atomic_u8_t  par_exp, atomic_u8_t  par_exc) { return __lock_cas8 (par, par_exp, par_exc); }
atomic_u16_t lock_cas16(atomic_u16_t* par, atomic_u16_t par_exp, atomic_u16_t par_exc) { return __lock_cas16(par, par_exp, par_exc); }
atomic_u32_t lock_cas32(atomic_u32_t* par, atomic_u32_t par_exp, atomic_u32_t par_exc) { return __lock_cas32(par, par_exp, par_exc); }
atomic_u64_t lock_cas64(atomic_u64_t* par, atomic_u64_t par_exp, atomic_u64_t par_exc) { return __lock_cas64(par, par_exp, par_exc); }

atomic_u8_t  lock_xchg8 (atomic_u8_t * par, atomic_u8_t  par_xchg) { return __lock_xchg8 (par, par_xchg); }
atomic_u16_t lock_xchg16(atomic_u16_t* par, atomic_u16_t par_xchg) { return __lock_xchg16(par, par_xchg); }
atomic_u32_t lock_xchg32(atomic_u32_t* par, atomic_u32_t par_xchg) { return __lock_xchg32(par, par_xchg); }
atomic_u64_t lock_xchg64(atomic_u64_t* par, atomic_u64_t par_xchg) { return __lock_xchg64(par, par_xchg); }

atomic_u8_t  cas8 (atomic_u8_t * par, atomic_u8_t  par_exp, atomic_u8_t  par_exc) { return __cas8 (par, par_exp, par_exc); }
atomic_u16_t cas16(atomic_u16_t* par, atomic_u16_t par_exp, atomic_u16_t par_exc) { return __cas16(par, par_exp, par_exc); }
atomic_u32_t cas32(atomic_u32_t* par, atomic_u32_t par_exp, atomic_u32_t par_exc) { return __cas32(par, par_exp, par_exc); }
atomic_u64_t cas64(atomic_u64_t* par, atomic_u64_t par_exp, atomic_u64_t par_exc) { return __cas64(par, par_exp, par_exc); }

atomic_u8_t  xchg8 (atomic_u8_t * par, atomic_u8_t  par_xchg) { return __xchg8 (par, par_xchg); }
atomic_u16_t xchg16(atomic_u16_t* par, atomic_u16_t par_xchg) { return __xchg16(par, par_xchg); }
atomic_u32_t xchg32(atomic_u32_t* par, atomic_u32_t par_xchg) { return __xchg32(par, par_xchg); }
atomic_u64_t xchg64(atomic_u64_t* par, atomic_u64_t par_xchg) { return __xchg64(par, par_xchg); }