
/* This is one of the files that I used from emma bendersky. The Node.cpp file allows for implementation of the Node class

   Mahika Bhan, 01/16/2025
*/

#include "Node.h"

using namespace std;


//constructor: initializes node w/ pointer to student obj
//set Node pointer to null


Node::Node(Student* newStudent)
{
  student = newStudent;
  next = NULL;
}

//destructor (to free up mempory)
Node::~Node()
{
  delete student;
  next = NULL;
}

//returns pointer to next node in the LL
Node* Node::getNext()
{
  return next;
}

//set pointer to new node in LL
void Node::setNext(Node* newNext)
{
  next = newNext;
}


//return pointer to a student obj in node
Student* Node::getStudent()
{
  return student;
}
