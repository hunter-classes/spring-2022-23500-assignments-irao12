#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"

BSTree *t = new BSTree();

TEST_CASE("Testing rsearch"){
  t->setup();
  /*
             10
           /    \
          5      20
        /  \    /   \
       3   8   15   30
  */
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

TEST_CASE("Testing remove"){
  BSTree t3;
  try{
    t3.remove(2);
  } catch (int e){
    CHECK(e == 1);
  }
  t3.setup();
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
  // no children
  t3.remove(30);
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, ");
  // with only a left child
  t3.remove(3);
  CHECK(t3.get_debug_string() == ", 5, , 8, , 10, , 15, , 20, ");
  // with only a right child
  t3.remove(10);
  // with both a left and right child
  CHECK(t3.get_debug_string() == ", 5, , 8, , 15, , 20, ");

  try{
    t3.remove(100);
  } catch (int e){
    CHECK(e == 1);
  }
  try{
    t3.remove(10);
  } catch (int e){
    CHECK(e == 1);
  }
  try{
    t3.remove(10);
  } catch (int e){
    CHECK(e == 1);
  }

  t3.remove(15);
  CHECK(t3.get_debug_string() == ", 5, , 8, , 20, ");
  t3.remove(5);
  CHECK(t3.get_debug_string() == ", 8, , 20, ");
  t3.remove(8);
  CHECK(t3.get_debug_string() == ", 20, ");
  // tree is just the root
  t3.remove(20);
  CHECK(t3.get_debug_string() == "");

}

TEST_CASE("Testing get_leaf_count()"){
  BSTree * t4 = new BSTree();
  CHECK(t4->get_leaf_count() == 0);
  t4->setup();
  /*
             10
           /    \
          5      20
        /  \    /   \
       3   8   15   30
  */
  CHECK(t4->get_leaf_count() == 4);
  t4->rinsert(100);
  CHECK(t->get_leaf_count() == 4);
  t4->rinsert(25);
  CHECK(t4->get_leaf_count() == 5);
  t4->rinsert(6);
  t4->rinsert(9);
  CHECK(t4->get_leaf_count() == 6);
  t4->remove(3);
  CHECK(t4->get_leaf_count() == 5);
  delete t4;
}

TEST_CASE("Testing get_height()"){
  BSTree * t5 = new BSTree();
  CHECK(t5->get_height() == -1);
  t5->setup();
  CHECK(t5->get_height() == 2);
  t5->rinsert(1);
  CHECK(t5->get_height() == 3);
  t5->rinsert(100);
  CHECK(t5->get_height() == 3);
  t5->rinsert(-1);
  CHECK(t5->get_height() == 4);
  t5->remove(100);
  CHECK(t5->get_height() == 4);
  t5->remove(-1);
  CHECK(t5->get_height() == 3);
  delete t5;
}

TEST_CASE("Testing get_level_sum"){
  BSTree * t6 = new BSTree();

  try{
    t6->get_level_sum(0);
  } catch (int e){
    CHECK(e == TREE_ERR_EMPTY);
  }
  t6->setup();

  /*
  0           10
            /    \
  1        5      20
         /  \    /   \
  2     3   8   15   30
  */

  try {
    t6->get_level_sum(3);
  } catch (int e){
    CHECK(e == TREE_ERR_LEVEL_DOESNT_EXIST);
  }

  try {
    t6->get_level_sum(-2);
  } catch(int e){
    CHECK(e == TREE_ERR_LEVEL_DOESNT_EXIST);
  }

  CHECK(t6->get_level_sum(0) == 10);
  CHECK(t6->get_level_sum(1) == 25);
  CHECK(t6->get_level_sum(2) == 56);
  t6->remove(3);
  CHECK(t6->get_level_sum(2) == 53);
  t6->rinsert(32);
  t6->rinsert(17);
  CHECK(t6->get_level_sum(3) == 49);
  t6->remove(20);
  CHECK(t6->get_level_sum(1) == 22);


}
