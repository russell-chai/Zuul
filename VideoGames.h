#include <iostream>
#include "DigitalMedia.h"

using namespace std;

class VideoGames : public DigitalMedia {
 public:
  VideoGames(char* newTitle, int newYear, char* newPublisher, float newRating);
  char* getPublisher();
  float getRating();
  ~VideoGames();
  virtual void print();
 private:
  char* publisher;
  float rating;
};
