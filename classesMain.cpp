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
  cin.ignore();
  if (type == 1) {
    char *title = new char(40);
    char *publisher = new char(40);
    int year;
    float rating;
    cout << "input video game's title" << endl;
    cin.getline(title, 40);
    cout << "input video game's year made" << endl;
    cin >> year;
    cin.ignore();
    cout << "input video game's publisher" << endl;
    cin.getline(publisher, 40);
    cout << "input video game's rating" << endl;
    cin >> rating;
    cin.ignore();
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
    cin.getline(title, 40);
    cout << "input artist" << endl;
    cin.getline(artist, 40);
    cout << "input year made" << endl;
    cin >> year;
    cin.ignore();
    cout << "input song duration" << endl;
    cin >> duration;
    cin.ignore();
    cout << "input publisher" << endl;
    cin >> publisher;
    cin.getline(publisher, 40);
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
    cin.getline(title, 40);
    cout << "input director" << endl;
    cin >> director;
    cin.getline(director, 40);
    cout << "input year movie was published" << endl;
    cin >> year;
    cin.ignore();
    cout << "input movie duration" << endl;
    cin >> duration;
    cin.ignore();
    cout << "input movie rating" << endl;
    cin >> rating;
    cin.ignore();
    Movie *temp = new Movie(title, director, year, duration, rating);
    medias->push_back(temp);
    return;
  }
}
void search(vector<DigitalMedia*>  *medias) {
  cout << "input 1 for search by name" << endl;
  cout << "input 2 for search by year" << endl;
  int input;
  cin >> input;
  cin.ignore();
  if (input == 1) {
    cout << "input media's title" << endl;
    char* title = new char(40);
    cin.getline(title, 40);
    for (int a = 0; a < medias->size(); a++) {
      if (strcmp(medias->at(a)->getTitle(), title) == 0) {
	medias->at(a)->print();
      }
    }
  }
  else {
    cout << "input media's year" << endl;
    int year;
    cin >> year;
    cin.ignore();
    for (int a = 0; a < medias->size(); a++) {
      if (medias->at(a)->getYear() == year) {
	medias->at(a)->print();
      }
    }
  }
}
int main() {
  
  vector<DigitalMedia*> *medias = new vector<DigitalMedia*>();
  while(true) {
    cout << "type ADD to add media" << endl;
    cout << "type SEARCH to search for media" << endl;
    cout << "type DELETE to delete media" << endl;
    cout << "type QUIT to quit" << endl;
    char *input = new char(6);
    cin >> input;
    cin.ignore();
    if (strcmp(input, "ADD") == 0) {
      addMedia(medias);
      medias->at(medias->size() - 1)->print();
    }
    else if (strcmp(input, "SEARCH") == 0) {
      search(medias);
    }
    
  }
  
}
