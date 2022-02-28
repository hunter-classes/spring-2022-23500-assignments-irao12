#include <iostream>
#include "OList.h"

OList::OList(){
  head = nullptr;
}
//~OList();

void OList::insert(int value){
  Node *walker = head;
  Node *trailer = nullptr;
  Node *temp = new Node(value);

  while (walker != nullptr && value > walker->getData()){
    trailer = walker;
    walker = walker->getNext();
  }

  if (trailer == nullptr){
    temp->setNext(head);
    head = temp;
  }
  else{
    trailer->setNext(temp);
    temp->setNext(walker);
  }
  return;
}


std::string OList::toString(){
  std::string result = "";
  Node * walker = head;
  while (walker != nullptr){
    result += std::to_string(walker->getData());
    result += "-->";
    walker = walker->getNext();
  }
  result+="nullptr";
  return result;
}

//bool contains(int value);

//int get(int loc);

//void remove (int loc);

//void reverse();
