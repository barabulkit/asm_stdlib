section .data
simple_str: db 'abcd', 0

section .text
%include "lib.inc"

global _start
_start:

mov rdi, simple_str
call print_char

mov rdi, 0
call exit