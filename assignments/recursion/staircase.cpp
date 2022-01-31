#include <iostream>

int stepPerms(int n){
  if (n == 0){
    return 1;
  }
  else if (n >= 3){
    return stepPerms(n-3) + stepPerms(n-2) + stepPerms(n-1);
  }
  else if (n >= 2){
    return stepPerms(n-2) + stepPerms(n-1);
  }
  else{
    return stepPerms(n-1);
  }
}

int main(){
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
