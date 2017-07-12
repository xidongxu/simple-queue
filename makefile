test : test.o queue.o 
	gcc -o test test.o queue.o
test.o : test.c queue.h
	gcc -c test.c
queue.o : queue.c queue.h
	gcc -c queue.c

clean :
	rm test test.o queue.o