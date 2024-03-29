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
    btc word [ecx], dx
    ret

btc32:
    btc dword[ecx], edx
    ret


btr16:
    btr word [ecx], dx
    ret

btr32:
    btr dword[ecx], edx
    ret


bts16:
    bts word [ecx], dx
    ret

bts32:
    bts dword[ecx], edx
    ret


bsf16:
    xor rax, rax
    bsf ax , cx
    ret

bsf32:
    xor rax, rax
    bsf eax, ecx
    ret


bsr16:
    xor rax, rax
    bsr ax , cx
    ret

bsr32:
    xor rax, rax
    bsr eax, ecx
    ret


lock_btc16:
    lock btc word [ecx], ax
    ret

lock_btc32:
    lock btc dword[ecx], eax
    ret


lock_btr16:
    lock btr word [ecx], ax
    ret

lock_btr32:
    lock btr dword[ecx], eax
    ret


lock_bts16:
    lock bts word [ecx], ax
    ret

lock_bts32:
    lock bts dword[ecx], eax
    ret