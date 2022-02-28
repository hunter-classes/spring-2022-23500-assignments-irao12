#include <iostream>
#include "OList.h"

OList::OList(){
  head = nullptr;
}

OList::~OList(){
  Node * trailer = nullptr;
  while (head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void OList::insert(int value){
  //while walker refers to index n, trailer refers to index n-1
  Node *walker = head;
  Node *trailer = nullptr;
  Node *temp = new Node(value);

  //walker must not be nullptr and value must be greater
  while (walker != nullptr && value > walker->getData()){
    trailer = walker;
    walker = walker->getNext();
  }

  //inserting at index 0
  if (trailer == nullptr){
    temp->setNext(head);
    head = temp;
  }
  //inserting elsewhere
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

bool OList::contains(int value){
  Node *walker = head;
  //skip Nodes until walker has data >= value
  while (walker != nullptr && walker->getData() < value){
    walker = walker->getNext();
  }

  if (walker == nullptr || walker->getData() > value){
    return false;
  }
  return true;
}

//int get(int loc);

//void remove (int loc);

//void reverse();
