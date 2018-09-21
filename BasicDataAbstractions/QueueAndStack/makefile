main: main.cpp Executive.o LinkedQueue.o LinkedStack.o PrecondViolatedExcep.o LinkedQueue.o LinkedStack.o Node.o
	g++ -o main main.cpp Executive.o PrecondViolatedExcep.o

Executive.o: Executive.h Executive.cpp
	g++ -c Executive.h Executive.cpp

LinkedQueue.o: LinkedQueue.h LinkedQueue.cpp
	g++ -o LinkedQueue.o -c LinkedQueue.h

LinkedStack.o: LinkedStack.h LinkedStack.cpp
	g++ -o LinkedStack.o -c LinkedStack.h

PrecondViolatedExcep.o: PrecondViolatedExcep.h PrecondViolatedExcep.cpp
	g++ -o PrecondViolatedExcep.o -c PrecondViolatedExcep.cpp

Node.o: Node.h Node.cpp
	g++ -o Node.o -c Node.h

clean:
	rm -f *.o *.gch main