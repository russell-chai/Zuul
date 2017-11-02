#include <iostream>
#include "VideoGames.h"

using namespace std;

VideoGames::VideoGames(char* newTitle, int newYear, char* newPublisher, float newRating) : DigitalMedia(newTitle, newYear) {
  type = 1;
  title = newTitle;
  year = newYear;
  publisher = newPublisher;
  rating = newRating;
}
VideoGames
VideoGames::~VideoGames() {
  
}
char* VideoGames::getPublisher() {
  return publisher;
}
float VideoGames::getRating() {
  return rating;
}
