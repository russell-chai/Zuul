/*
Digital Media header file
 */
//header guard
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <iostream>


class DigitalMedia {
  //variables that are passed down to children
 protected:
  int type;
  int year;
  char* title;
 public:
  DigitalMedia(char* title, int year);
  virtual ~DigitalMedia();
  virtual void print();
  
  char* getTitle();
  int getYear();
  int getType();
};

#endif /* DIGITALMEDIA_H */
