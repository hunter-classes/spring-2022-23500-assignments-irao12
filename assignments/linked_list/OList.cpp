#include <iostream>
#include "OList.h"
#include <climits>

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
  std::string result = "head --> ";
  Node * walker = head;
  while (walker != nullptr){
    result += std::to_string(walker->getData());
    result += " --> ";
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

int OList::get(int loc){
  Node *walker = head;
  while (loc > 0 && walker){
    walker = walker -> getNext();
    loc--;
  }
  if (walker != nullptr)
    return walker->getData();
  if (walker == nullptr){
    throw std::out_of_range("out of range");
  }
  //returns -2147483647 is there is no data at loc
  return INT_MAX*-1;
}

void OList::remove (int loc){
  Node *walker = head;
  Node *trailer = nullptr;

  while (loc > 0 && walker != nullptr){ //always check if the Node is equal to nullptr
    trailer = walker;
    walker = walker->getNext();
    loc = loc - 1;
  }
  //check to see if we're trying to insert beyond the end

  if (walker == nullptr){
    throw std::out_of_range("out of range");
  }

  if (trailer == nullptr){
    head = walker->getNext();
    delete walker;
  }
  else{
    trailer->setNext(walker->getNext());
    delete walker;
  }
}

void OList::reverse(){
    Node *prev = nullptr;
    Node *curr = head;
    Node *next;

    while (curr != nullptr){
      next = curr->getNext();
      curr->setNext(prev);
      prev = curr;
      curr = next;
    }

    head = prev;
    return;
}
