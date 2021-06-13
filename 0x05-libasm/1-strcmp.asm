BITS 64

global asm_strcmp

section .text
asm_strcmp:
	push	rbp		; Add a element to the stack
	mov 	rbp,	rsp	; Create a backup of the status stack
	xor	rcx,	rcx	; Create a counter and init to zero
	cmp	rdi,	0	; check if arg1 is NULL
	je	out		; so go out
	cmp	rsi,	0	; check if arg2 is NULL
	je	out		; so go out

loop:
	mov	al,	[rdi + rcx]	; cpy tmp = arg1[i]
	mov	r8b,	[rsi + rcx]	; cpy tmp = arg2[i]
	cmp	al,	0 		; Check if end of string 1
	je	final_value	  	; so go end of exec
	cmp	r8b,	0 		; Check if end of string 2
	je	final_value	  	; so go end of exec
	cmp	al,	r8b	   	; compare arg1[i], arg2[i]
	jne	final_value		; if arg1[i] != arg2[i]
	inc	rcx			; i++
	jmp	loop			; go to loop

final_value:
	sub	al,	r8b	; al -= r8b
	movsx	rax,	al	; get le sign of value
	cmp	rax,	0	; compare value == 0
	jg	pos_value	; if is pos > 0 go pos_value
	cmp	rax,	0	; comapare value == 0
	je	out		; if == 0 go out
	jmp	neg_value	; elf go neg if value < 0

pos_value:
	mov	rax,	1	; value = 1
	jmp	out		; go out

neg_value:
	mov	rax,	-1	; value = -1
	jmp	out		; go out

out:
	mov	rsp,	rbp	; Get back the status stack
	pop	rbp		; Delete the element to the stack
	ret			; return
	