/*
Author: Russell Chai
This program creates of list of students where the user can add and delte students
*/
#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>

using namespace std;

//student struct
struct student {
  char firstName[50];
  char lastName[50];
  int ID;
  float GPA;
};
//add student
void addStudent(vector<student> &students) {
  student temp;
  cout << "what is student's first name" << endl;
  cin >> temp.firstName;
  cout << "what is student's last name" << endl;
  cin >> temp.lastName;
  cout << "what is student's ID" << endl;
  cin >> temp.ID;
  cout << "what is student's GPA" << endl;
  cin >> temp.GPA;
  //add student to vector
  students.push_back(temp);
}
//print all the students
void printStudents(vector<student> &students) {
  cout << setprecision(2) << fixed;
  for (int a = 0; a < students.size(); a++) {
    cout << students[a].firstName << " " << students[a].lastName << ", " <<
      students[a].ID << ", " << students[a].GPA << endl;
  }
}
//delete students
void deleteStudents(vector<student> &students) {
  int tempId;
  cout << "what is student's ID" << endl;
  cin >> tempId;
  for (int a = 0; a < students.size(); a++) {
    if (students[a].ID == tempId) {
      students.erase(students.begin() + a);
      break;
    }
  }
}
int main() {
  vector<student> students;
  vector<student> *ptrStudent = &students;
  while (true) {
    char *input;
    cin >> input;
    //takes in input and check for command
    if (strcmp(input, "ADD") == 0) {
      addStudent(students);
    }
    else if (strcmp(input, "PRINT") == 0) {
      printStudents(students);
    }
    else if (strcmp(input, "DELETE") == 0) {
      deleteStudents(students);
    }
    else if (strcmp(input, "QUIT") == 0) {
      break;
    }
    else {
      cout << input << "is not a command" << endl;
      cout << "comands are ADD PRINT DELETE and QUIT" << endl;
    }
  }
}
