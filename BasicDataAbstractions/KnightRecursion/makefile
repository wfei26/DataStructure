lab5: main.cpp Executive.o KnightTour.o
	g++ -o lab5 main.cpp Executive.o KnightTour.o

KnightTour.o: KnightTour.h KnightTour.cpp
	g++ -c KnightTour.h KnightTour.cpp

Executive.o: Executive.h Executive.cpp
	g++ -c Executive.h Executive.cpp

clean:
	rm -f lab5 *.o