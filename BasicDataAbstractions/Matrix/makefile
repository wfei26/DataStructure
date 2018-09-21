main: main.cpp matrix.o
	g++ -o main main.cpp matrix.o

matrix.o: matrix.h matrix.cpp
	g++ -c matrix.h matrix.cpp

clean:
	rm main *.o