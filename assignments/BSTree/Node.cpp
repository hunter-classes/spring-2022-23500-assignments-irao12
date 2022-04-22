#include "Node.h"
/*
  int getData();
  Node * getLeft();
  Node * getRight();

  void setData(int d);
  void setLeft(Node *l);
  void setRight(Node *r);

};
*/

Node::Node(){
  left = nullptr;
  right = nullptr;
  data = 0;
}

Node::Node(int data){
  this->data = data;
  left = nullptr;
  right = nullptr;
}

Node::Node(int data, Node * left, Node * right){
  this->data = data;
  this->left = left;
  this->right = right;
}

int Node::getData(){
  return data;
}

Node * Node::getLeft(){
  return left;
}

Node * Node::getRight(){
  return right;
}

void Node::setData(int d){
  data = d;
}

void Node::setLeft(Node *l){
  left = l;
}

void Node::setRight(Node *r){
  right = r;
}
