#include <iostream>
#include "Room.h"
#include <vector>
#include <map>
#include <string.h>

Room::Room(char* newName) {
  name = newName;
  hasObjects = new vector<Objects*>;
}

void Room::addObject(Objects *object) {
  hasObjects->push_back(object);
}

char* Room::getName() {
  return name;
}
void Room::removeObject(Objects *object) {
  for (int a = 0; a < hasObjects->size(); a++) {
    if (strcmp(hasObjects->at(a)->getName(), object->getName()) == 0) {
      hasObjects->erase(hasObjects->begin() + a);
      break;
    }
  }
}
int Room::sizeOfInventory() {
  return hasObjects->size();
}
void Room::addAdjacentRoom(char* direction, Room* nextRoom) {
  nextRooms[direction] = nextRoom;
}
vector<Objects*>* Room::getHasObjects() {
  return hasObjects;
}

map<char*, Room*> Room::getNextRooms() {
  return nextRooms;
}
