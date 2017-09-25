/*
Author: Russell Chai
Date: 9/13/17
This programs takes in a line and sees if it is a palindrome
*/
#include <iostream>

using namespace std;

int main() {
  cout << "enter statement and will output if it is a palindrome or not" << endl;
  //char array for input
  char palindromeTest[80];
  
  cin.get(palindromeTest, 80);
  cin.get();
  
  int counter = 0;

  //forward
  char array1[80];
  //backwards
  char array2[80];
  
  for (int a = 0; a < 80; a++) {
    //while the test hasn't been returned
    if (palindromeTest[a] == '\0') {
      break;
    }
    //if it is a lowercase letter
    if ('a' <= palindromeTest[a] && palindromeTest[a] <= 'z') {
      array1[counter] = palindromeTest[a];
      counter++;
    }
    //if it is a uppercase letter convert to lowercase and then add
    else if ('A' <= palindromeTest[a] && palindromeTest[a] <= 'Z') {
      array1[counter] = palindromeTest[a] - 'A' + 'a';
      counter++;
    }
    //if it is a number
    else if ('0' <= palindromeTest[a] && palindromeTest[a] <= '9') {
      array1[counter] = palindromeTest[a];
      counter++;
    }
    //if its not a number or letter, ignore
  }

  //reverse the letters and add them to another array
  for (int a = 0; a < counter; a++) {
    array2[counter - a - 1] = array1[a];
  }
  //compare the two arrays
  for (int a = 0; a < counter; a++) {
    if (array1[a] != array2[a]) {
      cout << "not a palindrome" << endl;
      return 0;
    }
  }
  cout << "is palindrome" << endl;
  return 0;
}
