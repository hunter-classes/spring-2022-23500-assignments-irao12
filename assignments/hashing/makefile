main: Person.o Node.o List.o Dictionary.o main.o
	g++ -o main Person.o Node.o List.o Dictionary.o main.o

main.o: Dictionary.h main.cpp
	g++ -c -std=c++11 main.cpp

Person.o: Person.h Person.cpp
	g++ -c -std=c++11 Person.cpp

Node.o: Node.h Node.cpp Person.h
	g++ -c -std=c++11 Node.cpp

List.o: List.h List.cpp Node.h
	g++ -c -std=c++11 List.cpp

Dictionary.o: Dictionary.h Dictionary.cpp List.h
	g++ -c -std=c++11 Dictionary.cpp

clean:
	rm -f *.o 
