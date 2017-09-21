/*
Author: Russell Chai
This program is a two user game for tic tac toe
*/
#include <iostream>

using namespace std;

char board[3][3];//tictactoe board
int counter = 0;//number if pieces set down
int XWins = 0;//number of times x was placed
int YWins = 0;//number of times y was placed

//print board
void printBoard() {
  //print column labels
  cout << "\t" << "1" << "\t" << "2" << "\t" << "3" << endl;
  char line;
  for (int a = 0; a < 3; a++) {
    line = a + 'a';
    //print row label
    cout << line;
    for (int b = 0; b < 3; b++) {
      cout << "\t" << board[a][b];
    }
    cout << endl;
  }
}
//clear board
void resetBoard() {
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      board[a][b] = ' ';
    }
  }
}
//check if a player won
bool checkWin(char player) {
  //check by row
  for (int a = 0; a < 3; a++) {
    int count = 0;
    for (int b = 0; b < 3; b++) {
      if (board[a][b] == player) {
	count++;
      }
    }
    if (count == 3) {
      return true;
    }
  }
  //check by column
  for (int b = 0; b < 3; b++) {
    int count = 0;
    for (int a = 0; a < 3; a++) {
      if (board[a][b] == player) {
	count++;
      }
    }
    if (count == 3) {
      return true;
    }
  }
  //check diagonal
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[2][0] == player && board[1][1] == player && board[0][2] == player) {
    return true;
  }
  return false;
}
int main() {
  while(true) {
   cout << "Enter move by row, column (ex. a1)" << endl;
   resetBoard();
   printBoard();
   while(true) {
     //get input
    char input[2];
    cin >> input;
    int x = input[0] - 'a';
    int y = input[1] - '1';
    //check if theres already a piece there
    if (board[x][y] == ' ') {
      //check which player's turn
      if (counter % 2 == 0) {
	board[x][y] = 'X';
	if (checkWin('X')) { //if player X won...
	  XWins++;
	  printBoard();
	  cout << "X Wins" << endl;
	  cout << "games won" << endl;
	  cout << "x: " << XWins << " games" << endl;
	  cout << "y: " << YWins << " games" << endl;
	  resetBoard();
	  break;
	}
      }
      else {
	board[x][y] = 'O';
	if (checkWin('O')) {//if player O won...
	  YWins++;
	  printBoard();
	  cout << "O Wins" << endl;
	  cout << "games won" << endl;
	  cout << "x: " << XWins << " games" << endl;
	  cout << "y: " << YWins << " games" << endl;
	  resetBoard();
	  break;
	}
      }
      counter++;
      printBoard();
    }
    else {
      cout << "invalid move" << endl;
    }
  }
  }
}
