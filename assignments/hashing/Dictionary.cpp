#include <iostream>
#include "Dictionary.h"
#include "List.h"

Dictionary::Dictionary(){
  table = new List*[5];
  for (int i =0; i < 5; i++){
    table[i] = new List();
  }
}

Dictionary::~Dictionary(){
  for (int i = 0; i < 5; i++){
    delete table[i];
  }
}

// hash function was made bad on purpose for testing
int Dictionary::hash_func(std::string key){
  int sum = 0;
  for (int i = 0; i < key.length(); i++)
    sum += (int) key[i];
  return sum % 5;
}


void Dictionary::insert(Person *p){

  std::string name = p->get_name();
  int index = hash_func(name);
  table[index]->insert(p);

}


Person * Dictionary::retrieve(std::string name){
  Person * result = nullptr;

  // Find what the index of the Person would have been if in the table
  int index = hash_func(name);
  List * l = table[index];
  Node * curr = l->get_head();

  // look at each Person in the list
  while (curr){
    if (name == curr->getPerson()->get_name()){
      result = curr->getPerson();
      break;
    }
    curr = curr->getNext();
  }

  return result;
}


std::string Dictionary::get_names(){
  std::string result = "|";

  for (int i = 0; i < 5; i++){
    List * l = table[i];
    result += l->toString();
  }

  return result;
}
