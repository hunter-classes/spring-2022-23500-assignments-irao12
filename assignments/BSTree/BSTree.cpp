#include "BSTree.h"
#include <iostream>

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int d){

}

std::string BSTree::get_debug_string_helper(Node * root){
  if (root == nullptr) return "";
  else{
    return get_debug_string_helper(root->getLeft()) + " " +
           get_debug_string_helper(root->getRight()) + " " +
           std::to_string(root->getData());
  }
}

std::string BSTree::get_debug_string(){
  return get_debug_string_helper(root);
}

void BSTree::setup(){
  Node * n = new Node (10);
  root = n;
  n = new Node(20);
  root->setLeft(n);
  n = new Node (30);
  root->setRight(n);

  n = new Node (40);
  root->getLeft()->setLeft(n);
}
