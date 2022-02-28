main: main.o OList.o Node.o
	g++ -o main main.o Node.o OList.o

tests: tests.o OList.o Node.o
	g++ -std=c++11 -o tests tests.o OList.o Node.o

main.o: main.cpp Node.h
	g++ -c main.cpp

tests.o: tests.cpp OList.h
	g++ -std=c++11 -c test.cpp

OList.o: OList.cpp OList.h Node.h
	g++ -std=c++11 -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -c Node.cpp

clean:
	rm -rf *.o main
