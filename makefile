lab1: main.cpp ListOperation.o Node.o 
	g++ -o lab1 main.cpp ListOperation.o Node.o 

Node.o: Node.h Node.cpp
	g++ -c Node.h Node.cpp

ListOperation.o: ListOperation.h ListOperation.cpp
	g++ -c ListOperation.h ListOperation.cpp

clean:
	rm -f lab1 *.o

