#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "OList.h"


TEST_CASE("Testing constructor, insert, and toString"){
  OList * list = new OList();
  CHECK(list->toString() == "nullptr");
  list->insert(10);
  CHECK(list->toString() == "10-->nullptr");
  list->insert(12);
  CHECK(list->toString() == "10-->12-->nullptr");
  list->insert(5);
  CHECK(list->toString() == "5-->10-->12-->nullptr");
  list->insert(-11);
  CHECK(list->toString() == "-11-->5-->10-->12-->nullptr");
  list->insert(7);
  CHECK(list->toString() == "-11-->5-->7-->10-->12-->nullptr");
  delete list;
}

TEST_CASE("testing contains"){
  OList * list = new OList();
  //testing on an empty list
  CHECK(!list->contains(5)); //false
  list->insert(10);
  list->insert(12);
  list->insert(5);
  CHECK(list->contains(10));
  CHECK(list->contains(12));
  CHECK(list->contains(5));
  //not yet inserted
  CHECK(!list->contains(4));
  list->insert(4);
  CHECK(list->contains(4));
  delete list;
}

TEST_CASE("testing get"){
  OList * list = new OList();
  list->insert(10);
  list->insert(12);
  list->insert(5);
  list->insert(4);
  list->insert(7);
  CHECK(list->get(0)==4);
  CHECK(list->get(1)==5);
  CHECK(list->get(2)==7);
  CHECK(list->get(3)==10);
  CHECK(list->get(4)==12);
  delete list;
}

TEST_CASE("testing remove"){
  OList *list = new OList();
  list->insert(10);
  list->insert(12);
  list->insert(5);
  list->insert(-11);
  list->insert(7);
  CHECK(list->toString() == "-11-->5-->7-->10-->12-->nullptr");
  list->remove(2);
  CHECK(list->toString() == "-11-->5-->10-->12-->nullptr");
  list->remove(3);
  CHECK(list->toString() == "-11-->5-->10-->nullptr");
  list->remove(0);
  CHECK(list->toString() == "5-->10-->nullptr");
}
