#include <iostream>
#include "List.h"

List::List(){
  head = nullptr;
}

List::~List(){
  Node * walker = head;
  while (walker != nullptr){
    Node * current = walker;
    walker = walker->getNext();
    delete current;
  }
  head = nullptr;
}

void List::insert(std::string data){
  //Create a new node
  Node *new_node = new Node(data);

  //Insert the new node
  new_node->setNext(head);
  head = new_node;
}

void List::insert(std::string data, int index){
  Node * new_node = new Node(data);
  Node * walker = head;
  int counter = 0;
  while (walker != nullptr && counter < index-1){
    walker = walker->getNext();
    counter++;
  }
  Node * temp = walker -> getNext();
  walker->setNext(new_node);
  new_node->setNext(temp);
  return;
}

Node * List::locate(int index){
  int counter = 0;
  Node *walker = head;
  while(walker != nullptr && counter < index){
    walker = walker->getNext();
    counter++;
  }
  return walker;
}

void List::remove(int index){
  Node * walker = head;
  int counter = 0;
  while (counter < index-1){
    walker = walker->getNext();
    counter++;
  }
  Node * removing = walker->getNext();
  walker->setNext(removing->getNext());
  delete removing;

  return;
}

std::string List::toString(){
  if (head == nullptr){
    return "";
  }

  Node *walker = head;
  std::string s = "";
  while (walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();
  }
  s = s + "nullptr";
  return s;
}
