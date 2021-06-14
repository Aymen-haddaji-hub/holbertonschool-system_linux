BITS 64

global asm_strlen

section .text
asm_strlen:
	push rb
	mov rbp, rsp

	mov rcx, 0h
loop_asm_strlen:


	cmp byte[rdi + rcx], 0h
	je end
	inc rcx
	jmp loop_asm_strlen
end:
	mov rax, rcx
	mov rsp, rbp
	pop rbp

	ret
