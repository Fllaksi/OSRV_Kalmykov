all: main testing
debug: main.c
	gcc -g -o main_debug main.c
main : main.c
	gcc -o main main.c
testing: testing.c
	gcc -o testing testing.c
clean:
	rm -f main testing main_debug
