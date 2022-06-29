section .data
digits: db '0123456789'
minus: db '-'
newline: db 0xA

section .text
strlen:
    mov rax, rdi
    mov rcx, 0
loop:
    mov dh, byte [rax + rcx]
    test dh, dh
    jz end
    inc rcx
    jmp loop
end:
    mov rax, rcx
    ret

print_char:
    lea rsi, [rdi]
    mov rax, 1
    mov rdi, 1
    mov rdx, 1
    syscall
    ret

print_newline:
    mov rdi, newline
    call print_char
    ret

print_signed_int:
    mov rax, rdi
    cmp rax, 0
    jge print
    mov rdi, minus
    push rax
    call print_char
    pop rax
    neg rax
    mov rdi, rax
print:
    call print_unsigned_int
    ret

print_unsigned_int:
    mov rax, rdi
    mov rbx, 10
    mov rcx, 0
print_int_loop:
    mov rdx, 0
    div rbx
    lea rsi, [digits + rdx] 
    push rsi
    inc rcx
    test rax, rax
    jnz print_int_loop
print_loop:
    pop rdi
    push rcx
    call print_char
    pop rcx
    dec rcx
    test rcx, rcx
    jnz print_loop
    ret

exit:
    mov rax, 60
    syscall
    ret