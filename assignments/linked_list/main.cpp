#include <iostream>
#include "OList.h"

int main() {
  std::cout << "Creating a new list" << '\n';
  OList * list = new OList();
  std::cout << "list: " << list->toString() << '\n';
  std::cout << "\nInserting 12, 2, 6, 24, -5, and 0" << '\n';
  list->insert(12);
  list->insert(2);
  list->insert(6);
  list->insert(24);
  list->insert(-5);
  list->insert(0);
  std::cout << "list: " << list->toString() << '\n';

  std::cout << "\nlist->contains(100): ";
  std::cout << std::boolalpha << (list->contains(100)) << '\n';
  std::cout << "list->contains(12): ";
  std::cout << std::boolalpha << (list->contains(12)) << '\n';
  std::cout << "list->contains(0): ";
  std::cout << std::boolalpha << (list->contains(12)) << '\n';
  std::cout << "list->contains(24): ";
  std::cout << std::boolalpha << (list->contains(24)) << '\n';

  std::cout << "\nlist->get(0): " << list->get(0) << '\n';
  std::cout << "list->get(2): " << list->get(2) << '\n';
  std::cout << "list->get(5): " << list->get(5) << '\n';

  std::cout << "\nlist->remove(0):"<< '\n';
  list->remove(0);
  std::cout << "list: " << list->toString() << '\n';
  std::cout << "list->remove(4):"<< '\n';
  list->remove(4);
  std::cout << "list: " << list->toString() << '\n';

  std::cout << "\nreversing the list:" << '\n';
  list->reverse();
  std::cout << "list: " << list->toString() << '\n';
  std::cout << "reversing the list again:" << '\n';
  list->reverse();
  std::cout << "list: " << list->toString() << '\n';
  
  return 0;
}
