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
    btc   word [rcx], dx
    setc  al
    movzx ax, al
    ret

btc32:
    btc   dword[rcx], edx
    setc  al
    movzx eax, al
    ret

btc64:
    btc qword[rcx], rdx
    setc  al
    movzx rax, al
    ret


btr16:
    btr word [rcx], dx
    setc  al
    movzx ax, al
    ret

btr32:
    btr dword[rcx], edx
    setc  al
    movzx eax, al
    ret

btr64:
    btr qword[rcx], rdx
    setc  al
    movzx rax, al
    ret


bts16:
    bts word [rcx], dx
    setc  al
    movzx ax, al
    ret

bts32:
    bts dword[rcx], edx
    setc  al
    movzx eax, al
    ret

bts64:
    bts qword[rcx], rdx
    setc  al
    movzx rax, al
    ret


bsf16:
    xor rax, rax
    bsf ax , cx
    ret

bsf32:
    xor rax, rax
    bsf eax, ecx
    ret

bsf64:
    xor rax, rax
    bsf rax, rcx
    ret


bsr16:
    xor rax, rax
    bsr ax , cx
    ret

bsr32:
    xor rax, rax
    bsr eax, ecx
    ret

bsr64:
    xor rax, rax
    bsr rax, rcx
    ret


lock_btc16:
    lock btc word [rcx], dx
    setc  al
    movzx ax, al
    ret

lock_btc32:
    lock btc dword[rcx], edx
    setc  al
    movzx eax, al
    ret

lock_btc64:
    lock btc qword[rcx], rdx
    setc  al
    movzx rax, al
    ret


lock_btr16:
    lock btr word [rcx], dx
    setc  al
    movzx ax, al
    ret

lock_btr32:
    lock btr dword[rcx], edx
    setc  al
    movzx eax, al
    ret

lock_btr64:
    lock btr qword[rcx], rdx
    setc  al
    movzx rax, al
    ret


lock_bts16:
    lock bts word [rcx], dx
    setc  al
    movzx ax, al
    ret

lock_bts32:
    lock bts dword[rcx], edx
    setc  al
    movzx eax, al
    ret

lock_bts64:
    lock bts qword[rcx], rdx
    setc  al
    movzx rax, al
    ret