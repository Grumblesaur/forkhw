all: forktest opentest waittest

forktest: forktest.o
	gcc -o forktest forktest.o
opentest: opentest.o
	gcc -o opentest opentest.o
waittest: waittest.o
	gcc -o waittest waittest.o

forktest.o: forktest.c
	gcc -c forktest.c
opentest.o: opentest.c
	gcc -c opentest.c
waittest.o: waittest.c
	gcc -c waittest.c

clean:
	rm -f *.o forktest waittest opentest
