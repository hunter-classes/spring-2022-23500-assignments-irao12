#include <iostream>
#include "funcs.h"

const int SIZE = 5;

int main(){
  int ** board = new int * [SIZE];
  for (int i = 0; i < SIZE; i++){
    board[i] = new int [SIZE];
  }
  initialize(board, SIZE);

  std::cout << "Initial Empty Board" << '\n';
  print_board(board, SIZE);
  std::cout << '\n';
  std::cout << "After solving:" << '\n';
  solve(board, SIZE, 0, 0, 1);
  print_board(board, SIZE);


  return 0;
}
