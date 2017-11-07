#include <iostream>
#include <vector>
#include <string.h>
#include "DigitalMedia.h"
#include "VideoGames.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

void addMedia(vector<DigitalMedia*> *medias) {
  int type;
  cout << "for video game, input 1" << endl;
  cout << "for music, input 2" << endl << "for movie, input 3" << endl;
  cin >> type;
  if (type == 1) {
    char *title = new char(40);
    char *publisher = new char(40);
    int year;
    float rating;
    cout << "input video game's title" << endl;
    cin.get(title, 40);
    cout << "input video game's year made" << endl;
    cin >> year;
    cout << "input video game's publisher" << endl;
    cin.get(publisher, 40);
    cout << "input video game's rating" << endl;
    cin >> rating;
    VideoGames *temp = new VideoGames(title, year, publisher, rating);
    medias->push_back(temp);
    return;
  }
  if (type == 2) {
    char *title = new char(40);
    char *artist = new char(40);
    char *publisher = new char(40);
    int year;
    float duration;
    cout << "input song name" << endl;
    cin >> title;
    cout << "input artist" << endl;
    cin >> artist;
    cout << "input year made" << endl;
    cin >> year;
    cout << "input song duration" << endl;
    cin >> duration;
    cout << "input publisher" << endl;
    cin >> publisher;
    Music *temp = new Music(title, artist, year, duration, publisher);
    medias->push_back(temp);
    return;
  }
  if (type == 3) {
    char *title = new char(40);
    char *director = new char(40);
    int year;
    float duration, rating;
    cout << "input movie name" << endl;
    cin >> title;
    cout << "input director" << endl;
    cin >> director;
    cout << "input year movie was published" << endl;
    cin >> year;
    cout << "input movie duration" << endl;
    cin >> duration;
    cout << "input movie rating" << endl;
    cin >> rating;
    Movie *temp = new Movie(title, director, year, duration, rating);
    medias->push_back(temp);
    return;
  }
}
int main() {
  cout << "type ADD to add media" << endl;
  cout << "type SEARCH to search for media" << endl;
  cout << "type DELETE to delete media" << endl;
  cout << "type QUIT to quit" << endl;
  vector<DigitalMedia*> *medias = new vector<DigitalMedia*>();
  while(true) {
    char *input = new char(6);
    cin >> input;
    if (strcmp(input, "ADD") == 0) {
      addMedia(medias);
      medias->at(medias->size() - 1)->print();
 
    }
    
  }
  
}
