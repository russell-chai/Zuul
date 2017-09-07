#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
  //for pseudorandom generator
  srand(time(NULL));

  //while the player keeps wanting to play
  while (true) {
    //generate a new random number from 0-100
    int randomNumber = rand() % 101;
    //counter for how many tries
    int counter = 0;
    //while they keep guessing
    while (true) {
      //increase tries counter
      counter++;
      //get user guess
      int input;
      cin >> input;
      //check if higher or lower or correct
      if (input > randomNumber) {
	cout << "too high" << endl;
      }
      else if (input < randomNumber) {
	cout << "too low" << endl;
      }
      else {
	cout << "correct" << endl;
	cout << "tries: " << counter << endl;
	cout << "want to play again? (y/n)" << endl;
	break;
      }
    }
    //get user response
    char response;
    cin >> response;
    if (response == 'y') {
      //if yes, reset counter and get new random number
      counter = 0;
      randomNumber = rand() % 101;
    }
    else {
      //else stop
      break;
    }
  }
 
  return 0;
}
