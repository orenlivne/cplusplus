CC=g++
CFLAGS=-I.
#DEPS=hellomake.h
OBJ=ex1.1.o ex1.2.o 

all: ex1.1 ex1.2 $(OBJ)

ex1.1: ex1.1.o
	$(CC) -o $@ $^ $(CFLAGS)
	
ex1.2: ex1.2.o
	$(CC) -o $@ $^ $(CFLAGS)
	
%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)
