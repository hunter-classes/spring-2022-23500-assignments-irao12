#include <iostream>
#include "Heap.h"

void make_heap(int data[], int curr, int length){
  int left = 2 * curr + 1;
  int right = 2 * curr + 2;
  int most = curr;

  // if left child exists, and data[left] is largest, swap
  if (left < length && data[left] > data[most]){
    most = left;
  }
  // if right child exists, and data[right]] is largest, swap
  if (right < length && data[right] > data[most]){
    most = right;
  }

  if (most != curr){
    // swap the larger value with curr's value if curr is
    // not the largest
    int temp = data[curr];
    data[curr] = data[most];
    data[most] = temp;
    // if swapped with a different value, make sure
    // the swapped side still follows the heap property
    make_heap(data, most, length);
  }
}

void make_heap(int data[], int length){
  // all the values from 0 to (length-1)/2 are parents
  // if last value is at index n, the last parent is (n-1)/2
  // we do not need to check the non-parents
  if (length < 1) throw HEAP_ERR_EMPTY;
  for (int i = (length-1)/2; i >=0; i--){
    // sift up from the bottom
    make_heap(data, i, length);
  }
}

void heap_sort(int data[], int length){
  // keep track of the last element that has not been
  // processed
  if (length < 1) throw HEAP_ERR_EMPTY;

  int last = length -1;

  // while the whole array has not been processed
  while (last > 0){
    // swap the last and first (max) element
    int temp = data[last];
    data[last] = data[0];
    data[0] = temp;
    // decrement last so we do not change it
    last--;
    // preserve the heap property from 0 to last
    make_heap(data, 0, last+1);
  }
}
