#include <iostream>

int stepsTable[10000];

int stepPerms(int n){
  if (n == 0){
    return 1;
  }
  else if (stepsTable[n] != 0){
    return stepsTable[n];
  }
  else{
    int r = 0;
    for (int i = 3; i > 0; i--){
      if (n-i >= 0) r += stepPerms(n-i);
    }
    stepsTable[n] = r;
    return r;
  }

}

int main(){
  for (int i = 0; i < 10000; i++){
    stepsTable[i] = 0;
  }
  std::cout << "First staircase: 1 step" << '\n';
  std::cout << "stepPerms(1): " << stepPerms(1) << '\n';
  std::cout << "Second staircase: 3 steps" << '\n';
  std::cout << "stepPerms(4): " << stepPerms(4) << '\n';
  std::cout << "Third staircase: 7 steps" << '\n';
  std::cout << "stepPerms(7): " << stepPerms(7) << '\n';
  std::cout << "Fourth staircase: 5 steps" << '\n';
  std::cout << "stepPerms(5): " << stepPerms(5) << '\n';

  return 0;
}
