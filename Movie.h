/*
Movie header file
*/
#include "DigitalMedia.h"
#include <iostream>

using namespace std;

class Movie : public DigitalMedia {//child of Digital Media
 public://public functions
  Movie(char* newTitle, char* newDirector, int year, float duration, float rating);
  virtual void print();
  char* getDirector();
  float getDuration();
  float getRating();
  ~Movie();
 private://private variables
  char* director;
  float duration;
  float rating;
};
