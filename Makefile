all: output

output:
	gcc test.c -std=c99 -L.\lib -lpowerconsole -o test.exe