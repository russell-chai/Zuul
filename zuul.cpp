#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include "Room.h"
#include "Objects.h"

void printOptions(Room *current, vector<Objects*> *inventory) {
  cout << "You are in: " << current->getName() << endl;
  cout << "There is: " << endl;
  if (current->sizeOfInventory() == 0) {
    cout << "nothing in this room" << endl;
  }
  else {
    for (int a = 0; a < current->sizeOfInventory(); a++) {
      cout << current->getHasObjects()->at(a)->getName() << " " << endl;
    }
    cout << "in this room" << endl;
  }
  
  cout << "You have: " << endl;
  if (inventory->size() == 0) {
    cout << "nothing in your inventory" << endl;
  }
  else {
    for (int a = 0; a < inventory->size(); a++) {
      cout << inventory->at(a)->getName() << " " << endl;
    }
    cout << "in your inventory" << endl;
  }

  cout << "Type.." << endl;
  map<char*, Room*> :: iterator itr = current->getNextRooms().begin();
  for (int a = 0; a < current->getNextRooms().size(); a++) {
    cout << itr->first << " to go to " << itr->second->getName() << endl;
    itr++;
  }
  if (inventory->size() > 0) {
    cout << "DROP to place something in your inventory into this room" << endl;
  }
  if (current->sizeOfInventory() > 0) {
    cout << "GRAP to place something in this room into your inventory" << endl;
  }
}
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
  Room *footballField = new Room("Football Field");
  Room *bathroom = new Room("Bathroom");

  parkingLot->addAdjacentRoom("FORWARD", mainHall);
  parkingLot->addAdjacentRoom("BACKWARD", cornell);
  parkingLot->addAdjacentRoom("LEFT", tennisCourt);

  cornell->addAdjacentRoom("FORWARD", parkingLot);

  mainHall->addAdjacentRoom("LEFT", rightOneHall);
  mainHall->addAdjacentRoom("BACKWARD", parkingLot);

  tennisCourt->addAdjacentRoom("RIGHT", parkingLot);

  rightOneHall->addAdjacentRoom("FORWARD", lowerCommons);
  rightOneHall->addAdjacentRoom("BACKWARD", mainHall);
  rightOneHall->addAdjacentRoom("LEFT", leftOneHall);
  rightOneHall->addAdjacentRoom("RIGHT", aWing);

  leftOneHall->addAdjacentRoom("FORWARD", upperCommons);
  leftOneHall->addAdjacentRoom("BACKWARD", computerLab);
  leftOneHall->addAdjacentRoom("LEFT", mathClass);
  leftOneHall->addAdjacentRoom("RIGHT", rightOneHall);

  lowerCommons->addAdjacentRoom("FORWARD", locker);
  lowerCommons->addAdjacentRoom("BACKWARD", rightOneHall);
  lowerCommons->addAdjacentRoom("LEFT", upperCommons);

  upperCommons->addAdjacentRoom("FORWARD", gym);
  upperCommons->addAdjacentRoom("BACKWARD", leftOneHall);
  upperCommons->addAdjacentRoom("RIGHT", lowerCommons);

  locker->addAdjacentRoom("BACKWARD", lowerCommons);

  computerLab->addAdjacentRoom("FORWARD", leftOneHall);

  gym->addAdjacentRoom("FORWARD", footballField);
  gym->addAdjacentRoom("BACKWARD", upperCommons);
 
  mathClass->addAdjacentRoom("RIGHT", leftOneHall);

  aWing->addAdjacentRoom("BACKWARD", bathroom);
  aWing->addAdjacentRoom("LEFT", rightOneHall);

  footballField->addAdjacentRoom("BACKWARD", gym);
  footballField->addAdjacentRoom("RIGHT", cornell);

  bathroom->addAdjacentRoom("FORWARD", aWing);

  Room *current = parkingLot;
  vector<Objects*> *inventory = new vector<Objects*>();
  while (true) {
    if (current == cornell) {
      cout << "On Cornell, you got hit by a car and died :(" << endl << "Game Over" << endl;
      return 0;
    }
    if (current == locker && locker->sizeOfInventory() == 5) {
      cout << "You have successfully placed all the items in the locker :)" << endl << "You Won!" << endl;
      return 0;
    }
    printOptions(current, inventory);
    char* input = new char(10);
    cin.getLine(input, 10);
    if (strcmp("DROP",input) == 0) {
      if (inventory->size() == 0) {
	cout << "Statement not recognized" << endl;
      }
      /*

       */
    }
  }
}
