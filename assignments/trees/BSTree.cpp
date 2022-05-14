#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
  std::string a,b,c;

  if (n==nullptr){
    return "";
  }
  else {
    a =  traverse(n->getLeft());
    b = std::to_string(n->getData());
    c =  traverse(n->getRight());

    return a + ", " + b+ ", " + c;
  }
};

std::string BSTree::get_debug_string(){
  return traverse(root);
};

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);

}

int BSTree::rsearch(int value, Node *p){
  //If we ever reach nullptr, throw an exception
  if (p == nullptr){
    throw TREE_ERR_NO_VAL;
  }

  int data = p->getData();
  //if the value is equal to the node's data, return data
  if (value == data){
    return data;
  }
  //search the left subtree if the value is less the current node's data
  else if (value < data){
    return rsearch(value, p->getLeft());
  }
  //search the right subtree if the value is greater the current node's data
  else {
    return rsearch(value, p->getRight());
  }

}

int BSTree::rsearch(int value){
  return rsearch(value, root);
}

void BSTree::rinsert(int value, Node *p){
  if (root == nullptr){
    root = new Node (value);
    return;
  }
  int data = p->getData();

  if (value == data){
    return;
  }
  else if (value < data){
    if (p->getLeft() == nullptr){
      p->setLeft(new Node(value));
    }
    else{
      rinsert(value, p->getLeft());
    }
  }
  else {
    if (p->getRight() == nullptr){
      p->setRight(new Node (value));
    }
    else{
      rinsert(value, p->getRight());
    }
  }
}

void BSTree::rinsert(int value){
  rinsert(value, root);
}

void BSTree::remove(int value){
  Node * curr = root;
  // parent keeps track of the parent node of curr
  Node * parent = nullptr;
  // found is true if the value exists in the tree
  bool found = false;

  while (curr){
    int x = curr->getData();
    // if value is less than curr's data, move to the left subtree
    if (value < x){
      parent = curr;
      curr = curr->getLeft();
    }
    // if value is less than curr's data, move to the left subtree
    else if (value > x){
      parent = curr;
      curr = curr->getRight();
    }
    // if value is equal to curr's data, delete curr
    else{
      Node * left = curr->getLeft();
      Node * right = curr->getRight();

      //if curr has at most one child
      if ( (!left && right) || (left && !right) || (!left && !right)){
        if (!left){
          if (curr == root){
            root = right;
          }
          else if (x > parent->getData()){
            parent->setRight(right);
          }
          else if (x < parent->getData()){
            parent->setLeft(right);
          }
        }
        else{
          if (curr == root){
            root = left;
          }
          else if (x > parent->getData()){
            parent->setRight(left);
          }
          else if (x < parent->getData()){
            parent->setLeft(left);
          }
        }
        delete curr;
      }
      // curr has two children nodes
      else{
        Node * temp_parent, * temp;
        temp_parent = curr;
        temp = curr->getLeft();
        // if the left subtree is a linked-list, just shift the list to curr
        if (!temp->getRight()){
          curr->setData(temp->getData());
          curr->setLeft(temp->getLeft());
        }
        else{
          //reach the node with the largest value in the left subtree
          while (temp->getRight()){
            temp_parent = temp;
            temp = temp->getRight();
          }

          curr->setData(temp->getData());
          delete temp;
          temp_parent -> setRight(nullptr);
        }
      }
      found = true;
      break;
    }
  }
  // if the value is not in the tree, throw an exception
  if (!found) throw TREE_ERR_NO_VAL;
}

int BSTree::get_leaf_count(Node * n){
  if (n == nullptr){
    return 0;
  }
  else if (!n->getLeft() && !n->getRight()){
    return 1;
  }
  return get_leaf_count(n->getLeft()) + get_leaf_count(n->getRight());
}

int BSTree::get_leaf_count(){
  return get_leaf_count(root);
}

int BSTree::get_height(Node * n){
  // the root is height 0
  if (n == nullptr){
    return -1;
  }
  int left_height = get_height(n->getLeft());
  int right_height = get_height(n->getRight());

  //the height of the tree is the height of the larger subtree + 1
  if (left_height < right_height){
    return right_height + 1;
  }
  return left_height + 1;
}

int BSTree::get_height(){
  return get_height(root);
}

int BSTree::get_level_sum(Node *n, int curr, int level){
  if (n == nullptr) return 0;
  if (curr == level){
    return n->getData();
  }
  return get_level_sum(n->getLeft(), curr+1, level)
         + get_level_sum(n->getRight(), curr+1, level);
}

int BSTree::get_level_sum(int level){
  // 0 -> root's level
  if (root == nullptr){
    throw TREE_ERR_EMPTY;
  }
  if (level < 0){
    throw TREE_ERR_LEVEL_DOESNT_EXIST;
  }
  if (get_height() < level){
    throw TREE_ERR_LEVEL_DOESNT_EXIST;
  }
  return get_level_sum(root, 0, level);
}
