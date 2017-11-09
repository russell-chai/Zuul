#include <iostream>
#include <vector>
#include <map>
#include "Objects.h"
using namespace std;

class Room {
 public:
  Room(char* newName, vector<Objects*> *newHasObjects, map<char*, Room*> newNextRooms);
  char* getName();
  vector<Objects*>* getHasObjects();
  map<char*, Room*> getNextRooms();
 private:
  char* name;
  vector<Objects*> *hasObjects;
  map<char*, Room*> nextRooms;
  
};
