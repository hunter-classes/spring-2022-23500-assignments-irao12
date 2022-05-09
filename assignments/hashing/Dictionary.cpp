#include <iostream>
#include "Dictionary.h"
#include "List.h"

Dictionary::Dictionary(){
  table = new List*[10];
  for (int i =0; i < 10; i++){
    table[i] = new List();
  }
}

Dictionary::~Dictionary(){
  for (int i = 0; i < 10; i++){
    delete table[i];
  }
}

/*void Dictionary::insert(Person *p){

}

std::string Dictionary::get_names(){


*/
