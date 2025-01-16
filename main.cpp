#include <iostream>
#include "student.h"
#include "node.h"
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>


using namespace std;

/*

  This is Linked Lists Part 2! This project uses the old Student List program, only with better retrieval of students since the program now includes linked lists.

  Here are sources I used for concepts such as recursion, traversing through linked lists, etc:

  https://stackoverflow.com/questions/48671554/how-do-you-print-a-linked-list-recursively-in-c
  

 */
//function prototypes 
 

void ADD(Node * current, Node * previous, Student * newStudent, Node * &head);
void PRINT(Node * head);
void DELETE(Node * current, Node * previous, int id, Node *& head);
void AVERAGE(Node * current, Node * head, int count, float average);

int main(){

  //initialize variables needed
  Node * head = NULL;
  Node * current = head;
  char input[30];

  while (true) {
    //user can add, delete, print, average or quit

    cout << "ADD, DELETE, PRINT, AVERAGE or QUIT" << endl;
    cin >> input;
    cin.ignore();

    if(strcmp(input, "ADD") == 0){
      char * first = new char[100];
      char * last = new char[100];
      int id;
      float gpa;


      cout << "Please enter the student's first name: ";
      cin.getline(first, 100);

      cout << "Please get the student's last name: ";
      cin.getline(last, 100);

      cout << "Please enter the student's ID: ";
      cin >> id;
      cin.ignore();

      cout << "Please enter the student's GPA: ";
      cin >> gpa;
      cin.ignore();

      //make new student with information inputted
      Student * newStudent = new Student((char*) first, (char*) last, id, (float)gpa);
      ADD(head, nullptr, newStudent, head);

      //to keep the code clean
      

    }else if(strcmp(input, "DELETE") == 0){
      cout << "Enter in the ID of the student you'd like to delete: ";
      int idToDelete = 0;
      cin >> idToDelete;
      cin.ignore();

      cout << "You're deleteing the student with the ID of " << idToDelete << endl;

      DELETE(head, head, idToDelete, head);

    }else if (strcmp(input, "PRINT") == 0){
      if(head == NULL){
	cout << "There are no students in the list currently." << endl;
	;
      }else {
	PRINT(head);
      }
    }else if (strcmp(input, "AVERAGE") == 0){
      AVERAGE(head, head, 0, 0.0f); 
    }else if (strcmp(input, "QUIT") == 0){
      exit(0);
    }
  }

  return 0;
  
}

void ADD(Node * current, Node * previous, Student * newStudent, Node * &head){

  if (head == NULL){
    cout << "Is my add function working?" << endl;
    head = new Node(newStudent);
    return;
  }
  if (current == NULL || newStudent -> getID() <= current -> getStudent()-> getID()){
    Node * newNode = new Node(newStudent);
    if (current == NULL){
      previous -> setNext(newNode);
    }else {
      newNode -> setNext(current);
      previous -> setNext(newNode);
    }
    return;
  }

  ADD(current-> getNext(), current, newStudent, head);
}


void PRINT(Node * head){
  if (head == NULL){
    return;
  }else {
    if(head != NULL){
      cout << head->getStudent()->getFirstName() << " ";
      cout << head->getStudent()->getLastName() << ", ";
      cout << fixed << setprecision(2) << head->getStudent()->getID() << ", ";
      cout << head->getStudent()->getGPA() << endl;
      head = head->getNext();
      /*cout << head -> getStudent()->getFirstName()<< " " << endl;
      cout << head -> getStudent()->getLastName()<< " " << endl;
      cout<<fixed<<setprecision(2)<<head->getStudent()->getID()<<",";
      cout<<head->getStudent()->getGPA()<<endl;
      PRINT(head->getNext());*/
    }
    
  }

}

void AVERAGE(Node * current, Node * head, int count, float average){
  if (current == NULL){
    if (count == 0){
      cout << "No students availible to calculate average: " << endl;
      
    }else {

      //source: https://stackoverflow.com/questions/10181149/c-walkthrough-cout-setfiosfixed-and-cout-precision
       cout.setf(ios::fixed, ios::floatfield);
       cout.setf(ios::showpoint);
       cout.precision(2);
       cout << "Average GPA: " << average / count << endl;
    }
    return;
  }
  average += current -> getStudent()-> getGPA();
  count ++;
  AVERAGE(current -> getNext(), head, count, average);
}

void DELETE(Node * current, Node * pre, int id, Node * &head){
  if (current == NULL){
    cout << "Nothing in database" << endl;
    return;
  }

  if(current != NULL && current -> getStudent() -> getID() == id){
    if (head == current){
      head = current -> getNext();
      delete current;
    }else {
      pre -> setNext(current -> getNext());
      delete current;
    }
    return;

  }
  DELETE(current -> getNext(), current, id, head);

}

//main.cpp
