#include "DigitalMedia.h"
#include <iostream>

using namespace std;

class Movie : public DigitalMedia {
 public:
  Movie(char* newTitle, char* newDirector, int year, float duration, float rating);
  virtual void print();
  char* getDirector();
  float getDuration();
  float getRating();
  ~Movie();
 private:
  char* director;
  float duration;
  float rating;
};
