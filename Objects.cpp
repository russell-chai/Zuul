#include <iostream>
#include "Objects.h"

using namespace std;

Objects::Objects(char* newName) {
  name = newName;
}

char* Objects::getName() {
  return name;
}
