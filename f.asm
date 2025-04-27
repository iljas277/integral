section .text
global f2
f2:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp + 8]  
    mov ecx, 4
.cycle:
    fmul qword[ebp + 8] 
    loop .cycle
    leave
    ret   
global f3
f3:
    push ebp
    mov ebp, esp
    finit
    fld1
    fld1
    faddp
    fld1
    faddp
    fld qword[ebp + 8]
    fchs
    fld1
    faddp
    fdiv st1
    leave
    ret


global f1
f1:
    push ebp
    mov ebp, esp
    finit
    fld qword [ebp + 8] 
    fld qword[ebp + 8]
    frndint
    fsubp st1              
    f2xm1  
    fld1              
    fadd st0, st1        
    fld qword[ebp + 8]
    fxch st1
    fscale  
    fld1             
    faddp st1, st0       
    mov esp, ebp
    pop ebp
    ret
global der_f2
der_f2:
    push ebp
    mov ebp, esp
    finit
    fld1
    xor ecx, ecx
    .c1:
        cmp ecx, 4
        je .e1
        fld1
        faddp
        inc ecx
        jmp .c1
    .e1:
    fld qword[ebp + 8]
    xor ecx, ecx
    .c2:
        cmp ecx, 3
        je .e2
        fmul qword[ebp + 8]
        inc ecx
        jmp .c2
    .e2:
    fmul st1
    leave
    ret
global der_f3
der_f3:
    push ebp
    mov ebp, esp
    finit
    fld1
    fld1
    faddp
    fld1
    faddp
    fld1
    fdiv st1
    fchs
    leave 
    ret
global der_f1
der_f1:
    push ebp
    mov ebp, esp
    finit
    fld qword [ebp + 8] 
    fld qword[ebp + 8]
    frndint
    fsubp st1              
    f2xm1  
    fld1              
    fadd st0, st1        
    fld qword[ebp + 8]
    fxch st1
    fscale                

    fldln2               
    fmulp st1, st0       
    leave
    ret