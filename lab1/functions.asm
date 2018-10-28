;------------------------------------------
; выход из программы
quit:
    mov     ebx, 0
    mov     eax, 1
    int     80h
    ret
    
;------------------------------------------
; вывод строки
sprint:
    push    edx
    push    ecx
    push    ebx
    push    eax
    call    slen
 
    mov     edx, eax
    pop     eax
 
    mov     ecx, eax
    mov     ebx, 1
    mov     eax, 4
    int     80h
 
    pop     ebx
    pop     ecx
    pop     edx
    ret
 
 
;------------------------------------------
; вывод строки с переходом на новую строку
sprintLF:
    call    sprint
 
    push    eax
    mov     eax, 0AH
    push    eax
    mov     eax, esp
    call    sprint
    pop     eax
    pop     eax
    ret
    
;------------------------------------------
; вычислить длинну строки
slen:
    push    ebx
    mov     ebx, eax
 
 
