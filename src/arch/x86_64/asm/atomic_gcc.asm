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
    lock add byte[rdi], sil
    mov  al, byte[rdi]
    ret

lock_add16:
    lock add word[rdi], si
    mov  ax, word[rdi]
    ret

lock_add32:
    lock add dword[rdi], esi
    mov eax, dword[rdi]
    ret

lock_add64:
    lock add  qword[rdi], rsi
    mov  rax, qword[rdi]
    ret


lock_sub8:
    lock sub byte[rdi], sil
    mov  al, byte[rdi]
    ret

lock_sub16:
    lock sub word[rdi], si
    mov  ax, word[rdi]
    ret

lock_sub32:
    lock sub dword[rdi], esi
    mov eax, dword[rdi]
    ret

lock_sub64:
    lock sub qword[rdi], rsi
    mov rax, qword[rdi]
    ret


lock_inc8:
    lock inc byte[rdi]
    mov  al, byte[rdi]
    ret

lock_inc16:
    lock inc word[rdi]
    mov  ax, word[rdi]
    ret

lock_inc32:
    lock inc dword[rdi]
    mov eax, dword[rdi]
    ret

lock_inc64:
    lock inc qword[rdi]
    mov rax, qword[rdi]
    ret


lock_dec8:
    lock dec byte[rdi]
    mov  al, byte[rdi]
    ret

lock_dec16:
    lock dec word[rdi]
    mov  ax, word[rdi]
    ret

lock_dec32:
    lock dec dword[rdi]
    mov eax, dword[rdi]
    ret

lock_dec64:
    lock dec qword[rdi]
    mov rax, qword[rdi]
    ret


lock_cas8:
    mov          al        , sil
    lock cmpxchg byte [rdi], dl
    ret

lock_cas16:
    mov          ax        , si
    lock cmpxchg word [rdi], dx
    ret

lock_cas32:
    mov          eax       , esi
    lock cmpxchg dword[rdi], edx
    ret

lock_cas64:
    mov          rax       , rsi
    lock cmpxchg qword[rdi], rdx
    ret


lock_xchg8:
    lock xchg byte[rdi], sil
    mov  al            , sil
    ret

lock_xchg16:
    lock xchg word[rdi], si
    mov  ax            , si
    ret

lock_xchg32:
    lock xchg dword[rdi], esi
    mov  eax            , esi
    ret

lock_xchg64:
    lock xchg qword[rdi], rsi
    mov  rax            , rsi
    ret


cas8:
    mov     al        , sil
    cmpxchg byte [rdi], dl
    ret

cas16:
    mov     ax        , si
    cmpxchg word [rdi], dx
    ret

cas32:
    mov     eax       , esi
    cmpxchg dword[rdi], edx
    ret

cas64:
    mov     rax       , rsi
    cmpxchg qword[rdi], rdx
    ret


xchg8:
    xchg byte[rdi], sil
    mov  al       , sil
    ret

xchg16:
    xchg word[rdi], si
    mov  ax       , si
    ret

xchg32:
    xchg dword[rdi], esi
    mov  eax       , esi
    ret

xchg64:
    xchg qword[rdi], rsi
    mov  rax       , rsi
    ret