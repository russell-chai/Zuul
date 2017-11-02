#include <iostream>
#include "DigitalMedia.h"

using namespace std;

class Music : public DigitalMedia {
 public:
  Music(char* newTitle, char* newArtist, int newYear, float newDuration, char* newPublisher);
  char* getArtist();
  float getDuration();
  char* getPublisher();
  ~Music();
 private:
  char* artist;
  float duration;
  char* publisher;
};
