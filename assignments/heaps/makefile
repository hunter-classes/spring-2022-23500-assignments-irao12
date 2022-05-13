main: main.o Heap.o
	g++ -o main main.o Heap.o

tests: tests.o Heap.o
	g++ -o tests tests.o Heap.o

tests.o: tests.cpp Heap.h
	g++ -c -std=c++11 tests.cpp

main.o: main.cpp Heap.h
	g++ -c -std=c++11 main.cpp

Heap.o: Heap.cpp Heap.h
	g++ -c -std=c++11 Heap.cpp

clean:
	rm -f *.o main tests
