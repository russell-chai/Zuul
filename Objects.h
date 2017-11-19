/*
Object's header file
*/
//header guard
#ifndef OBJECTS_H
#define OBJECTS_H

#include <iostream>
using namespace std;

class Objects {
 public:
  //functions
  Objects(char* newName);  
  char* getName();
  ~Objects();
 private:
  //variables
  char* name;
};

#endif /* OBJECTS_H */
