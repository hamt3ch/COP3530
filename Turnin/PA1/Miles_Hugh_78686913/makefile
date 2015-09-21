all: PA1

PA1: josephus.o
	g++ josephus.o -o josephus

josephus.o: josephus.cpp CircularSingleLinkedList_HAM.h
	g++ -c josephus.cpp

clean:
	$(RM) main
