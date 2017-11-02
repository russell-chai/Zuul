#include <iostream>
#include "DigitalMedia.h"

using namespace std;

DigitalMedia::DigitalMedia(char* newTitle, int newYear) {
  title = newTitle;
  year = newYear;
}
virtual void DigitalMedia::print() {
  cout << endl;
}
DigitalMedia::~DigitalMedia() {

}
char* DigitalMedia::getTitle() {
  return title;
}
int DigitalMedia::getYear() {
  return year;
}
int DigitalMedia::getType() {
  return type;
}
