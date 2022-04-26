#pragma once
#include "Node.h"

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class Queue{
private:
  int head;
  int tail;
  int * queue;
  int count;
public:
  Queue();
  ~Queue();
  void enqueue(int val); // add a value to the queue
  int dequeue(); //the value at the front is removed and returned
  int front(); //returns the value at the front of the queue
  bool is_empty(); //returns whether the queue is empty
  bool is_full(); //returns whether the queue is full
};
