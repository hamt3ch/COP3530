all: PA1

PA1: main.o
	g++ main.o -o main

sparse.o: main.cpp SparseMatrix_HAM.h
	g++ -c main.cpp

clean:
	$(RM) main
