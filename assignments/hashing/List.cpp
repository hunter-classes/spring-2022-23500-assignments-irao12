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

void List::insert(Person *p){
  //Create a new node
  Node *new_node = new Node(p);
  //Insert the new node
  new_node->setNext(head);
  head = new_node;
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
    s = s + " " + walker->getPerson()->get_name() + " |";
    walker = walker->getNext();
  }
  return s;
}

Node * List::get_head(){
  return head;
}
