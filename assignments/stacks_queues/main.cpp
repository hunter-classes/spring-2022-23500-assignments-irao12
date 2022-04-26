#include <iostream>
#include "Stack.h"
#include "Queue.h"

int main(){
  std::cout << "Creating a new stack" << '\n';
  Stack * s = new Stack();
  std::cout << "The stack is empty: " << std::boolalpha << s->is_empty() << '\n';
  std::cout << "Pushing 1, 2, and 3 onto the stack" << '\n';
  s->push(1);
  s->push(2);
  s->push(3);
  std::cout << "The int at the top of the stack: " << s->top() << '\n';
  std::cout << "Popping the stack 3 times" << '\n';
  std::cout << "\tPopped: " << s->pop();
  std::cout << ", Popped: " << s->pop();
  std::cout << ", Popped: " << s->pop() << '\n';

  std::cout << "Popping one more time" << '\n';
  try {
    s->pop();
  }
  catch(int e){
    std::cout << "\tAttempted to pop an empty stack" << '\n';
  }

  std::cout << "The int at the top of the stack: " << '\n';
  try{
    s->pop();
  }
  catch (int e){
    std::cout << "\tAttempted to look at the top of an empty stack" << '\n';
  }

  delete s;

  std::cout << "\nCreating a new queue" << '\n';
  Queue * q = new Queue();

  std::cout << "The queue is empty: " << std::boolalpha << q->is_empty() << '\n';
  std::cout << "Enqueueing a 1 to the queue" << '\n';
  q->enqueue(1);
  std::cout << "The int at the front of the queue: " << q->front() << '\n';
  std::cout << "Enqueueing 2, 3, 4, and 5 to the queue" << '\n';
  q->enqueue(2);
  q->enqueue(3);
  q->enqueue(4);
  q->enqueue(5);
  std::cout << "The int at the front of the queue: " << q->front() << '\n';
  std::cout << "Enqueueing a 6 to the queue" << '\n';
  try{
    q->enqueue(6);
  }
  catch (int e){
    std::cout << "\tAttempted to enqueue to a full queue" << '\n';
  }

  std::cout << "The queue is full: " << std::boolalpha << q->is_full() << '\n';
  std::cout << "Dequeueing 5 times" << '\n';
  std::cout << "\tDequeued: " << q->dequeue();
  std::cout << ", Dequeued: " << q->dequeue();
  std::cout << ", Dequeued: " << q->dequeue();
  std::cout << ", Dequeued: " << q->dequeue();
  std::cout << ", Dequeued: " << q->dequeue() << '\n';

  std::cout << "Dequeueing one more time" << '\n';
  try{
    q->dequeue();
  }
  catch (int e){
    std::cout << "\tAttempted to dequeue an empty queue" << '\n';
  }
  std::cout << "The queue is full: " << std::boolalpha << q->is_full() << '\n';

  std::cout << "Front of the queue: ";
  try{
    q->front();
  }
  catch (int e) {
    std::cout << "\n\tAttempted to look at the front of an empty queue" << '\n';
  }

  delete q;

  return 0;
}
