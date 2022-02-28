main: main.o OList.o Node.o
	g++ -o main main.o Node.o OList.o

test: test.o OList.o Node.o
	g++ -std=c++11 -o test test.o OList.o Node.o
	
main.o: main.cpp Node.h
	g++ -c main.cpp

test.o: test.cpp OList.h
	g++ -std=c++11 -c test.cpp

OList.o: OList.cpp OList.h Node.h
	g++ -std=c++11 -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp

clean:
	rm -rf *.o main
