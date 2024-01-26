#include "../../atom.h"

atom_u8_t  
    lock_cas_inc8
        (atom_u8_t* par)    {
            u8_t ret_inc = 0;
            u8_t ret     = 0;
            do                    {
                ret      = *par   ;
                ret_inc  = ret + 1;
            } while (lock_cas8(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u16_t  
    lock_cas_inc16
        (atom_u16_t* par)    {
            u16_t ret_inc = 0;
            u16_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_inc   = ret + 1;
            } while (lock_cas16(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u32_t  
    lock_cas_inc32
        (atom_u32_t* par)    {
            u32_t ret_inc = 0;
            u32_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_inc   = ret + 1;
            } while (lock_cas32(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u64_t  
    lock_cas_inc64
        (atom_u64_t* par)    {
            u64_t ret_inc = 0;
            u64_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_inc   = ret + 1;
            } while (lock_cas64(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u8_t  
    lock_cas_dec8
        (atom_u8_t* par)    {
            u8_t ret_dec = 0;
            u8_t ret     = 0;
            do                    {
                ret      = *par   ;
                ret_dec  = ret - 1;
            } while (lock_cas8(par, ret, ret_dec) != ret);

            return ret_dec;
}

atom_u16_t  
    lock_cas_dec16
        (atom_u16_t* par)    {
            u16_t ret_dec = 0;
            u16_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_dec   = ret - 1;
            } while (lock_cas16(par, ret, ret_dec) != ret);

            return ret_dec;
}

atom_u32_t  
    lock_cas_dec32
        (atom_u32_t* par)    {
            u32_t ret_dec = 0;
            u32_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_dec   = ret - 1;
            } while (lock_cas32(par, ret, ret_dec) != ret);

            return ret_dec;
}

atom_u64_t  
    lock_cas_dec64
        (atom_u64_t* par)    {
            u64_t ret_dec = 0;
            u64_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_dec   = ret - 1;
            } while (lock_cas64(par, ret, ret_dec) != ret);

            return ret_dec;
}


atom_u8_t  
    cas_inc8
        (atom_u8_t* par)    {
            u8_t ret_inc = 0;
            u8_t ret     = 0;
            do                    {
                ret      = *par   ;
                ret_inc  = ret + 1;
            } while (cas8(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u16_t  
    cas_inc16
        (atom_u16_t* par)    {
            u16_t ret_inc = 0;
            u16_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_inc   = ret + 1;
            } while (cas16(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u32_t  
    cas_inc32
        (atom_u32_t* par)    {
            u32_t ret_inc = 0;
            u32_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_inc   = ret + 1;
            } while (cas32(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u64_t  
    cas_inc64
        (atom_u64_t* par)    {
            u64_t ret_inc = 0;
            u64_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_inc   = ret + 1;
            } while (cas64(par, ret, ret_inc) != ret);

            return ret_inc;
}

atom_u8_t  
    cas_dec8
        (atom_u8_t* par)    {
            u8_t ret_dec = 0;
            u8_t ret     = 0;
            do                    {
                ret      = *par   ;
                ret_dec  = ret - 1;
            } while (cas8(par, ret, ret_dec) != ret);

            return ret_dec;
}

atom_u16_t  
    cas_dec16
        (atom_u16_t* par)    {
            u16_t ret_dec = 0;
            u16_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_dec   = ret - 1;
            } while (cas16(par, ret, ret_dec) != ret);

            return ret_dec;
}

atom_u32_t  
    cas_dec32
        (atom_u32_t* par)    {
            u32_t ret_dec = 0;
            u32_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_dec   = ret - 1;
            } while (cas32(par, ret, ret_dec) != ret);

            return ret_dec;
}

atom_u64_t  
    cas_dec64
        (atom_u64_t* par)    {
            u64_t ret_dec = 0;
            u64_t ret     = 0;
            do                     {
                ret       = *par   ;
                ret_dec   = ret - 1;
            } while (cas64(par, ret, ret_dec) != ret);

            return ret_dec;
}