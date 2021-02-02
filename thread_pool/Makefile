CC=g++ 
LIB=-lpthread
FLAg=-std=c++11

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c, %.o, $(SRC))

all: $(OBJ)
	$(CC) -o p $(OBJ) $(LIB)

$(OBJ): %.o:%.c
	$(CC) $(INC) $(FLAG) -c $<

clean:
	rm -f *.o p




