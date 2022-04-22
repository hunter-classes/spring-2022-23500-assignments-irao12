OBJECTS=main.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS)
BSTree.o: BSTree.cpp Node.h BSTree.h
	g++ -c -std=c++11 BSTree.cpp
main.o: main.cpp Node.h BSTree.h
	g++ -c -std=c++11 main.cpp
Node.o: Node.cpp Node.h
	g++ -c -std=c++11 Node.cpp
clean:
	rm -f $(OBJECTS)
