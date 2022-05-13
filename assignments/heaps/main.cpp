#include <iostream>
#include "Heap.h"

int main(){

  int data[10] = {7, 49, 73, 58, 130, 32, 144, 78, 123, 109};

  std::cout << "Original array: " << '\n';
  for (int i = 0; i < 10; i++){
    std::cout << data[i] << ' ';
  }
  std::cout << '\n';

  make_heap(data, 10);
  std::cout << "\nAfter turning the array into a max heap: " << '\n';
  for (int i = 0; i < 10; i++){
    std::cout << data[i] << ' ';
  }
  std::cout << '\n';

  heap_sort(data, 10);
  std::cout << "\nThe array after heap_sort():" << '\n';
  for (int i = 0; i < 10; i++){
    std::cout << data[i] << ' ';
  }
  std::cout << '\n';
}
