#include <iostream>
#include "Music.h"

using namespace std;

//constructor
Music::Music(char* newTitle, char* newArtist, int newYear, float newDuration, char* newPublisher) : DigitalMedia(newTitle, newYear) {
  type = 2;
  title = newTitle;
  artist = newArtist;
  year = newYear;
  duration = newDuration;
  publisher = newPublisher;
}
//destructor
Music::~Music() {
  cout << "deleted " << title << endl;
  delete[] title;
  delete[] artist;
  delete[] publisher;
}
//print function
void Music::print() {
  cout << "Music:" << endl;
  cout << "title: " << title << endl;
  cout << "artist: " << artist << endl;
  cout << "year: " << year << endl;
  cout << "duration: " << duration << endl;
  cout << "publisher: " << publisher << endl;
  cout << endl;
}

//getters
char* Music::getArtist() {
  return artist;
}
float Music::getDuration() {
  return duration;
}
char* Music::getPublisher() {
  return publisher;
}
