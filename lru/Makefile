
CC=g++
flag=-std=c++11 
all: main.o
	$(CC) $(flag) main.o -o p

main.o: main.c lru.h
	$(CC) $(flag) -c main.c 

clean: 
	rm -f *.o p
	


