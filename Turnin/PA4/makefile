all: PA4

PA4: main.o
	g++ main.o -o MST

sparseMatrix.o: main.cpp Graphs_HAM.h minHeap_HAM.h
	g++ -c main.cpp

clean:
	$(RM) main
