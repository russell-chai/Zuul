#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <string.h>

//constructor
Room::Room(char* newName) {
  name = newName;
  hasObjects = new vector<Objects*>;
}

//adds object into room
void Room::addObject(Objects *object) {
  hasObjects->push_back(object);
}

//return room's name
char* Room::getName() {
  return name;
}

//remove object from room
void Room::removeObject(Objects *object) {
  for (int a = 0; a < hasObjects->size(); a++) {
    if (strcmp(hasObjects->at(a)->getName(), object->getName()) == 0) {
      hasObjects->erase(hasObjects->begin() + a);
      break;
    }
  }
}

//return the number of objects in the room
int Room::sizeOfInventory() {
  return hasObjects->size();
}

//link room to an adjacent room
void Room::addAdjacentRoom(char* direction, Room* nextRoom) {
  nextRooms[direction] = nextRoom;
}
//return the vector of objects in the room
vector<Objects*>* Room::getHasObjects() {
  return hasObjects;
}

//return the map of the rooms connnected to this one
map<char*, Room*> Room::getNextRooms() {
  return nextRooms;
}
