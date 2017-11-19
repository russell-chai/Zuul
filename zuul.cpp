/*
Author: Russell Chai
11/18/17
this program is a game where the user can go to rooms and grab and place objects
 */
#include <iostream>
#include <vector>
#include <map>
#include <string.h>
#include "Room.h"
#include "Objects.h"

//print what the user can do
void printOptions(Room *current, vector<Objects*> *inventory) {
  cout << "You are in: " << current->getName() << endl; //prints out what room user is in currently

  //prints out the items in the room
  cout << "In this room, there is: " << endl;
  if (current->sizeOfInventory() == 0) {
    cout << "nothing" << endl;
  }
  else {
    for (int a = 0; a < current->sizeOfInventory(); a++) {
      cout << current->getHasObjects()->at(a)->getName() << " " << endl;
    }
  }
  cout << endl;

  //prints out the items in user's inventory
  cout << "You have: " << endl;
  if (inventory->size() == 0) {
    cout << "nothing" << endl;
  }
  else {
    for (int a = 0; a < inventory->size(); a++) {
      cout << inventory->at(a)->getName() << " " << endl;
    }
  }
  cout << endl;

  //printing input options
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
    cout << "GRAB to place something in this room into your inventory" << endl;
  }
  cout << "QUIT to quit game" << endl;
}


int main() {
  //creating the objects
  Objects *waterBottle = new Objects("Water Bottle");
  Objects *backpack = new Objects("Backpack");
  Objects *sandwich = new Objects("Sandwich");
  Objects *laptop = new Objects("Laptop");
  Objects *tennisBall = new Objects("Tennis Ball");

  //creating the rooms and placing objects in rooms
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
  aWing->addObject(backpack);
  Room *footballField = new Room("Football Field");
  footballField->addObject(waterBottle);
  Room *bathroom = new Room("Bathroom");


  //linking rooms to each other
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


  Room *current = parkingLot; //begin in parking lot
  vector<Objects*> *inventory = new vector<Objects*>();//personal inventory
  while (true) {
    //losing condition: going onto cornell
    if (current == cornell) {
      cout << "On Cornell, you got hit by a car and died :(" << endl << "Game Over" << endl;
      return 0;
    }
    //winning condition: dropping all 5 items into locker
    if (current == locker && locker->sizeOfInventory() == 5) {1
      cout << "You have successfully placed all the items in the locker :)" << endl << "You Won!" << endl;
      return 0;
    }
    printOptions(current, inventory);//print options
    
    char* input = new char(10);
    cin.getline(input, 10);

    //if user wants to place item in room
    if (strcmp("DROP",input) == 0) {
      if (inventory->size() == 0) {
	cout << "Statement not recognized" << endl;
      }
      else {
	cout << "Input the name of the object you want to drop" << endl;
	char* objectName = new char(20);
	cin.getline(objectName, 20);
	int countTemp = 0;
	
	//searches through all of inventory for item
	for (int a = 0; a < inventory->size(); a++) {
	  if (strcmp(objectName, inventory->at(a)->getName()) == 0) {
	    current->addObject(inventory->at(a));
	    inventory->erase(inventory->begin() + a);
	    countTemp++;
	    break;
	  }
	}
	if (countTemp == 0) {
	  cout << "Object not found" << endl;
	}
      }
    }
    //if user wants to grab something from room
    else if (strcmp("GRAB", input) == 0) {
      if (current->sizeOfInventory() == 0) {
	cout << "Statement not recognized" << endl;
      }
      else {
	cout << "Input the name of the object you want to take from room" << endl;
	char* objectName = new char(20);
	cin.getline(objectName, 20);
	int countTemp = 0;
	//searches through all the items in the room
	for (int a = 0; a < current->sizeOfInventory(); a++) {
	  if (strcmp(objectName, current->getHasObjects()->at(a)->getName()) == 0) {
	    inventory->push_back(current->getHasObjects()->at(a));
	    current->removeObject(current->getHasObjects()->at(a));
	    countTemp++;
	    break;
	  }
	}
	if (countTemp == 0) {
	  cout << "Object not found" << endl;
	}
      }
    }
    //if user wants to quit
    else if (strcmp("QUIT", input) == 0) {
      cout << "Game Ended" << endl;
      return 0;
    }
    
    map<char*, Room*> :: iterator itr = current->getNextRooms().begin();
    bool found = false;
    //searches through all the adjacent room and see if they match input
    for (int a = 0; a < current->getNextRooms().size(); a++) {
      if (strcmp(itr->first, input) == 0) {
	current = itr->second;
	found = true;
	break;
      }
      itr++;
    }
    if (found == false) {
      cout << "Statement not recognized" << endl;
    }
    cout << endl;
    cout << endl;
    cout << endl;
  }
}
