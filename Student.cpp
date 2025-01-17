
/*
In this file, it contains the functions for the student class. Allows for managing of information of a student, including first name, last name, id, GPA

Mahika Bhan 01/16/2025
*/


//this is student.cpp file



#include "student.h"
#include <iostream>
#include <cstring>

using namespace std;


//create student using inputted information

Student::Student(char * firstNameInput, char * lastNameInput, int inputid, float inputgpa){

  //allocate memory for first and last name
  firstname = new char[200];
  lastname = new char [200];

  //then copy input into allocated memoery

  strcpy(firstname, firstNameInput);
  strcpy(lastname, lastNameInput);

  //assign ID/GPA values

  id = inputid;
  gpa = inputgpa;
  
}


//return first name

char * Student::getFirstName(){

  return firstname;
}

//return last name

char * Student::getLastName(){

  return lastname;
}

//return ID

int Student::getID() {

  return id;
}

//return GPA

float Student::getGPA(){

  return gpa;
}
