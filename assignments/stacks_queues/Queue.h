#pragma once
#include "Node.h"

class Queue{
private:
  Node * head = nullptr;
  Node * tail = nullptr;
  int * queue;
public:
  Queue();
  void enqueue(int val); // add a value to the queue
  int dequeue(); //the value at the front is removed and returned
  int front(); //returns the value at the front of the queue
  bool is_empty(); //returns whether the queue is empty
  bool is_full(); //returns whether the queue is full
};
