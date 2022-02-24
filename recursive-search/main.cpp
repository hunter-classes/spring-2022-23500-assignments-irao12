#include <iostream>
#include "funcs.h"

const int SIZE = 5;

int main(){
  int ** board = new int * [SIZE];
  for (int i = 0; i < SIZE; i++){
    board[i] = new int [SIZE];
  }
  initialize(board, SIZE);

  std::cout << "A solution with the knight starting at the top left corner" << '\n';
  solve(board, SIZE, 0, 0, 1);
  print_board(board, SIZE);

  initialize(board, SIZE);
  std::cout << "A solution with the knight starting at the bottom right corner" << '\n';
  solve(board, SIZE, 4, 4, 1);
  print_board(board, SIZE);
  return 0;
}
