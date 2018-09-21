main: main.cpp executive.o poly.o
	g++ -o main main.cpp executive.o poly.o 

executive.o: executive.h executive.cpp
	g++ -c executive.h executive.cpp 

poly.o: poly.h poly.cpp
	g++ -c poly.h poly.cpp 

clean:
	rm main *.o *.gch
