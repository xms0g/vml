section .text
global __vec_add
global __vec_sub
global __vec_mul
global __vec_div
global __vec_max
global __vec_min
global __vec_sadd
global __vec_ssub
global __vec_smul
global __vec_sdiv
global __vec_neg
global __vec_abs
global __vec_norm
global __vec_len
global __vec_dot

; -------------------------------------------------------------
; void _vec_add(float* result, float* v1, float* v2, int len)  ;
; rdi = result                                                 ;
; rsi = v1                                                     ;
; rdx = v2                                                     ;
; rcx = len                                                    ;
; -------------------------------------------------------------
__vec_add:
    xor r8, r8
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    movups xmm1, [rdx + r8]
    addps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    movss xmm1, [rdx + r8]
    addss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; -------------------------------------------------------------
; void _vec_sub(float* result, float* v1, float* v2, int len)  ;
; rdi = result                                                 ;
; rsi = v1                                                     ;
; rdx = v2                                                     ;
; rcx = len                                                    ;
; -------------------------------------------------------------
__vec_sub:
    xor r8, r8 
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    movups xmm1, [rdx + r8]
    subps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    movss xmm1, [rdx + r8]
    subss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; -------------------------------------------------------------
; void _vec_mul(float* result, float* v1, float* v2, int len)  ;
; rdi = result                                                 ;
; rsi = v1                                                     ;
; rdx = v2                                                     ;
; rcx = len                                                    ;
; -------------------------------------------------------------
__vec_mul:
   xor r8, r8 
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    movups xmm1, [rdx + r8]
    mulps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    movss xmm1, [rdx + r8]
    mulss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; -------------------------------------------------------------
; void _vec_div(float* result, float* v1, float* v2, int len)  ;
; rdi = result                                                 ;
; rsi = v1                                                     ;
; rdx = v2                                                     ;
; rcx = len                                                    ;
; -------------------------------------------------------------
__vec_div:
    xor r8, r8 
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    movups xmm1, [rdx + r8]
    divps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    movss xmm1, [rdx + r8]
    divss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; -------------------------------------------------------------
; void _vec_max(float* result, float* v1, float* v2, int len)  ;
; rdi = result                                                 ;
; rsi = v1                                                     ;
; rdx = v2                                                     ;
; rcx = len                                                    ;
; -------------------------------------------------------------
__vec_max:
    xor r8, r8 
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    movups xmm1, [rdx + r8]
    maxps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    movss xmm1, [rdx + r8]
    maxss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; -------------------------------------------------------------
; void _vec_min(float* result, float* v1, float* v2, int len)  ;
; rdi = result                                                 ;
; rsi = v1                                                     ;
; rdx = v2                                                     ;
; rcx = len                                                    ;
; -------------------------------------------------------------
__vec_min:
    xor r8, r8 
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    movups xmm1, [rdx + r8]
    minps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    movss xmm1, [rdx + r8]
    minss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; --------------------------------------------------------------
; void _vec_sadd(float* result, float* v1, int scalar, int len) ;
; rdi = result                                                  ;
; rsi = v1                                                      ;
; rdx = scalar                                                  ;
; rcx = len                                                     ;
; --------------------------------------------------------------  
__vec_sadd:
    xor r8, r8
    cvtsi2ss xmm1, rdx
    shufps xmm1, xmm1, 0x00         ;fill xmm1 with scalar
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    addps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    addss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; --------------------------------------------------------------
; void _vec_ssub(float* result, float* v1, int scalar, int len) ;
; rdi = result                                                  ;
; rsi = v1                                                      ;
; rdx = scalar                                                  ;
; rcx = len                                                     ;
; -------------------------------------------------------------- 
__vec_ssub:
    xor r8, r8
    cvtsi2ss xmm1, rdx
    shufps xmm1, xmm1, 0x00         ;fill xmm1 with scalar
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    subps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    subss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; --------------------------------------------------------------
; void _vec_smul(float* result, float* v1, int scalar, int len) ;
; rdi = result                                                  ;
; rsi = v1                                                      ;
; rdx = scalar                                                  ;
; rcx = len                                                     ;
; --------------------------------------------------------------
__vec_smul:
    xor r8, r8
    cvtsi2ss xmm1, rdx
    shufps xmm1, xmm1, 0x00         ;fill xmm1 with scalar
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    mulps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    mulss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; --------------------------------------------------------------
; void _vec_sdiv(float* result, float* v1, int scalar, int len) ;
; rdi = result                                                  ;
; rsi = v1                                                      ;
; rdx = scalar                                                  ;
; rcx = len                                                     ;
; -------------------------------------------------------------- 
__vec_sdiv:
    xor r8, r8
    xorps xmm0, xmm0
    xorps xmm1, xmm1
    cvtsi2ss xmm1, rdx
    shufps xmm1, xmm1, 0x00 
