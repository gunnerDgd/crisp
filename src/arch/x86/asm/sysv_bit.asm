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
    btc word [edi], si
    ret

btc32:
    btc dword[edi], esi
    ret


btr16:
    btr word [edi], si
    ret

btr32:
    btr dword[edi], esi
    ret


bts16:
    bts word [edi], si
    ret

bts32:
    bts dword[edi], esi
    ret


bsf16:
    xor rax, rax
    bsf ax , di
    ret

bsf32:
    xor rax, rax
    bsf eax, edi
    ret


bsr16:
    xor rax, rax
    bsr ax , di
    ret

bsr32:
    xor rax, rax
    bsr eax, edi
    ret


lock_btc16:
    lock btc word [edi], ax
    ret

lock_btc32:
    lock btc dword[edi], eax
    ret


lock_btr16:
    lock btr word [edi], ax
    ret

lock_btr32:
    lock btr dword[edi], eax
    ret


lock_bts16:
    lock bts word [edi], ax
    ret

lock_bts32:
    lock bts dword[edi], eax
    ret