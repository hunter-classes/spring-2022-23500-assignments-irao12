#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Heap.h"

// array of size 0
int test0[] = {};
// array of size 1
int test1[] = {240};
// larger array (sorted)
int test2[] = {1, 2, 3, 4, 5};
// larger array (random)
int test3[] = {13, 54, 2, 70, 86, 1, 37, 99};
// larger array with negatives
int test4[] = {32, -23, 0, -78, 123, 62, -41};


TEST_CASE("Testing make_heap"){

  // test0: array of size 0;
  try{
    make_heap(test0, 0);
  } catch (int e){
    CHECK(e == HEAP_ERR_EMPTY);
  }

  // test1: array of size 1;
  make_heap(test1, 1);
  CHECK(test1[0] == 240);

  // test2: larger array (sorted)
  make_heap(test2, 5);
  int test2_res[] = {5, 4, 3, 1, 2};
  for (int i = 0; i < 5; i++){
    CHECK(test2[i] == test2_res[i]);
  }

  // test3: larger array (random)
  make_heap(test3, 8);
  int test3_res[] = {99, 86, 37, 70, 13, 1, 2, 54};
  for (int i = 0; i < 8; i++){
    CHECK(test3[i] == test3_res[i]);
  }

  // test4: larger array with negatives
  make_heap(test4, 7);
  int test4_res[] = {123, 32, 62, -78, -23, 0, -41};
  for (int i = 0; i < 7; i++){
    CHECK(test4[i] == test4_res[i]);
  }
}

TEST_CASE("Testing heap_sort"){
  // test0: array of size 0
  try {
    heap_sort(test0, 0);
  } catch (int e){
    CHECK(e == HEAP_ERR_EMPTY);
  }

  // test1: array of size 1
  heap_sort(test1, 1);
  CHECK(test1[0] == 240);

  // test2: larger array (sorted)
  heap_sort(test2, 5);
  int test2_res[] = {1, 2, 3, 4, 5};
  for (int i = 0; i < 5; i++){
    CHECK(test2[i] == test2_res[i]);
  }
  // test3: larger array (random)
  heap_sort(test3, 8);
  int test3_res[] = {1, 2, 13, 37, 54, 70, 86, 99};
  for (int i = 0; i < 8; i++){
    CHECK(test3[i] == test3_res[i]);
  }
  // test4: larger array with negatives
  heap_sort(test4, 7);
  int test4_res[] = {-78, -41, -23, 0, 32, 62, 123};
  for (int i = 0; i < 7; i++){
    CHECK(test4[i] == test4_res[i]);
  }
}
