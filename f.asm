section .data
    three dq 3.0
    five dq 5.0
section .text
global f2
f2:
    push ebp
    mov ebp, esp
    finit
    fld qword[ebp + 8]  
    fmul qword[ebp + 8]
    fld st0
    fmulp st1
    fmul qword[ebp + 8]
    leave
    ret   
global f3
f3:
    push ebp
    mov ebp, esp
    finit
    fld qword[three]
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
    fld qword[ebp + 8]
    fmul qword[ebp + 8]
    fld st0
    fmulp st1
    fmul qword[five]
    leave
    ret
global der_f3
der_f3:
    push ebp
    mov ebp, esp
    finit
    fld1
    fdiv qword[three]
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