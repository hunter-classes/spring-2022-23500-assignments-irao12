#pragma once
#include "Node.h"

class List{
private:
  Node *head;
public:
  List();
  ~List();
  void insert(std::string data);
  void insert(std::string data, int index);
  std::string toString();
  Node * locate(int index);
  void remove(int index);
};
