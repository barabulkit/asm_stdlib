section .data
simple_str: db 'abcdefg', 0

section .text
%include "lib.inc"

global _start
_start:

mov rdi, 102
call print_unsigned_int
call print_newline

mov rdi, -102
call print_signed_int
call print_newline

mov rdi, simple_str
call print_char
call print_newline

mov rdi, simple_str
call strlen

mov rdi, rax
call print_unsigned_int
call print_newline

mov rdi, simple_str
call print_string
call print_newline

mov rdi, 0
call exit