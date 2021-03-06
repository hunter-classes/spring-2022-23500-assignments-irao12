#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"

#define TREE_ERR_NO_VAL 1
#define TREE_ERR_EMPTY 2
#define TREE_ERR_LEVEL_DOESNT_EXIST 4

class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);
  int get_leaf_count(Node * n);
  int get_height(Node * n);
  int get_level_sum(Node *n, int curr, int level);
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

  void remove(int value);

  int get_leaf_count();

  int get_height();

  int get_level_sum(int level);

  // void rdelete(int value);
  // void rdelete(int value, Node * parent, Node * curr);

};
