section .data
digits: db '0123456789'

section .text
strlen:
    mov rax, rdi
    mov rcx, 0
loop:
    mov rdx, [rax + rcx]
    test rdx, rdx
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

print_int:
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