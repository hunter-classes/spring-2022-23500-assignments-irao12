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

TEST_CASE("Testing rinsert"){
  BSTree t2;
  t2.rinsert(2);
  CHECK(t2.get_debug_string() == ", 2, ");
  t2.rinsert(10);
  CHECK(t2.get_debug_string() == ", 2, , 10, ");
  t2.rinsert(0);
  CHECK(t2.get_debug_string() == ", 0, , 2, , 10, ");
  t2.rinsert(25);
  CHECK(t2.get_debug_string() == ", 0, , 2, , 10, , 25, ");
  t2.rinsert(-12);
  CHECK(t2.get_debug_string() == ", -12, , 0, , 2, , 10, , 25, ");
}

TEST_CASE("Testing rdelete"){
  BSTree t3;
  try{
    t3.delete_val(2);
  } catch (int e){
    CHECK(e == 1);
  }
  t3.setup();
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
  t3.delete_val(10);
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 15, , 20, , 30, ");

  t3.delete_val(30);
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 15, , 20, ");
  t3.delete_val(5);
  CHECK(t3.get_debug_string() == ", 3, , 8, , 15, , 20, ");

  try{
    t3.delete_val(100);
  } catch (int e){
    CHECK(e == 1);
  }
  try{
    t3.delete_val(10);
  } catch (int e){
    CHECK(e == 1);
  }
  try{
    t3.delete_val(5);
  } catch (int e){
    CHECK(e == 1);
  }

  t3.delete_val(15);
  CHECK(t3.get_debug_string() == ", 3, , 8, , 20, ");
  t3.delete_val(3);
  CHECK(t3.get_debug_string() == ", 8, , 20, ");
  t3.delete_val(8);
  CHECK(t3.get_debug_string() == ", 20, ");
  t3.delete_val(20);
  CHECK(t3.get_debug_string() == "");

}

/*
TEST_CASE("Testing rdelete"){
  BSTree t3;
  try{
    t3.rdelete(2);
  } catch (int e){
    CHECK(e == 1);
  }

  t3.setup();
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
  t3.rdelete(10);
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 15, , 20, , 30, ");
  t3.rdelete(30);
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 15, , 20, ");
  t3.rdelete(5);
  CHECK(t3.get_debug_string() == ", 3, , 8, , 15, , 20, ");

  try{
    t3.rdelete(100);
  } catch (int e){
    CHECK(e == 1);
  }
  try{
    t3.rdelete(10);
  } catch (int e){
    CHECK(e == 1);
  }
  try{
    t3.rdelete(5);
  } catch (int e){
    CHECK(e == 1);
  }

  t3.rdelete(15);
  CHECK(t3.get_debug_string() == ", 3, , 8, , 20, ");
  t3.rdelete(3);
  CHECK(t3.get_debug_string() == ", 8, , 20, ");
  t3.rdelete(8);
  CHECK(t3.get_debug_string() == ", 20, ");
  t3.rdelete(20);
  CHECK(t3.get_debug_string() == "");
}
*/
