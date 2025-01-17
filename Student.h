/*

  This file defines the Student class, which allows us to store informaiton about students
  

 */


//student.h file, mahika bhan, 01/16/2025


//header guard
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstring>

using namespace std;

//create Student class

class Student{
 public:
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

 private:
  char * firstname;
  char * lastname;
  int id;
  float gpa;


};

//end of header guard

#endif
