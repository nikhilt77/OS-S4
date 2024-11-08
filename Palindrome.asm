DATA SEGMENT
    msg1 db 10,13, 'Enter string:$'
    msg2 db 10,13, 'String is Palindrome$'
    msg3 db 10,13, 'String is not Palindrome$'
    str1 db 50 dup(?)
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    LEA DX,msg1
    MOV AH,09H
    INT 21H
     
    LEA SI,str1
    LEA DI,str1

NEXT:
    MOV AH,01H       ; Wait for user input (from keyboard)
    INT 21H          ; Call DOS interrupt 21h, function 01h (read character from keyboard)
    CMP AL,13        ; Check if the entered character is a carriage return (Enter key, ASCII code 13)
    JE TERMINATE     ; Jump to TERMINATE if Enter key is pressed (input is finished)
    MOV [DI],AL      ; Store the character in the string
    INC DI           ; Move DI to the next position in the string
    JMP NEXT         ; Jump back to the start of the loop to ask for the next character


TERMINATE:
    MOV AL,'$'
    MOV [DI],AL
    DEC DI
    MOV BX,DI

DOTHIS:
    MOV AL,[SI]
    CMP AL,[DI]
    JNE NOTPALINDROME
    INC SI
    DEC DI
    CMP SI,DI
    JL DOTHIS

PALINDROME:
    LEA DX,msg2
    MOV AH,09H
    INT 21H
    JMP ENDPROGRAM

NOTPALINDROME:
    LEA DX,msg3
    MOV AH,09H
    INT 21H

ENDPROGRAM:
    MOV AH,4CH
    INT 21H

CODE ENDS
END START
