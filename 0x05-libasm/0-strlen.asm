BITS 64

global asm_strlen

section .text

asm_strlen:
	push rbp							;push the pointer to memory
	mov rbp, rsp

	mov rcx, 0h							;set rcx to NULL

loop_asm_strlen:

	cmp byte[rdi + rcx], 0h
	je end								;if null end loop
	inc rcx								;increment
	jmp loop_asm_strlen					;and then reloop
end:

	mov rax, rcx						;put the rcx to return register
	mov rsp, rbp						;move the last pointer to the fist
	pop rbp

	ret
