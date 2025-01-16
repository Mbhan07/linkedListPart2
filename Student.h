//student.h file, mahika bhan

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

//create Student class

class Student{

  //create new student
  Student(char * firstNameInput, char * lastNameInput, int inputid, float inputgpa);
  // first name
  char * getFirstName();
  //last name
  char * getLastName();
  //id number
  int getID();
  //gpa value
  float getGPA();


  char * firstname;
  char * lastname;
  id id;
  float gpa;


};

#endif
