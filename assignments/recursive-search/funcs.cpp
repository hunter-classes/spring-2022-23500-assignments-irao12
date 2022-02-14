#include <iostream>
#include <iomanip>
#include "funcs.h"
#include <unistd.h>

void initialize(int ** board, int size){
  for (int i = 0 ; i < size; i++){
    for (int j = 0; j < size; j++){
      board[i][j] = 0;
    }
  }
}

void print_board(int ** board, int size){
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      std::cout << std::setw(2) << board[i][j];
      std::cout << "|";
    }
    std::cout << '\n';
  }
}

bool is_complete(int ** board, int size){
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j ++){
      if (board[i][j] == 0) return false;
    }
  }
  return true;
}


void solve(int ** board, int size, int row, int col, int counter){

  if (row < 0 || col < 0 || row >= size || col >= size){
    return;
  }

  if (board[row][col] != 0){
    return;
  }

  if (is_complete(board, size)){
    return;
  }

  board[row][col] = counter;

  if (!is_complete(board,size)){
    print_board(board, size);
    std::cout << '\n';
  }
  
  if (!is_complete(board, size)) solve(board, size, row-2, col+1, counter+1);
  if (!is_complete(board, size)) solve(board, size, row-1, col+2, counter+1);
  if (!is_complete(board, size)) solve(board, size, row+1, col+2, counter+1);
  if (!is_complete(board, size)) solve(board, size, row+2, col+1, counter+1);
  if (!is_complete(board, size)) solve(board, size, row+2, col-1, counter+1);
  if (!is_complete(board, size)) solve(board, size, row-1, col-2, counter+1);
  if (!is_complete(board, size)) solve(board, size, row-1, col-2, counter+1);
  if (!is_complete(board, size)) solve(board, size, row-2, col-1, counter+1);

  if (!is_complete(board, size)) board[row][col] = 0;

  return;

}
