#include "Movie.h"
#include <iostream>

using namespace std;

//constructor
Movie::Movie(char* newTitle, char* newDirector, int newYear, float newDuration, float newRating) : DigitalMedia(newTitle, newYear) {
  type = 3;
  title = newTitle;
  director = newDirector;
  year = newYear;
  duration = newDuration;
  rating = newRating;
}
//print function
void Movie::print() {
  cout << "Movie:" << endl;
  cout << "title: " << title << endl;
  cout << "director: " << director << endl;
  cout << "year: " << year << endl;
  cout << "duration: " << duration << endl;
  cout << "rating: " << rating << endl;
  cout << endl;
}

//getters
char* Movie::getDirector() {
  return director;
}
float Movie::getDuration() {
  return duration;
}
float Movie::getRating() {
  return rating;
}

//destructor
Movie::~Movie() {
  cout << "deleted " << title << endl;
  delete []title;
  delete []director;
}