.loop:
    cmp rcx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    divps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rcx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    divss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; ------------------------------------------------------------
; void _vec_neg(float* result, float* v1, int len)            ;   
; rdi = result                                                ;
; rsi = v1                                                    ;  
; rdx = len                                                   ;                                             
; ------------------------------------------------------------
__vec_neg:
    xor r8, r8
    mov rcx, -1
    cvtsi2ss xmm1, rcx
    shufps xmm1, xmm1, 0x00         ;fill xmm1 with -1
.loop:
    cmp rdx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    mulps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rdx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    mulss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rdx
    jg .remainder
.done:
    ret

; ------------------------------------------------------------
; void _vec_abs(float* result, float* v1, int len)            ;   
; rdi = result                                                ;
; rsi = v1                                                    ;  
; rdx = len                                                   ;                                             
; ------------------------------------------------------------
__vec_abs:
    xor r8, r8
    pcmpeqd xmm1, xmm1          ; xmm1 = all 1s
    psrld xmm1, 1             ; shift right → 0x7FFFFFFF in all lanes
.loop:
    cmp rdx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    andps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rdx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    andps xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rdx
    jg .remainder
.done:
    ret

; ------------------------------------------------------------
; void _vec_norm(float* result, float* v1, int len)           ;   
; rdi = result                                                ;
; rsi = v1                                                    ;  
; rdx = len                                                   ;                                             
; ------------------------------------------------------------
__vec_norm:
    push rdi
    push rsi
    mov rdi, rsi
    mov rsi, rdx
    call __vec_len
    xorps xmm1, xmm1
    ucomiss xmm0, xmm1      ;if len is zero, we are done
    je .done
    movss xmm1, xmm0
    shufps xmm1, xmm1, 0x00
    xor r8, r8
    pop rsi
    pop rdi
.loop:
    cmp rdx, 4
    jl .remainder

    movups xmm0, [rsi + r8]
    divps xmm0, xmm1
    movups [rdi + r8], xmm0 
    add r8, 16                      ; 4 floats 16 bytes
    sub rdx, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rsi + r8]
    divss xmm0, xmm1
    movss [rdi + r8], xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rcx
    jg .remainder
.done:
    ret

; ------------------------------------------------------------
; float _vec_len(float* v1, int len)                          ;   
; rdi = v1                                                    ;
; rsi = len                                                   ;                                               
; ------------------------------------------------------------
__vec_len:
   xor r8, r8
   xorps xmm1, xmm1
   xorps xmm0, xmm0
.loop:
    cmp rsi, 4
    jl .remainder
    
    movups xmm0, [rdi + r8]
    mulps xmm0, xmm0        ;square each element
    haddps xmm0, xmm0       ;horizontal add
    haddps xmm0, xmm0
    addss xmm1, xmm0
    add r8, 16
    sub rsi, 4
    jg .loop
    jmp .done
.remainder:
    movss xmm0, [rdi + r8]
    mulss xmm0, xmm0
    addss xmm1, xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rsi
    jg .remainder         
.done:
    sqrtps xmm0, xmm1       ;square root
    ret

; -------------------------------------------------------------
; float _vec_dot(float* v1, float* v2, int len)                ;
; rdi = v1                                                     ;
; rsi = v2                                                     ;
; rdx = len                                                    ;
; -------------------------------------------------------------
__vec_dot:
   xor r8, r8
   xorps xmm2, xmm2
   xorps xmm0, xmm0
   xorps xmm1, xmm1
.loop:
    cmp rdx, 4
    jl .remainder

    movups xmm0, [rdi + r8]
    movups xmm1, [rsi + r8]
    mulps xmm0, xmm1
    haddps xmm0, xmm0   ;horizontal add
    haddps xmm0, xmm0
    addss xmm2, xmm0
    add r8, 16
    sub rdx, 4
    jg .loop
    jmp .remainder
.remainder:
    movss xmm0, [rdi + r8]
    movss xmm1, [rsi + r8]
    mulss xmm0, xmm1
    addss xmm2, xmm0
    add r8, 4                       ; 1 float 4 bytes
    dec rdx
    jg .remainder
.done:
    movss xmm0, xmm2
    ret