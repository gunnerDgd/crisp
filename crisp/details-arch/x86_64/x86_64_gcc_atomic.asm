global atomic_add8
global atomic_add16
global atomic_add32
global atomic_add64

global atomic_sub8
global atomic_sub16
global atomic_sub32
global atomic_sub64

global atomic_cmpxchg8
global atomic_cmpxchg16
global atomic_cmpxchg32
global atomic_cmpxchg64

global atomic_inc8
global atomic_inc16
global atomic_inc32
global atomic_inc64

global atomic_dec8
global atomic_dec16
global atomic_dec32
global atomic_dec64

section .text

atomic_add8:
    lock add byte[rdi], sil
    mov  al, byte[rdi]
    ret

atomic_add16:
    lock add word[rdi], si
    mov  ax, word[rdi]
    ret

atomic_add32:
    lock add dword[rdi], esi
    mov eax, dword[rdi]
    ret

atomic_add64:
    lock add  qword[rdi], rsi
    mov  rax, qword[rdi]
    ret


atomic_sub8:
    lock sub byte[rdi], sil
    mov  al, byte[rdi]
    ret

atomic_sub16:
    lock sub word[rdi], si
    mov  ax, word[rdi]
    ret

atomic_sub32:
    lock sub dword[rdi], esi
    mov eax, dword[rdi]
    ret

atomic_sub64:
    lock sub qword[rdi], rsi
    mov rax, qword[rdi]
    ret


atomic_inc8:
    lock inc byte[rdi]
    mov  al, byte[rdi]
    ret

atomic_inc16:
    lock inc word[rdi]
    mov  ax, word[rdi]
    ret

atomic_inc32:
    lock inc dword[rdi]
    mov eax, dword[rdi]
    ret

atomic_inc64:
    lock inc qword[rdi]
    mov rax, qword[rdi]
    ret


atomic_dec8:
    lock dec byte[rdi]
    mov  al, byte[rdi]
    ret

atomic_dec16:
    lock dec word[rdi]
    mov  ax, word[rdi]
    ret

atomic_dec32:
    lock dec dword[rdi]
    mov eax, dword[rdi]
    ret

atomic_dec64:
    lock dec qword[rdi]
    mov rax, qword[rdi]
    ret


atomic_cmpxchg8:
    lock cmpxchg byte [rdi], sil
    ret

atomic_cmpxchg16:
    lock cmpxchg word [rdi], si
    ret

atomic_cmpxchg32:
    lock cmpxchg dword[rdi], esi
    ret

atomic_cmpxchg64:
    lock cmpxchg qword[rdi], rsi
    ret