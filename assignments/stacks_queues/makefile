main: Stack.o Queue.o Node.o main.o
	g++ -o main -std=c++11 Stack.o Queue.o Node.o main.o

tests: tests.o Stack.o Queue.o Node.o
	g++ -o tests -std=c++11 Stack.o Queue.o Node.o tests.o

Stack.o: Stack.cpp Stack.h Node.h
	g++ -c -std=c++11 Stack.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c -std=c++11 Queue.cpp

Node.o: Node.cpp Node.h
	g++ -c -std=c++11 Node.cpp

main.o: main.cpp Stack.h Queue.h
	g++ -c -std=c++11 main.cpp

tests.o: tests.cpp Stack.h Queue.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f *.o
