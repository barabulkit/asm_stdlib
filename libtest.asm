section .data
simple_str: db 'abcdefg', 0
buffer: times 5 db 0

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

call read_char
mov rdi, rax
call print_char
call print_newline


mov rdi, buffer
mov rsi, 4
call read_string
call print_newline
mov rdi, buffer
call print_string
call print_newline

mov rdi, buffer
call parse_uint
mov rdi, rax
call print_unsigned_int

mov rdi, 0
call exit