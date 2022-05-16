#include <iostream>
#include "Dictionary.h"

int main(){
  std::cout << "Creating a Dictionary" << '\n';
  Dictionary * dict = new Dictionary();
  std::cout << "Dictionary: " << dict->get_names() << '\n';

  Person *p0 = new Person("Ivan", "Rao", 0);
  Person *p1 = new Person("James", "Bond", 1);
  Person *p2 = new Person("Abraham", "Lincoln", 2);
  Person *p3 = new Person("John", "Cena", 3);
  Person *p4 = new Person("Lebron", "James", 4);
  Person *p5 = new Person("George", "Washington", 5);
  Person *p6 = new Person("Michael", "Jordan", 6);

  std::cout << "\nHash of James Bond: " << dict->hash_func(p1->get_name()) << '\n';

  std::cout << "\nInserting 7 people into the Dictionary" << '\n';
  dict->insert(p0);
  dict->insert(p1);
  dict->insert(p2);
  dict->insert(p3);
  dict->insert(p4);
  dict->insert(p5);
  dict->insert(p6);

  std::cout << "Dictionary: " << dict->get_names() << '\n';

  std::cout << "\nRetrieving the address of George Washington from the Dictionary: " << dict->retrieve("Washington, George")<< '\n';
  std::cout << "Address of George Washington: " << p5 << '\n';

  std::cout << "Retrieving the address of Joe Biden: " << dict->retrieve("Biden, Joe") << '\n';

  return 0;
}
