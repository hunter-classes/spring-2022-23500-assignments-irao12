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
  int max_frequency = -1;
  int mode = v[0];
  for (int i = 0; i < v.size(); i++){
    int current_frequency = count(v, v[i]);
    if (current_frequency > max_frequency){
      mode = v[i];
      max_frequency = current_frequency;
    }
  }
  return mode;
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
