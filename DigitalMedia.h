
#ifndef DIGITALMEDIA_H
#define DIGITALMEDIA_H

#include <iostream>


class DigitalMedia {
 protected:
  int type;
  int year;
  char* title;
 public:
  DigitalMedia(char* title, int year);
  ~DigitalMedia();
  virtual void print();
  
  char* getTitle();
  int getYear();
  int getType();
};

#endif /* DIGITALMEDIA_H */
