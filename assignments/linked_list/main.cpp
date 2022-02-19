#include <iostream>

#include "Node.h"

int main() {
  Node *p1 = new Node();
  p1->setData("hello");
  Node *p2 = new Node("World");
  p1->setNext(p2);

  std::cout << p1->getData() << '\n';
  std::cout << p2->getData() << '\n';
  std::cout << p1->getNext()->getData() << '\n';

  p2 = new Node("!");

  p1->getNext()->setNext(p2);

  std::cout << p1->getData() << '\n';
  std::cout << p1->getNext()->getData() << '\n';
  std::cout << p1->getNext()->getNext()->getData() << '\n';

  Node *walker = p1;

  while (walker != nullptr){
    std::cout << walker->getData() << '\n';
    walker = walker->getNext();
  }

  return 0;
}
