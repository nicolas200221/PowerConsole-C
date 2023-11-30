all: output

output:
	gcc -std=c99 -Llib\ -lpowerconsole test.c -o test.exe