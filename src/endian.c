#include "endian.h"

#ifdef PRESET_X86_64
u16_t 
    be16(u16_t par) { 
        return ((par & 0xFF00) >> 8) | ((par & 0x00FF) << 8); 
}

u32_t 
    be32(u32_t par)     {
        u8_t *ret = &par;
        return ret[3] | ret[2] | ret[1] | ret[0];
}

u64_t 
    be64(u64_t par)     {
        u8_t *ret = &par;
        return ret[7] | ret[6] | ret[5] | ret[4] | ret[3] | ret[2] | ret[1] | ret[0];
}

u16_t le16(u16_t par) { return par; }
u32_t le32(u32_t par) { return par; }
u64_t le64(u64_t par) { return par; }
#endif