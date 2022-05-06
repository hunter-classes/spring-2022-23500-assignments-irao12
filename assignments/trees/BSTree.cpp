#include <iostream>
#include "Node.h"
#include "BSTree.h"
/*
 *
 BST - Binary Search Tree

 ordered tree where it's either empty or given a node N, all the
 values in N's left subtree are less than the value in N and all the
 values in N's right subtree are greater than the value in N.

*/
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


int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }

  }

  // if we get here then the value isn't
  // in the tree

  // normally, if we had a tree of objects
  // we could return null but since we only have
  // an int, we can't return an int to represent
  // not found so we'll throw an exception

  throw TREE_ERR_NO_VAL; // we should define our exceptions.

}

// we will always insert new nodes as leaves
void BSTree::insert(int value){

  // make a new node
  Node *newnode = new Node(value);

  // search for where the node would go as a leaf
  // that is, search until we get to null
  // we can use the piggyback strategy of having
  // a second pointer trail the lead pointer
  Node *p = root;
  Node *trailer;


  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;
    if (p->getData() == value){
      // do the stuff when the node is already in the tree
      return;
    }
    else if (p->getData() < value){
      p = p->getRight();
    } else {
      p = p->getLeft();
    }
  }

  // handle the special case of the tree
  // being empty (null)
  if (root==nullptr){
    root=newnode;
  } else {
    // trailer points to the node ABOVE where the new node
    // will go.
    // we have to figure out if newnode goes on the
    // left of trailer or on the right of trailer
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }

  }
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

void BSTree::delete_val(int value){
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

/* void BSTree::rdelete(int value, Node * parent, Node * curr){
  // will reach nullptr if the value is
  // not in the tree, throw exception
  if (curr == nullptr){
    throw 1;
  }
  // if the value is found, delete the node
  if (value == curr->getData()){
    Node * left = curr->getLeft();
    Node * right = curr->getRight();
    // if the node has at most one child
    if ((left && !right) || (!left && right) || (!left && !right)){
      // if the child is the right node
      if (!left){
        // if curr is the root, just set the root to right
        if (curr == root){
          delete curr;
          root = right;
        }
        // if curr was the parent's left node
        else if (curr->getData() < parent->getData()){
          parent->setLeft(right);
          delete curr;
        }
        // if curr was the parent's right node
        else {
          parent->setRight(right);
          delete curr;
        }
      }
      // if the child is the left node
      else {
        // if curr is the root, just set the root to left
        if (curr == root){
          delete curr;
          root = left;
        }
        // if curr was the parent's left node
        else if (curr->getData() < parent->getData()){
          parent->setLeft(left);
          delete curr;
        }
        // if curr was the parent's right node
        else {
          parent->setRight(left);
          delete left;
        }
      }
    }
    //if the node has two chidlren
    else{
      Node * temp = curr->getLeft();
      Node * temp_parent = curr;
      //find the largest element in the left subtree
      while (temp->getRight() != nullptr){
        temp_parent = temp;
        temp = temp->getRight();
      }
      //change curr's data to the largest value in the left subtree
      curr->setData(temp->getData());
      // delete the node that holds the copied value
      rdelete(temp->getData(), temp_parent, temp);
    }
  }
  // if value is less than the current node's data
  // delete the value in the left subtree
  else if (value < curr->getData()){
    rdelete(value, curr, curr->getLeft());
  }
  // if value is greater than the current node's data
  // delete the value in the right subtree
  else{
    rdelete(value, curr, curr->getRight());
  }
}

void BSTree::rdelete(int value){
    rdelete(value, nullptr, root);
}
*/
