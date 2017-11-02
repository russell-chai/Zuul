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
    cin >> title;
    cout << "input video game's year made" << endl;
    cin >> year;
    cout << "input video game's publisher" << endl;
    cin >> publisher;
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
    cin >> duration;
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
    cin >> duration;
    Movie *temp = new Movie(title, director, year, duration, rating);
    medias->push_back(temp);
    return;
  }
}

void search(vector<DigitalMedia*> *medias) {
  int type;
  cout << "input 1 for search by name" << endl;
  cout << "input 2 for search by year" << endl;
  cin >> type;
  if (type == 1) {
    char *title = new char(40);
    int count = 0;
    cout << "enter media title" << endl;
    cin >> title;
    for (int a = 0; a < medias->size(); a++) {
      if (strcmp(title, medias->at(a)->getTitle()) == 0) {
	if (medias->at(a)->getType() == 1) {
	  cout << "Video Game: ";
	  cout << medias->at(a)->getTitle() << " " << medias->at(a)->getYear() << " " << medias->at(a)->getPublisher() << " " << medias->at(a)->getRating() << endl;
	}
	else if (medias->at(a)->getType() == 2) {
	  cout << "Music: " << medias->at(a)->getTitle() << " " << medias->at(a)->getArtist() << " " << medias->at(a)->getYear() << " " << medias->at(a)->getDuration() << " " << medias->at(a)->getPublisher() << endl;
	}
	else if (medias->at(a)->getType() == 3) {
	  cout << "Movie: " << medias->at(a)->getTitle() << " " << medias->at(a)-> getDirector() << " " << medias->at(a)->getYear() << " " << medias->at(a)->getDuration() << " " << medias->at(a)->getRating() << endl;
	}
	count++;
      }
    }
    if (count == 0) {
      cout << "Nothing found" << endl;
    }
    break;
    
  }
  else if (type == 2) {
    int year;
    int count = 0;
    cout << "enter media's year published" << endl;
    cin >> year;
     for (int a = 0; a < medias->size(); a++) {
       if (medias->at(a)->getYear() == year) {
	if (medias->at(a)->getType() == 1) {
	  cout << "Video Game: ";
	  cout << medias->at(a)->getTitle() << " " << medias->at(a)->getYear() << " " << medias->at(a)->getPublisher() << " " << medias->at(a)->getRating() << endl;
	}
	else if (medias->at(a)->getType() == 2) {
	  cout << "Music: " << medias->at(a)->getTitle() << " " << medias->at(a)->getArtist() << " " << medias->at(a)->getYear() << " " << medias->at(a)->getDuration() << " " << medias->at(a)->getPublisher() << endl;
	}
	else if (medias->at(a)->getType() == 3) {
	  cout << "Movie: " << medias->at(a)->getTitle() << " " << medias->at(a)-> getDirector() << " " << medias->at(a)->getYear() << " " << medias->at(a)->getDuration() << " " << medias->at(a)->getRating() << endl;
	}
	count++;
      }
    }
     if (count == 0) {
       cout << "Nothing found" << endl;
     }
    break;
                     
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
      cout << medias->at(medias->size() - 1)->getType() << endl;
 
    }
    else if (strcmp(input, "SEARCH") == 0) {
      search(medias);
    }
  }
  
}
