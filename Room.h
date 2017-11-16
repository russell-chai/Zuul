#include <iostream>
#include <vector>
#include <map>
#include "Objects.h"
using namespace std;

class Room {
 public:
  Room(char* newName);
  char* getName();
  vector<Objects*>* getHasObjects();
  map<char*, Room*> getNextRooms();
  void addObject(Objects* object);
  void removeObject(Objects* object);
  void addAdjacentRoom(char* direction, Room* newRoom);
  int sizeOfInventory();
 
 private:
  char* name;
  vector<Objects*> *hasObjects;
  map<char*, Room*> nextRooms;
  
};
