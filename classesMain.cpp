/*
Author: Russell Chai
Date: 11/7/17
This program allows the user to create a data base of different types of digital medias
and allows user to add, search, and delete medias
*/
#include <iostream>
#include <vector>
#include <string.h>
#include "DigitalMedia.h"
#include "VideoGames.h"
#include "Music.h"
#include "Movie.h"

using namespace std;

//function for adding media
void addMedia(vector<DigitalMedia*> *medias) {
  int type; 
  cout << "for video game, input 1" << endl;
  cout << "for music, input 2" << endl << "for movie, input 3" << endl;
  cin >> type; //asks for type of media, and then media gets added to vector 
  cin.ignore();
  cout << endl;
  if (type == 1) { //if media is a video game...
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
    VideoGames *temp = new VideoGames(title, year, publisher, rating); //creates object
    medias->push_back(temp); //pushes it into main vector
    return;
  }
  if (type == 2) {//if media is a song...
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
    cin.getline(publisher, 40);
    Music *temp = new Music(title, artist, year, duration, publisher);
    medias->push_back(temp);
    return;
  }
  if (type == 3) {//if media is a movie...
    char *title = new char(40);
    char *director = new char(40);
    int year;
    float duration, rating;
    cout << "input movie name" << endl;
    cin.getline(title, 40);
    cout << "input director" << endl;
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
//function that searches for a digital media file by either name or year made
void search(vector<DigitalMedia*>  *medias) {
  cout << "input 1 for search by name" << endl;//asks if user wants to input by title..
  cout << "input 2 for search by year" << endl;//or by year
  int input;
  cin >> input;
  cin.ignore();
  cout << endl;
  int count = 0;//to check if there were any matches found
  if (input == 1) {
    cout << "input media's title" << endl;
    char* title = new char(40);
    cin.getline(title, 40);
    for (int a = 0; a < medias->size(); a++) {//goes through every object until it finds a match
      if (strcmp(medias->at(a)->getTitle(), title) == 0) {
	medias->at(a)->print();
	count++;
      }
    }
  }
  else {
    cout << "input media's year" << endl;
    int year;
    cin >> year;
    cin.ignore();
    for (int a = 0; a < medias->size(); a++) {//goes through every object until it finds a match
      if (medias->at(a)->getYear() == year) {
	medias->at(a)->print();
	count++;
      }
    }
  }
  if (count == 0) { //nothing found
    cout << "nothing found" << endl;
  }
}
//function used to remove something from main vector
void remove(vector<DigitalMedia*> *medias) {
  cout << "input 1 for delete by name" << endl;//asks if user wants to delete by name...
  cout << "input 2 for delete by year" << endl;//or by year
  int input;
  cin >> input;
  cin.ignore();
  int count = 0;
  if (input == 1) {//if deleting by name
    cout << "input media's title" << endl;
    char* title = new char(40);
    cin.getline(title, 40);
    for (int a = 0; a < medias->size(); a++) { //goes and checks through every object
      if (strcmp(medias->at(a)->getTitle(), title) == 0) {
	count++;
	cout << "Do you want to delete...(y/n)" << endl; //asks user to confirm delete
	medias->at(a)->print();
	char response;
	cin >> response;
	cin.ignore();
	if (response == 'y') {//manually calls destructor
	  delete medias->at(a);
	  medias->erase(medias->begin() + a);
	  a--;
	}
      }
    }
  }
  else {//if deleting by year
    cout << "input media's year" << endl;
    int year;
    cin >> year;
    cin.ignore();
    for (int a = 0; a < medias->size(); a++) {//goes and checks through every object
      if (medias->at(a)->getYear() == year) {
	count++;
	cout << "Do you want to delete...(y/n)" << endl;//asks yser to confirm delete
	medias->at(a)->print();
	char response;
	cin >> response;
	cin.ignore();
	if (response == 'y') {//manually calls destructor
	  delete medias->at(a);
	  medias->erase(medias->begin() + a);
	  a--;
	}
      }
    }
  }
  if (count == 0) {
    cout << "nothing found" << endl;
  }
}
int main() {
  
  vector<DigitalMedia*> *medias = new vector<DigitalMedia*>();//main vector containing all objects
  while(true) {
    //asks user what they want to do
    cout << "type ADD to add media" << endl;
    cout << "type SEARCH to search for media" << endl;
    cout << "type DELETE to delete media" << endl;
    cout << "type QUIT to quit" << endl;
    char *input = new char(6);
    cin >> input;
    cin.ignore();
    if (strcmp(input, "ADD") == 0) {//add
      cout << endl;
      addMedia(medias);
      cout << endl;
      medias->at(medias->size() - 1)->print();
      cout << endl;
    }
    else if (strcmp(input, "SEARCH") == 0) {//search
      cout << endl;
      search(medias);
      cout << endl;
    }
    else if (strcmp(input, "DELETE") == 0) {//delete
      cout << endl;
      remove(medias);
      cout << endl;
    }
    else if (strcmp(input, "QUIT") == 0) {//quit
      return 0;
    }
    
  }
  
}
