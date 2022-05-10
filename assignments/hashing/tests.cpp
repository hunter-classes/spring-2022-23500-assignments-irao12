#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "Dictionary.h"

Dictionary *dict = new Dictionary();
Person * p0 = new Person("Ivan", "Rao", 0);
Person * p1 = new Person("James", "Bond", 1);
Person * p2 = new Person("Abraham", "Lincoln", 2);
Person * p3 = new Person("John", "Cena", 3);
Person * p4 = new Person("Lebron", "James", 4);
Person * p5 = new Person("George", "Washington", 5);

TEST_CASE("Testing hash_func"){
  CHECK(dict->hash_func("test") == 3);
  CHECK(dict->hash_func("Cena, John") == 0);
  CHECK(dict->hash_func("Bond, James") == 4);
  CHECK(dict->hash_func("Lincoln, Abraham") == 4);
  CHECK(dict->hash_func("Rao, Ivan") == 4);
  CHECK(dict->hash_func("James, Lebron") == 2);
  CHECK(dict->hash_func("Washington, George") == 0);
  CHECK(dict->hash_func("Jordan, Michael") == 3);
  CHECK(dict->hash_func("the last test") == 4);
}

TEST_CASE("Testing insert and get_names"){
  CHECK(dict->get_names() == "|");
  dict->insert(p0);
  CHECK(dict->get_names() == "| Rao, Ivan |");
  dict->insert(p1);
  dict->insert(p2);
  CHECK(dict->get_names() == "| Lincoln, Abraham | Bond, James | Rao, Ivan |");
  dict->insert(p3);
  CHECK(dict->get_names() == "| Cena, John | Lincoln, Abraham | Bond, James | Rao, Ivan |");
  dict->insert(p4);
  CHECK(dict->get_names() == "| Cena, John | James, Lebron | Lincoln, Abraham | Bond, James | Rao, Ivan |");
  dict->insert(p5);
  CHECK(dict->get_names() == "| Washington, George | Cena, John | James, Lebron | Lincoln, Abraham | Bond, James | Rao, Ivan |");
  dict->insert(new Person("Michael", "Jordan", 6));
  CHECK(dict->get_names() == "| Washington, George | Cena, John | James, Lebron | Jordan, Michael | Lincoln, Abraham | Bond, James | Rao, Ivan |");
}

TEST_CASE("Testing retrieve"){
    Person * p = dict->retrieve("Ross, Bob");
    CHECK(p == nullptr);
    p = dict->retrieve("Rao, Ivan");
    CHECK(p == p0);
    p = dict->retrieve("Cena, John");
    CHECK(p == p3);
    p = dict->retrieve("Khan, Genghis");
    CHECK(p == nullptr);
    p = dict->retrieve("Lincoln, Abraham");
    CHECK(p == p2);
    p = dict->retrieve("Washington, George");
    CHECK(p == p5);
}
