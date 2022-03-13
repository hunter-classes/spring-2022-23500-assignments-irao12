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

int mode1(std::vector<int> v){
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

int mode2(std::vector<int> v){
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
    if (counter[v[i]] == most_occured){
      return v[i];
    }
  }
  return -1;
}

int main(){
  srand(time(NULL));
  int items = 50;
  int max = 10;

  std::vector<int> v;
  for (int i = 0; i < items; i++){
      v.push_back(rand()%max);
  }

  print_vector(v);

  std::cout << "\nlargest number: " << largest(v) << "\n\n";

  for (int i = 0; i < max; i++){
    std::cout << "number of "<< i<< "\'s: " << count(v, i) << '\n';
  }

  std::cout << "\nmode using mode1: " << mode1(v) << '\n';
  std::cout << "mode using mode2: " << mode2(v) << '\n';

}
