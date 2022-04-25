#include "Stack.h"

Stack::Stack(){
  stack = nullptr;
}

Stack::~Stack(){
  Node * curr = stack;
  while (stack){
    Node * temp = stack;
    stack = stack->getNext();
    delete temp;
  }
}

void Stack::push(int val){
  Node * temp = new Node(val, stack);
  stack = temp;
  return;
}

int Stack::pop(){
  if (stack == nullptr) throw ERR_STACK_EMPTY;
  int val = stack->getData();
  Node * removing = stack;
  stack = stack->getNext();
  delete removing;
  return val;
}

int Stack::top(){
  if (stack == nullptr) throw ERR_STACK_EMPTY;
  return stack->getData();
}

bool Stack::is_empty(){
  if (stack == nullptr) return true;
  return false;
}
