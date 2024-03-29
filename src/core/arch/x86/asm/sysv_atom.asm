global lock_add8
global lock_add16
global lock_add32
global lock_add64

global lock_sub8
global lock_sub16
global lock_sub32
global lock_sub64

global lock_inc8
global lock_inc16
global lock_inc32
global lock_inc64

global lock_dec8
global lock_dec16
global lock_dec32
global lock_dec64

global lock_cas8
global lock_cas16
global lock_cas32
global lock_cas64

global lock_xchg8
global lock_xchg16
global lock_xchg32
global lock_xchg64

global cas8
global cas16
global cas32
global cas64

global xchg8
global xchg16
global xchg32
global xchg64

section .text

lock_add8:
    lock add byte[edi], sil
    mov  al, byte[edi]
    ret

lock_add16:
    lock add word[edi], si
    mov  ax, word[edi]
    ret

lock_add32:
    lock add dword[edi], esi
    mov eax, dword[edi]
    ret


lock_sub8:
    lock sub byte[edi], sil
    mov  al, byte[edi]
    ret

lock_sub16:
    lock sub word[edi], si
    mov  ax, word[edi]
    ret

lock_sub32:
    lock sub dword[edi], esi
    mov eax, dword[edi]
    ret


lock_inc8:
    lock inc byte[edi]
    mov  al, byte[edi]
    ret

lock_inc16:
    lock inc word[edi]
    mov  ax, word[edi]
    ret

lock_inc32:
    lock inc dword[edi]
    mov eax, dword[edi]
    ret


lock_dec8:
    lock dec byte[edi]
    mov  al, byte[edi]
    ret

lock_dec16:
    lock dec word[edi]
    mov  ax, word[edi]
    ret

lock_dec32:
    lock dec dword[edi]
    mov eax, dword[edi]
    ret


lock_cas8:
    mov          al        , sil
    lock cmpxchg byte [edi], dl
    ret

lock_cas16:
    mov          ax        , si
    lock cmpxchg word [edi], dx
    ret

lock_cas32:
    mov          eax       , esi
    lock cmpxchg dword[edi], edx
    ret


lock_xchg8:
    lock xchg byte[edi], sil
    mov  al            , sil
    ret

lock_xchg16:
    lock xchg word[edi], si
    mov  ax            , si
    ret

lock_xchg32:
    lock xchg dword[edi], esi
    mov  eax            , esi
    ret


cas8:
    mov     al        , sil
    cmpxchg byte [edi], dl
    ret

cas16:
    mov     ax        , si
    cmpxchg word [edi], dx
    ret

cas32:
    mov     eax       , esi
    cmpxchg dword[edi], edx
    ret


xchg8:
    xchg byte[edi], sil
    mov  al       , sil
    ret

xchg16:
    xchg word[edi], si
    mov  ax       , si
    ret

xchg32:
    xchg dword[edi], esi
    mov  eax       , esi
    ret