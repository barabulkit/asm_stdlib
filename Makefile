libtest.o: lib.inc libtest.asm
	nasm -felf64 -o libtest.o libtest.asm
libtest: libtest.o
	ld -o libtest libtest.o
