OBJECTS=main.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)
tests: tests.o BSTree.o Node.o doctest.h
	g++ -o tests tests.o BSTree.o Node.o
BSTree.o: BSTree.cpp Node.h BSTree.h
	g++ -c -std=c++11 BSTree.cpp
main.o: main.cpp Node.h BSTree.h
	g++ -c -std=c++11 main.cpp
tests.o: tests.cpp Node.h BSTree.h
	g++ -c -std=c++11 tests.cpp
Node.o: Node.cpp Node.h
	g++ -c -std=c++11 Node.cpp
clean:
	rm -f $(OBJECTS)
