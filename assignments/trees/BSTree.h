#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"

class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();

  void setup();

  std::string get_debug_string();


  // std::string traverse(Node *n);

  int search(int value);

  int rsearch(int value);
  int rsearch(int value, Node *p);

  void insert(int value);

  void rinsert(int value);
  void rinsert(int value, Node *p);

  void delete_val(int value);

  // void rdelete(int value);
  // void rdelete(int value, Node * parent, Node * curr);
  // int treesum();
  // int treesum(Node *n);

};
