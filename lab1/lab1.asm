%include "stud_io.inc"
%include "functions_str.asm"
%define SYMBOL ' '
section .data

msg_add_str		db      'Введите строку: ', 0h      ; сообщение пользователю
msg_result_str	db      'Результат: ', 0h           ; сообщение с результатом

section .bss
array resb 12

section .text
global _start

_start:
	
	mov edi, array
	mov byte [array + 12], SYMBOL
	
	mov     eax, msg_add_str ; сообщение в регистр
    call    sprintLF ; напечатать его
	
	
again:	GETCHAR 			
		cmp eax, 10 	; равен ли символ '\n'
		je in_out 
		cmp eax, SYMBOL 	; равен ли символ ограничителю?
		je input_err 
		
push:		
		mov [edi], al 	; записать элемент в стек
		inc edi			; переход к след. элементу

		cmp byte [array+12], SYMBOL	 ; достигнута ли граница?
		jne over_err 
		jmp again 
in_out:		
			
			
; Вывод стека

out:		
		PUTCHAR 10
		PRINT "Содеримое стека: "
		mov edi, array

prepare:	
		inc edi
		cmp byte [edi], SYMBOL	 ; достигнут ли ограничитель?
		jne prepare
						
pop:		
		dec edi
		PUTCHAR [edi]
		cmp edi,array 
		jne pop
		PUTCHAR 10	
		call quit
    
input_err:	PUTCHAR 10
		PRINT "Stack is full!"
		call quit
			
over_err: 	PUTCHAR 10
		PRINT "Переполнение стека!"
		call quit		
