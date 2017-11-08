/*
Music header file
*/
#include <iostream>
#include "DigitalMedia.h"

using namespace std;

class Music : public DigitalMedia {//child of digital media
 public://public functions
  Music(char* newTitle, char* newArtist, int newYear, float newDuration, char* newPublisher);
  virtual void print();
  char* getArtist();
  float getDuration();
  char* getPublisher();
  ~Music();
 private://private variables
  char* artist;
  float duration;
  char* publisher;
};
