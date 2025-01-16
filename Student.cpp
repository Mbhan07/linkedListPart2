
/*
In this file, it contains the functions for the student class
 */


//this is student.cpp file



#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;


//create student using inputted information

Student::Student(char * firstNameInput, char * lastNameInput, int inputid, float inputgpa){
  firstname = new char[200];
  lastname = new char [200];

  strcpy(firstname, firstNameInput);
  strcpy(lastname, lastNameInput);

  id = inputid;
  gpa = inputgpa;
  
}


//return first name

char * Student::getFirstName(){

  return firstname;
}


char * Student::getLastName(){

  return lastname;
}

int Student::getID() {

  return id;
}

float Student::getGPA(){

  return gpa;
}
