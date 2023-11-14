global __lock_add8
global __lock_add16
global __lock_add32
global __lock_add64

global __lock_sub8
global __lock_sub16
global __lock_sub32
global __lock_sub64

global __lock_inc8
global __lock_inc16
global __lock_inc32
global __lock_inc64

global __lock_dec8
global __lock_dec16
global __lock_dec32
global __lock_dec64

global __lock_cas8
global __lock_cas16
global __lock_cas32
global __lock_cas64

global __lock_xchg8
global __lock_xchg16
global __lock_xchg32
global __lock_xchg64

global __cas8
global __cas16
global __cas32
global __cas64

global __xchg64
global __xchg64
global __xchg64
global __xchg64

section .text

__lock_add8:
    lock add byte[rcx], dl
    mov  al, byte[rcx]
    ret

__lock_add16:
    lock add word[rcx], dx
    mov  ax, word[rcx]
    ret

__lock_add32:
    lock add dword[rcx], edx
    mov eax, dword[rcx]
    ret

__lock_add64:
    lock add  qword[rcx], rdx
    mov  rax, qword[rcx]
    ret


__lock_sub8:
    lock sub byte[rcx], dl
    mov  al, byte[rcx]
    ret

__lock_sub16:
    lock sub word[rcx], dx
    mov  ax, word[rcx]
    ret

__lock_sub32:
    lock sub dword[rcx], edx
    mov eax, dword[rcx]
    ret

__lock_sub64:
    lock sub qword[rcx], rdx
    mov rax, qword[rcx]
    ret


__lock_inc8:
    lock inc byte[rcx]
    mov  al, byte[rcx]
    ret

__lock_inc16:
    lock inc word[rcx]
    mov  ax, word[rcx]
    ret

__lock_inc32:
    lock inc dword[rcx]
    mov eax, dword[rcx]
    ret

__lock_inc64:
    lock inc qword[rcx]
    mov rax, qword[rcx]
    ret


__lock_dec8:
    lock dec byte[rcx]
    mov  al, byte[rcx]
    ret

__lock_dec16:
    lock dec word[rcx]
    mov  ax, word[rcx]
    ret

__lock_dec32:
    lock dec dword[rcx]
    mov eax, dword[rcx]
    ret

__lock_dec64:
    lock dec qword[rcx]
    mov rax, qword[rcx]
    ret


__lock_cas8:
    mov          al        , dl
    lock cmpxchg byte [rcx], r8b
    ret

__lock_cas16:
    mov          ax        , dx
    lock cmpxchg word [rcx], r8w
    ret

__lock_cas32:
    mov          eax       , edx
    lock cmpxchg dword[rcx], r8d
    ret

__lock_cas64:
    mov          rax       , rdx
    lock cmpxchg qword[rcx], r8
    ret


__lock_xchg8:
    lock xchg byte[rcx], dl
    mov  al            , dl
    ret

__lock_xchg16:
    lock xchg word[rcx], dx
    mov  ax            , dx
    ret

__lock_xchg32:
    lock xchg dword[rcx], edx
    mov  eax            , edx
    ret

__lock_xchg64:
    lock xchg qword[rcx], rdx
    mov  rax            , rdx
    ret


__cas8:
    mov     al        , dl
    cmpxchg byte [rcx], r8b
    ret

__cas16:
    mov     ax        , dx
    cmpxchg word [rcx], r8w
    ret

__cas32:
    mov     eax       , edx
    cmpxchg dword[rcx], r8d
    ret

__cas64:
    mov     rax       , rdx
    cmpxchg qword[rcx], r8
    ret


__xchg8:
    xchg byte[rcx], dl
    mov  al       , dl
    ret

__xchg16:
    xchg word[rcx], dx
    mov  ax       , dx
    ret

__xchg32:
    xchg dword[rcx], edx
    mov  eax       , edx
    ret

__xchg64:
    xchg qword[rcx], rdx
    mov  rax       , rdx
    ret