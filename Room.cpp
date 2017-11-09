#include <iostream>
#include "Room.h"
#include <vector>
#include <map>

Room::Room(char* newName, vector<Objects*> *newHasObjects, map<char*, Room*> newNextRoom) {
  name = newName;
  hasObjects = newHasObjects;
  nextRooms = newNextRoom;
}

vector<Objects*>* Room::getHasObjects() {
  return hasObjects;
}

map<char*, Room*> Room::getNextRooms() {
  return nextRooms;
}
