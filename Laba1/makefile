CFLAGS =
all: main testing
debug:  CFLAGS+= -g
debug: main testing
main : main.c
	gcc $(CFLAGS) -o main main.c
testing: testing
	gcc $(CLAGS) -o testing testing.c
clean:
	rm -f main testing
