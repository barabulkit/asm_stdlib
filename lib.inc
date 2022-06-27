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

exit:
    mov rax, 60
    syscall