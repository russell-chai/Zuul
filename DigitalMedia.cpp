
/*
Digital Media's functions
*/
#include <iostream>
#include "DigitalMedia.h"

using namespace std;
//contructor
DigitalMedia::DigitalMedia(char* newTitle, int newYear) {
  title = newTitle;
  year = newYear;
}
void DigitalMedia::print() {
  cout << endl;
}

//digital media's destructor
DigitalMedia::~DigitalMedia() {

}

//getters
char* DigitalMedia::getTitle() {
  return title;
}
int DigitalMedia::getYear() {
  return year;
}
int DigitalMedia::getType() {
  return type;
}
