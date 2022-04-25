#include <iostream>
#include "Queue.h"


Queue::Queue(){
  head = 0;
  tail = 0;
  queue = new int[5];
}

Queue::~Queue(){
  delete [] queue;
}


void Queue::enqueue(int val){ // add a value to the queue
  if (head == tail){
    queue[head] = val;
    tail++;
  }

  else if (is_full()){
    throw QUEUE_ERR_FULL;
  }

  else{
    queue[tail%5] = val;
    tail++;
  }
  return;
}


int Queue::dequeue(){ //the value at the front is removed and returned
  if (is_empty()){
    throw QUEUE_ERR_EMPTY;
  }

  int result = queue[head];
  head++;

  return result;

}



int Queue::front(){ //returns the value at the front of the queue
  if (is_empty()){
    throw QUEUE_ERR_EMPTY;
  }

  return queue[head];
}

bool Queue::is_empty(){ //returns whether the queue is empty
  if (head == tail) return true;
  return false;
}

bool Queue::is_full(){ //returns whether the queue is full
  if (tail % 5 == head - 1 || head == 0 && tail == 5 ) return true;
  else return false;
}
