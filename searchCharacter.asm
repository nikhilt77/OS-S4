DATA SEGMENT
    msg1 db 10, 13, 'Enter string: $'
    msg2 db 10, 13, 'Enter character to search: $'
    msg3 db 10, 13, 'Character found in string at position: $'
    msg4 db 10, 13, 'Character not found in string.$'
    str1 db 50 dup(?)
    target_char db ?
    pos db 0
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE, DS:DATA

START:
    MOV AX, DATA
    MOV DS, AX
    
    LEA DX, msg1
    MOV AH, 09H
    INT 21H
    
    LEA SI, str1
NEXT:
    MOV AH, 01H
    INT 21H
    CMP AL, 13
    JE TERMINATE_INPUT
    MOV [SI], AL
    INC SI
    JMP NEXT

TERMINATE_INPUT:
    MOV BYTE PTR [SI], '$'

    LEA DX, msg2
    MOV AH, 09H
    INT 21H
    
    MOV AH, 01H
    INT 21H
    MOV [target_char], AL

    LEA SI, str1
    MOV DI, 0

SEARCH_LOOP:
    MOV AL, [SI]
    CMP AL, '$'
    JE NOT_FOUND
    CMP AL, [target_char]
    JE CHARACTER_FOUND
    INC SI
    INC DI
    JMP SEARCH_LOOP

CHARACTER_FOUND:
    LEA DX, msg3
    MOV AH, 09H
    INT 21H
    
    MOV AX, DI

    CMP AX, 10
    JL PRINT_SINGLE_DIGIT

    MOV BX, 10
    DIV BX

    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    ADD AH, '0'
    MOV DL, AH
    MOV AH, 02H
    INT 21H
    JMP END_PROGRAM

PRINT_SINGLE_DIGIT:
    ADD AL, '0'
    MOV DL, AL
    MOV AH, 02H
    INT 21H

    JMP END_PROGRAM

NOT_FOUND:
    LEA DX, msg4
    MOV AH, 09H
    INT 21H

END_PROGRAM:
    MOV AH, 4CH
    INT 21H

CODE ENDS
END START
