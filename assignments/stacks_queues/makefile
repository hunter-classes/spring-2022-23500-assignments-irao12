main: Stack.o Node.o main.o
	g++ -o main -std=c++11 Stack.o Node.o main.o

Stack.o: Stack.cpp Stack.h
	g++ -c -std=c++11 Stack.cpp

Node.o: Node.cpp Node.h
	g++ -c -std=c++11 Node.cpp

main.o: main.cpp Stack.h
	g++ -c -std=c++11 main.cpp

clean:
	rm -f *.o main
