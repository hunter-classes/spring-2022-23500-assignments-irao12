#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

BSTree *t = new BSTree();

TEST_CASE("Testing rsearch"){
  t->setup();
  int result = t->rsearch(10);
  CHECK(result == 10);
  result = t->rsearch(20);
  CHECK(result == 20);
  result = t->rsearch(30);
  CHECK(result == 30);
  result = t->rsearch(15);
  CHECK(result == 15);
  result = t->rsearch(5);
  CHECK(result == 5);
  result = t->rsearch(3);
  CHECK(result == 3);
  result = t->rsearch(8);
  CHECK(result == 8);

  try {
    int result = t->rsearch(16);
  } catch (int e){
    CHECK(e == 1);
  }
  try {
    int result = t->rsearch(100);
  } catch (int e){
    CHECK(e == 1);
  }
  try {
    int result = t->rsearch(16);
  } catch (int e){
    CHECK(e == 1);
  }
  try {
    int result = t->rsearch(21);
  } catch (int e){
    CHECK(e == 1);
  }
  try {
    int result = t->rsearch(1);
  } catch (int e){
    CHECK(e == 1);
  }

}
