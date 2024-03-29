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
    lock add byte[ecx], dl
    mov  al, byte[ecx]
    ret

lock_add16:
    lock add word[ecx], dx
    mov  ax, word[ecx]
    ret

lock_add32:
    lock add dword[ecx], edx
    mov eax, dword[ecx]
    ret


lock_sub8:
    lock sub byte[ecx], dl
    mov  al, byte[ecx]
    ret

lock_sub16:
    lock sub word[ecx], dx
    mov  ax, word[ecx]
    ret

lock_sub32:
    lock sub dword[ecx], edx
    mov eax, dword[ecx]
    ret


lock_inc8:
    lock inc byte[ecx]
    mov  al, byte[ecx]
    ret

lock_inc16:
    lock inc word[ecx]
    mov  ax, word[ecx]
    ret

lock_inc32:
    lock inc dword[ecx]
    mov eax, dword[ecx]
    ret


lock_dec8:
    lock dec byte[ecx]
    mov  al, byte[ecx]
    ret

lock_dec16:
    lock dec word[ecx]
    mov  ax, word[ecx]
    ret

lock_dec32:
    lock dec dword[ecx]
    mov eax, dword[ecx]
    ret


lock_cas8:
    mov          al        , dl
    lock cmpxchg byte [ecx], r8b
    ret

lock_cas16:
    mov          ax        , dx
    lock cmpxchg word [ecx], r8w
    ret

lock_cas32:
    mov          eax       , edx
    lock cmpxchg dword[ecx], r8d
    ret


lock_xchg8:
    lock xchg byte[ecx], dl
    mov  al            , dl
    ret

lock_xchg16:
    lock xchg word[ecx], dx
    mov  ax            , dx
    ret

lock_xchg32:
    lock xchg dword[ecx], edx
    mov  eax            , edx
    ret


cas8:
    mov     al        , dl
    cmpxchg byte [ecx], r8b
    ret

cas16:
    mov     ax        , dx
    cmpxchg word [ecx], r8w
    ret

cas32:
    mov     eax       , edx
    cmpxchg dword[ecx], r8d
    ret


xchg8:
    xchg byte[ecx], dl
    mov  al       , dl
    ret

xchg16:
    xchg word[ecx], dx
    mov  ax       , dx
    ret

xchg32:
    xchg dword[ecx], edx
    mov  eax       , edx
    ret