section .data
digits: db '0123456789', 0
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
    mov rsi, rdi
    mov rax, 1
    mov rdi, 1
    mov rdx, 1
    syscall
    ret

print_string:
    call strlen
    mov rdx, rax
    mov rax, 1
    lea rsi, [rdi]
    mov rdi, 1
    syscall
    ret

print_newline:
    lea rdi, [newline]
    call print_char
    ret

print_signed_int:
    mov rax, rdi
    cmp rax, 0
    jge print
    lea rdi, [minus]
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

read_char:
    push rbp
    mov rbp, rsp
    sub rsp, 2
    lea rsi, [rbp - 1]
    mov rax, 0
    mov rdi, 0
    mov rdx, 2
    syscall
    lea rax, [rbp - 1]
    leave
    ret

read_string:
    mov rdx, rsi
    lea rsi, [rdi]
    mov rax, 0
    mov rdi, 0
    syscall
    ret

exit:
    mov rax, 60
    syscall
    ret