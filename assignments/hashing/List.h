#pragma once
#include "Node.h"

class List{
private:
  Node *head;
public:
  List();
  ~List();
  void insert(Person *p);
  std::string toString();
  Node * locate(int index);
  void remove(int index);
};
