global btc16
global btc32
global btc64

global btr16
global btr32
global btr64

global bts16
global bts32
global bts64

global bsf16
global bsf32
global bsf64

global bsr16
global bsr32
global bsr64

global lock_btc16
global lock_btc32
global lock_btc64

global lock_btr16
global lock_btr32
global lock_btr64

section .text

btc16:
    btc word [rdi], si
    ret

btc32:
    btc dword[rdi], esi
    ret

btc64:
    btc qword[rdi], rsi
    ret


btr16:
    btr word [rdi], si
    ret

btr32:
    btr dword[rdi], esi
    ret

btr64:
    btr qword[rdi], rsi
    ret


bts16:
    bts word [rdi], si
    ret

bts32:
    bts dword[rdi], esi
    ret

bts64:
    bts qword[rdi], rsi
    ret


bsf16:
    xor rax, rax
    bsf ax , di
    ret

bsf32:
    xor rax, rax
    bsf eax, edi
    ret

bsf64:
    xor rax, rax
    bsf rax, rdi
    ret


bsr16:
    xor rax, rax
    bsr ax , di
    ret

bsr32:
    xor rax, rax
    bsr eax, edi
    ret

bsr64:
    xor rax, rax
    bsr rax, rdi
    ret


lock_btc16:
    lock btc word [rdi], ax
    ret

lock_btc32:
    lock btc dword[rdi], eax
    ret

lock_btc64:
    lock btc qword[rdi], rax
    ret


lock_btr16:
    lock btr word [rdi], ax
    ret

lock_btr32:
    lock btr dword[rdi], eax
    ret

lock_btr64:
    lock btr qword[rdi], rax
    ret


lock_bts16:
    lock bts word [rdi], ax
    ret

lock_bts32:
    lock bts dword[rdi], eax
    ret

lock_bts64:
    lock bts qword[rdi], rax
    ret