#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}

int count(std::vector<int> v, int value){
  int result = 0;
  for (int i = 0; i < v.size(); i++){
    if (v[i] == value)
      result++;
  }
  return result;
}

int largest(std::vector<int> v){
    int max = v[0];
    for (int i = 1; i < v.size(); i++){
      if (v[i] > max) max = v[i];
    }

    return max;
}

int mode(std::vector<int> v){
  int max = largest(v);

  //count the number of times a number appears
  //index is the number
  std::vector<int> counter(max+1);

  for (int i = 0; i < v.size(); i++){
    counter[v[i]]++;
  }

  //finds the greatest number of times a number appears
  int most_occured = largest(counter);


  //if a number appears the greatest number of times,
  //return it as the mode

  for (int i = 0; i < v.size(); i++){
    if (count(v, v[i]) == most_occured){
      return v[i];
    }
  }
  return -1;
}

int main(){
  srand(time(NULL));
  int items = 25;
  int max = 5;

  std::vector<int> v;
  for (int i = 0; i < items; i++){
      v.push_back(rand()%max);
  }

  print_vector(v);

  std::cout << "\nlargest number: " << largest(v) << '\n';
  std::cout << "\nnumber of 0's: " << count(v, 0 ) << '\n';
  std::cout << "number of 1's: " << count(v, 1 ) << '\n';
  std::cout << "number of 2's: " << count(v, 2 ) << '\n';
  std::cout << "number of 3's: " << count(v, 3 ) << '\n';
  std::cout << "number of 4's: " << count(v, 4 ) << '\n';

  std::cout << "\nmode: " << mode(v) << '\n';

}
