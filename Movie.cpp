#include "Movie.h"
#include <iostream>

using namespace std;

Movie::Movie(char* newTitle, char* newDirector, int newYear, float newDuration, float newRating) : DigitalMedia(newTitle, newYear) {
  type = 3;
  title = newTitle;
  director = newDirector;
  year = newYear;
  duration = newDuration;
  rating = newRating;
}
void Movie::print() {
  cout << "Movie:" << endl;
  cout << "title: " << title << endl;
  cout << "director: " << director << endl;
  cout << "year: " << year << endl;
  cout << "rating: " << rating << endl;
  cout << endl;
}
char* Movie::getDirector() {
  return director;
}
float Movie::getDuration() {
  return duration;
}
float Movie::getRating() {
  return rating;
}
Movie::~Movie() {
  delete []title;
  delete []director;
}
