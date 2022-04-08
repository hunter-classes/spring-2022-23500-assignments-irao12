#pragma once

#include "Node.h"

#define ERR_STACK_EMPTY 1

class Stack{
public:
  Stack();
  ~Stack();
  void push(int val);
  int pop();
  int top();
  bool is_empty();
private:
  Node * stack;
};
