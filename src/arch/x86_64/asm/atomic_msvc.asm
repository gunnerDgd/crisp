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
    lock add byte[rcx], dl
    mov  al, byte[rcx]
    ret

lock_add16:
    lock add word[rcx], dx
    mov  ax, word[rcx]
    ret

lock_add32:
    lock add dword[rcx], edx
    mov eax, dword[rcx]
    ret

lock_add64:
    lock add  qword[rcx], rdx
    mov  rax, qword[rcx]
    ret


lock_sub8:
    lock sub byte[rcx], dl
    mov  al, byte[rcx]
    ret

lock_sub16:
    lock sub word[rcx], dx
    mov  ax, word[rcx]
    ret

lock_sub32:
    lock sub dword[rcx], edx
    mov eax, dword[rcx]
    ret

lock_sub64:
    lock sub qword[rcx], rdx
    mov rax, qword[rcx]
    ret


lock_inc8:
    lock inc byte[rcx]
    mov  al, byte[rcx]
    ret

lock_inc16:
    lock inc word[rcx]
    mov  ax, word[rcx]
    ret

lock_inc32:
    lock inc dword[rcx]
    mov eax, dword[rcx]
    ret

lock_inc64:
    lock inc qword[rcx]
    mov rax, qword[rcx]
    ret


lock_dec8:
    lock dec byte[rcx]
    mov  al, byte[rcx]
    ret

lock_dec16:
    lock dec word[rcx]
    mov  ax, word[rcx]
    ret

lock_dec32:
    lock dec dword[rcx]
    mov eax, dword[rcx]
    ret

lock_dec64:
    lock dec qword[rcx]
    mov rax, qword[rcx]
    ret


lock_cas8:
    mov          al        , dl
    lock cmpxchg byte [rcx], r8b
    ret

lock_cas16:
    mov          ax        , dx
    lock cmpxchg word [rcx], r8w
    ret

lock_cas32:
    mov          eax       , edx
    lock cmpxchg dword[rcx], r8d
    ret

lock_cas64:
    mov          rax       , rdx
    lock cmpxchg qword[rcx], r8
    ret


lock_xchg8:
    lock xchg byte[rcx], dl
    mov  al            , dl
    ret

lock_xchg16:
    lock xchg word[rcx], dx
    mov  ax            , dx
    ret

lock_xchg32:
    lock xchg dword[rcx], edx
    mov  eax            , edx
    ret

lock_xchg64:
    lock xchg qword[rcx], rdx
    mov  rax            , rdx
    ret


cas8:
    mov     al        , dl
    cmpxchg byte [rcx], r8b
    ret

cas16:
    mov     ax        , dx
    cmpxchg word [rcx], r8w
    ret

cas32:
    mov     eax       , edx
    cmpxchg dword[rcx], r8d
    ret

cas64:
    mov     rax       , rdx
    cmpxchg qword[rcx], r8
    ret


xchg8:
    xchg byte[rcx], dl
    mov  al       , dl
    ret

xchg16:
    xchg word[rcx], dx
    mov  ax       , dx
    ret

xchg32:
    xchg dword[rcx], edx
    mov  eax       , edx
    ret

xchg64:
    xchg qword[rcx], rdx
    mov  rax       , rdx
    ret