#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "Stack.h"
#include "Queue.h"

//Testing the Stack class
Stack * s = new Stack();

TEST_CASE("Testing the constructor, push, and top"){
  try{
    s->top();
  }
  catch (int e){
    CHECK(e == 1); //ERR_STACK_EMPTY
  }

  s->push(5);
  CHECK(s->top() == 5);
  s->push(10);
  s->push(12);
  CHECK(s->top() == 12);
  s->push(15);
  s->push(20);
  CHECK(s->top() != 15);
  CHECK(s->top() == 20);
  s->push(-23);
  CHECK(s->top() == -23);
}

TEST_CASE("Testing pop()"){
  CHECK(s->top() == -23);
  s->pop();
  CHECK(s->top() == 20);
  s->pop();
  CHECK(s->top() == 15);
  s->pop();
  s->pop();
  CHECK(s->top() == 10);
  s->pop();
  CHECK(s->top() == 5);
  s->pop();

  try{
    s->pop();
  }
  catch (int e){
    CHECK(e == 1); //ERR_STACK_EMPTY
  }
}

TEST_CASE("Testing is_empty()"){
  CHECK(s->is_empty());
  s->push(10);
  CHECK(!s->is_empty());
  s->push(20);
  CHECK(!s->is_empty());
  s->push(30);
  CHECK(!s->is_empty());
  s->pop();
  s->pop();
  s->pop();
  CHECK(s->is_empty());

  delete s;
}

//Testing the Queue class
Queue * q = new Queue();

TEST_CASE("Testing constructor, enqueue, dequeue, and front"){
  try {
    q->front();
  }
  catch (int e){
    CHECK(e == 1); //QUEUE_ERR_EMPTY
  }

  q->enqueue(0);
  CHECK(q->front() == 0);
  q->enqueue(1);
  CHECK(q->front() == 0);
  int val = q->dequeue();
  CHECK(val == 0);
  CHECK(q->front() == 1);
  q->enqueue(2);
  CHECK(q->front() == 1);
  q->enqueue(3);
  CHECK(q->front() == 1);
  q->enqueue(4);
  q->enqueue(5);
  
  try {
    q->enqueue(6);
  }
  catch (int e){
    CHECK(e == 2); //QUEUE_ERR_FULL
  }

}

Queue * q2 = new Queue();

TEST_CASE("Testing is is_full"){
  CHECK(q->is_full()); //should be true since we filled the queue with 0 to 4
  q->dequeue(); // remove one element
  CHECK(!q->is_full()); //should not be full after dequeueing
  q->enqueue(5); //enqueue again to test if is_full works with a different head
  CHECK(q->is_full()); //should test true since we enqueued again

  try {
    q2->dequeue();
  }
  catch (int e){
    CHECK(e == 1); //QUEUE_ERR_EMPTY
  }

  CHECK(!q2->is_full()); //empty queue, should not be full
  q2->enqueue(0);
  q2->enqueue(1);
  q2->enqueue(2);
  q2->enqueue(3);
  q2->enqueue(4); // queue is now full
  CHECK(q2->is_full()); //tests if queue is full when head is 0, should be full
  delete q;
}
