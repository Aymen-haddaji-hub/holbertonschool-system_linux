BITS 64

global asm_strlen

section .text
asm_strlen:
    push rbp; setup the pointer to memory
    mov rbp, rsp; 

    mov rcx, 0h ; set rcx to NULL               

    


loop_asm_strlen:


    cmp byte[rdi + rcx], 0h ; check the length of the str 
	je end; if null end loop
    inc rcx; if no increment
    jmp loop_asm_strlen; and then reloop
end:
    mov rax, rcx; put the rcx to return register.
    mov rsp, rbp; 
	pop rbp

    ret