lab7: lab7.cpp Executive.o Sorts.o
	g++ -o lab7 lab7.cpp Executive.o

Executive.o: Executive.h Executive.cpp
	g++ -c Executive.cpp

Sorts.o: Sorts.h bubbleSort.c++ insertionSort.c++ mergesort.c++ quicksort.c++ selectionSort.c++
	g++ -o Sorts.o -c Sorts.h

clean:
	rm -f lab7 *.o *.gch