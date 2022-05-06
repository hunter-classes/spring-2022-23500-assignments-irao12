#include <iostream>
#include "Node.h"
#include "BSTree.h"
#include <stdio.h>
#include <ctime>

int main()
{
  std::cout << "Creating a binary tree using setup" << '\n';
  BSTree *t = new BSTree();
  t->setup();
  std::cout << "Tree: " << t->get_debug_string() << '\n';

  std::cout << "Searching using rsearch" << '\n';

  int v = 15;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
  }

  v = 23;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
  }

  v = 30;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
  }

  v = 0;
  try {
    int x  = t->rsearch(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
  }

  std::cout << "\nNumber of leaves: " << t->get_leaf_count()<< '\n';
  std::cout << "Height of the tree: " << t->get_height() << '\n';

  std::cout << "\nDeleting values in the tree" << '\n';
  std::cout << "Deleting 10" << '\n';
  t->delete_val(10);
  std::cout << t->get_debug_string() << '\n';
  std::cout << "Deleting 15" << '\n';
  t->delete_val(15);
  std::cout << t->get_debug_string() << '\n';
  std::cout << "Deleting 8" << '\n';
  t->delete_val(8);
  std::cout << t->get_debug_string() << '\n';
  std::cout << "Deleting 5" << '\n';
  t->delete_val(5);
  std::cout << t->get_debug_string() << '\n';
  std::cout << "Deleting 100" << '\n';
  try{
    t->delete_val(100);
  } catch (int e){
    std::cout << "\tTried to delete a value that was not in the tree" << '\n';
  }
  std::cout << t->get_debug_string() << '\n';

  std::cout << "\nCreating a binary search tree of random values using rinsert" << '\n';


  BSTree *random_t = new BSTree();

  srand(time(NULL));
  for (int i = 0; i < 8; i++){
    int random = rand()%100;
    random_t->rinsert(random);
  }

  std::cout <<  "Tree: " << random_t->get_debug_string() << "\n";



  return 0;
}
