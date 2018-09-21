main: main.cpp executive.o count.h count.cpp countarray.h countarray.cpp
	g++ -o main main.cpp executive.o 

executive.o: executive.h executive.cpp
	g++ -c executive.cpp

clean:
	rm main *.o
