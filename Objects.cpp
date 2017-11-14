#include <iostream>
#include "Objects.h"

using namespace std;

Objects::Objects(char* newName) {
  name = newName;
}
Objects::~Objects() {
  delete []name;
}
char* Objects::getName() {
  return name;
}
