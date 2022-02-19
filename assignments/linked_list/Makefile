main: main.o List.o Node.o
	g++ -o main main.o Node.o List.o

main.o: main.cpp Node.h
	g++ -c main.cpp

List.o: List.cpp List.h Node.h
	g++ -c List.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -rf Node.o main.o List.o main
