.PHONY: run test

exe: solution.c
	gcc solution.c -o exe

run: exe
	./exe util_name util_param

test: exe
	./exe echo 00001000
