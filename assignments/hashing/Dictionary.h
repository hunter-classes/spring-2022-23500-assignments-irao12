#pragma once
#include "List.h"

#define DICT_ERR_NOT_FOUND 1

class Dictionary{
private:
  List ** table;
public:
  Dictionary();
  ~Dictionary();
  int hash_func(std::string key); // made public for testing purposes
  Person * retrieve(std::string name);
  void insert(Person *p);
  std::string get_names();

};
