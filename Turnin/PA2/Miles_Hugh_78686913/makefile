all: PA2

PA2: main.o
	g++ main.o -o sparseMatrix

sparseMatrix.o: main.cpp SparseMatrix_HAM.h
	g++ -c main.cpp

clean:
	$(RM) main
