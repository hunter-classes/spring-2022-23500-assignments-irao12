#pragma once
#include <iostream>

#include "Node.h"
#include <stdio.h>

class BSTree{
private:
  Node * root;
public:
  BSTree();
  std::string get_debug_string_helper(Node * root);
  std::string get_debug_string();
  void insert (int d);
  void setup();
};
