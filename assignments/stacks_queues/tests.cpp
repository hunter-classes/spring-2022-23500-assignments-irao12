#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "Stack.h"

Stack * s = new Stack();

TEST_CASE("Testing the constructor, push, and top"){
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
}

TEST_CASE("Testing is_empty()"){
  s->pop();
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
