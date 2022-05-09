#pragma once
#include "List.h"

class Dictionary{
private:
  List ** table;
  int hash_func(std::string key);
public:
  Dictionary();
  ~Dictionary();
  void insert(Person *p);
  std::string get_names();

};
