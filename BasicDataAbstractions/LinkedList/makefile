main: main.cpp Executive.o Count.h Count.cpp CountList.h CountList.cpp
	g++ -o main main.cpp Executive.o Count.h CountList.h

Executive.o: Executive.h Executive.cpp
	g++ -c Executive.h Executive.cpp

clean:
	rm main *.o