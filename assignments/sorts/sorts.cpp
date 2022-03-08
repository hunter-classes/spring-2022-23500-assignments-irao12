#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a,
		   int start_index,
		   int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);

    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;

  }
  return a;
}

/*
  left and right are already sorted
  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left,
		       std::vector<int> right){
  std::vector<int> merged;

  // your code here
  int l = 0;
  int r = 0;

  while (l < left.size() &&
	 r < right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  // add any extra elements in left
  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }


  // add any extra elements in right
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }


  return merged;


}

std::vector<int> msort(std::vector<int> v){

  //base case: if the vector has one or less element
  if (v.size() < 2) return v;

  int len = v.size();

  //splitting the vector into two
  //first vector has elements from 0 to len/2-1
  //second vector has elements from len/2-1 to len-1

  std::vector<int>left, right;
  for (int i = 0; i < len; i++){
    if (i < len/2)
      left.push_back(v[i]);
    else
      right.push_back(v[i]);
  }

  //recursive case: sort the two vectors
  left = msort(left);
  right = msort(right);

  //merge the sorted vectors
  return merge(left, right);
}


int main()
{
  std::cout << "Before sorting with merge sort: " << '\n';
  std::vector<int> v = {23, 3, 11, 21, 0, 54, 65, -2};
  print_vector(v);
  v = msort(v);
  std::cout << "After sorting with merge sort: " << '\n';
  print_vector(v);
  return 0;
}
