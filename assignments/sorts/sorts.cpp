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

  std::vector<int> left, right;
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

std::vector<int> bad_qsort1(std::vector<int> list){

  int i,j;

  // base case
  if (list.size() <= 1){
    return list;
  }

  // select a pivot value.
  // for now, just pick list[0]
  int pivot = list[0];

  // make 2 new vectors
  std::vector<int> lower,higher;

  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  for (i=1; i < list.size(); i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  lower = bad_qsort1(lower);
  higher = bad_qsort1(higher);

  // copy everything back into list
  for (i=0 ; i < lower.size(); i++){
    list[i]=lower[i];
  }

  list[i] = pivot;
  i++;

  for (j=0;j<higher.size();j++){
    list[i] = higher[j];
    i++;
  }

  // return the sorted list

  return list;
}

std::vector<int> good_qsort1(std::vector<int> list){

  int i,j;

  // base case
  if (list.size() <= 1){
    return list;
  }

  // select a pivot value.
  // for now, just pick list[0]
  int pivot;
  int first = list[0];
  int last = list[list.size()-1];
  int mid = list[list.size()/2];
  if ((first>=mid && mid>=last) || (last>=mid && mid>=first)) pivot = mid;
  if ((mid >= first && first >= last) || (last >= first && first >= mid)) pivot = first;
  if ((last >= first && last <= mid) || (last >= mid && last <= first)) pivot = last;

  // make 2 new vectors
  std::vector<int> lower,higher;

  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  for (i=1; i < list.size(); i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }

  lower = good_qsort1(lower);
  higher = good_qsort1(higher);

  // copy everything back into list
  for (i=0 ; i < lower.size(); i++){
    list[i]=lower[i];
  }

  list[i] = pivot;
  i++;

  for (j=0;j<higher.size();j++){
    list[i] = higher[j];
    i++;
  }

  // return the sorted list
  return list;
}

void swap(std::vector<int> *list, int a, int b){
  int temp = (*list)[a];
  (*list)[a] = (*list)[b];
  (*list)[b] = temp;
  return;
}

void bad_qsort2(std::vector<int> *list, int L, int H){
  if (L>=H) return;


  int pivot = (*list)[L];
  int i = L;
  int j = H;

  //stop when i and j are both on pivot
  while (i <= j){
    //goes from L to the pivot until an element is >= the pivot
    while ((*list)[i] < pivot){
      i++;
    }
    //goes from the end to pivot until an element is <= the pivot
    while ((*list)[j] > pivot){
      j--;
    }
    if (i <= j){
    swap(list, i, j);
      i++;
      j--;
    }
  }

  bad_qsort2(list, L, j);
  bad_qsort2(list, i, H);
}

void good_qsort2(std::vector<int> *list, int L, int H){
  if (L>=H) return;

  int i = L;
  int j = H;

  int pivot;
  int first = (*list)[L];
  int last = (*list)[H];
  int mid = (*list)[(H-L)/2+L];
  if (first>mid){
    if (first<last)
      pivot = first;
    else if (mid>last)
      pivot = mid;
    else
      pivot = last;
  }
  else{
    if (last > mid)
      pivot = mid;
    else if (first > last)
      pivot = first;
    else
      pivot = last;
  }

  //stop when i and j are both on pivot
  while (i <= j){
    //goes from L to the pivot until an element is >= the pivot
    while ((*list)[i] < pivot){
      i++;
    }
    //goes from the end to pivot until an element is <= the pivot
    while ((*list)[j] > pivot){
      j--;
    }
    if (i <= j){
    swap(list, i, j);
      i++;
      j--;
    }
  }

  good_qsort2(list, L, j);
  good_qsort2(list, i, H);
}

void test(std::string sort, std::vector<int> *list){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  if (sort == "msort")
    msort(*list);
  else if (sort == "bad_qsort2")
    bad_qsort2(list, 0 , (*list).size()-1);
  else if (sort == "good_qsort2")
    good_qsort2(list, 0 , (*list).size()-1);
  else if (sort == "good_qsort1")
    good_qsort1(*list);
  else if (sort == "bad_qsort1")
    bad_qsort1(*list);

  gettimeofday(&tp,NULL);
  long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  long elapsed = current_time - start_time;
  std::cout << "\tTime: " << elapsed << '\n';
}

int main()
{
  /*
  std::cout << "Example 1: " << '\n';
  std::cout << "Before sorting with merge sort: " << '\n';
  std::vector<int> v = {23, 3, 11, 21, 0, 54, 65, -2};
  print_vector(v);
  v = msort(v);
  std::cout << "After sorting with merge sort: " << '\n';
  print_vector(v);

  std::cout << "\nExample 2: " << '\n';
  std::cout << "Before sorting with merge sort: " << '\n';
  v = {64, 32, 70, 2, 53, -223, -2, -50};
  print_vector(v);
  v = msort(v);
  std::cout << "After sorting with merge sort: " << '\n';
  print_vector(v);
  */
  //Generating a random vector of ints
  int max = 1000;
  int size = 15000;
  std::vector<int> list1, list2, list3, list4;

  srand(time(NULL));
  for (int i = 0 ; i < size; i++){
    int random = rand() % max;
    list1.push_back(random);
    list2.push_back(random);
    list3.push_back(i);
    list4.push_back(i);
  }

  std::cout << "Testing on randomized vectors" << '\n';

  std::cout << "Starting mergesort on a vector of size " << size << '\n';

  test("msort", &list1);

  std::cout << "Starting bad original quicksort on a vector of size " << size << '\n';

  test("bad_qsort1", &list1);

  std::cout << "Starting good original quicksort on a vector of size " << size << '\n';

  test("good_qsort1", &list1);

  std::cout << "Starting bad in-place quicksort on a vector of size " << size << '\n';

  test("bad_qsort2", &list1);

  std::cout << "Starting good in-place quicksort on a vector of size " << size << '\n';

  test("good_qsort2", &list2);

  std::cout << "\nTesting on sorted vectors" << '\n';

  std::cout << "Starting mergesort on a sorted vector of size " << size << '\n';

  test("msort", &list3);

  std::cout << "Starting bad original quicksort on a sorted vector of size " << size << '\n';

  test("bad_qsort1", &list3);


  std::cout << "Starting good original quicksort on a sorted vector of size " << size << '\n';

  test("good_qsort1", &list3);

  std::cout << "Starting bad in-place quicksort on a sorted vector of size " << size << '\n';

  test("bad_qsort2" , &list3);

  std::cout << "Starting good in-place quicksort on a sorted vector of size " << size << '\n';

  test("good_qsort2", &list4);





  return 0;
}
