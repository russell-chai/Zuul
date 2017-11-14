#include <iostream>
#include <vector>
#include <map>
#include "Room.h"
#include "Objects.h"

int main() {
  Objects *waterBottle = new Objects("Water Bottle");
  Objects *backpack = new Objects("Backpack");
  Objects *sandwich = new Objects("Sandwich");
  Objects *laptop = new Objects("Laptop");
  Objects *tennisBall = new Objects("Tennis Ball");
  
  Room *parkingLot = new Room("Parking Lot");
  Room *cornell = new Room("Cornell");
  Room *mainHall = new Room("Main Hall");
  Room *tennisCourt = new Room("Tennis Court");
  tennisCourt->addObject(tennisBall);
  Room *rightOneHall = new Room("Right Part of One Hall");
  Room *leftOneHall = new Room("Left Part of One Hall");
  Room *lowerCommons = new Room("Lower Commons");
  lowerCommons->addObject(sandwich);
  Room *upperCommons = new Room("Upper Commons");
  Room *locker = new Room("Locker");
  Room *computerLab = new Room("Computer Lab");
  computerLab->addObject(laptop);
  Room *gym = new Room("Gym");
  Room *mathClass = new Room("Math Class");
  Room *aWing = new Room("A Wing");
  Room *footballField = new Room("FootBall Field");
  Room *bathroom = new Room("Bathroom");


}
