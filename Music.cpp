#include <iostream>
#include "Music.h"

using namespace std;

Music::Music(char* newTitle, char* newArtist, int newYear, float newDuration, char* newPublisher) : DigitalMedia(newTitle, newYear) {
  type = 2;
  title = newTitle;
  artist = newArtist;
  year = newYear;
  duration = newDuration;
  publisher = newPublisher;
} 
char* Music::getArtist() {
  return artist;
}
float Music::getDuration() {
  return duration;
}
char* Music::getPublisher() {
  return publisher;
}
