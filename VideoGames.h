/*
Video Game header file
*/
#include <iostream>
#include "DigitalMedia.h"

using namespace std;

class VideoGames : public DigitalMedia { //child of DigitalMedia
 public://public functions
  VideoGames(char* newTitle, int newYear, char* newPublisher, float newRating);
  char* getPublisher();
  float getRating();
  ~VideoGames();
  virtual void print();
 private://its own variables
  char* publisher;
  float rating;
};
