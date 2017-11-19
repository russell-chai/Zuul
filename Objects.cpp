
#include <iostream>
#include "Objects.h"

using namespace std;

//objects's contructor
Objects::Objects(char* newName) {
  name = newName;
}
//returns object's name
char* Objects::getName() {
  return name;
}
