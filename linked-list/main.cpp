#include <iostream>
#include "List.h"

int main() {
  List *l1 = new List();
  std::cout << l1->toString() << '\n';
  l1->insert("a");
  l1->insert("b");
  l1->insert("c");
  l1->insert("d");
  l1->insert("e");
  l1->insert("f");
  std::cout << l1->toString() << '\n';
  std::cout << "\nLocating Node at index 3" << '\n';
  std::cout << l1->locate(3) << ": " << l1->locate(3)->getData()<<'\n';
  std::cout << "\nInserting \"z\" at index 2" << '\n';
  l1->insert("z", 2);
  std::cout << l1->toString() << '\n';
  std::cout << "\nRemoving Node at index 4" << '\n';
  l1->remove(4);
  std::cout << l1->toString() << '\n';
  std::cout << "\nTesting destructor" << '\n';
  delete l1;

  return 0;
}
