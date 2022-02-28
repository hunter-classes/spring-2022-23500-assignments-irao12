#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "OList.h"

OList * list = new OList();
TEST_CASE("Testing constructor, insert, and toString"){
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
}
