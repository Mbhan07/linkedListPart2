/*
  This is the second file I recieved from emma bendersky. This is the Node.h class which defines the Node class, which representa a node in a LL. Each node contains a pointer to a Student object/pointer to next node.

  Mahika Bhan, 1/16/2025
 */

//header guard
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

class Node // create Node class
{
 public:
  Node(Student*); //constructor
  ~Node(); // destructor
  Node* getNext(); //getNext() method
  Student* getStudent(); //getStudent() method
  void setNext(Node*); //setNext() method
  
 private:
  Student* student; //student object
  Node* next; //pointer to next node inLL
};

#endif
//end of header guard
