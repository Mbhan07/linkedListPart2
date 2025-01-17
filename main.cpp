#include <iostream>
#include "student.h"
#include "node.h"
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>


using namespace std;

/*

  This is Linked Lists Part 2! Using linked lists, we manage a list of students (spin off from the old Student List program)
  

  Here are sources I used for concepts such as recursion, traversing through linked lists, etc:

  https://www.geeksforgeeks.org/program-to-implement-singly-linked-list-in-c-using-class/ 
  https://www.cprogramming.com/tutorial/lesson15.html
  https://cplusplus.com/reference/iomanip/setprecision/ https://stackoverflow.com/questions/48671554/how-do-you-print-a-linked-list-recursively-in-c 5. 
  https://github.com/Mbhan07/studentList/blob/main/studentList.cpp
  https://github.com/Mbhan07/linkedlist/blob/main/main.cpp

  Mahika Bhan, 01/16/2025
  
  Why is recursion needed in the context of this project?
  It allows us to traverse and easily manipulate linked lists. Makes it easier to add, delete, etc

 */


//function prototypes 
 
void ADD(Node * current, Node * previous, Student * newStudent, Node * &head);
void PRINT(Node * head);
void DELETE(Node * current, Node * previous, int id, Node *& head);
void AVERAGE(Node * current, Node * head, int count, float average);

int main(){

  //initialize variables needed
  Node * head = NULL; //pointer to head of linked list
  Node * current = head; //temporary pointer
  char input[30];

  while (true) {
    //user can add, delete, print, average or quit

    cout << "ADD, DELETE, PRINT, AVERAGE or QUIT" << endl;
    cin >> input;
    cin.ignore();


    //if user says add, get information like first name, last name, id, gpa, then call the ADD function
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
      
      //ADD(current, previous, newStudent, head);
      ADD(head, NULL, newStudent, head);
      
      //if user sayds delete, then enter ID and call the DELETE function
    }else if(strcmp(input, "DELETE") == 0){
      cout << "Enter in the ID of the student you'd like to delete: ";
      int idToDelete = 0;
      cin >> idToDelete;
      cin.ignore();

      cout << "You're deleteing the student with the ID of " << idToDelete << endl;


      DELETE(head, head, idToDelete, head);

    //if user says print, call the PRINT function
    }else if (strcmp(input, "PRINT") == 0){
      if(head == NULL){
	cout << "There are no students in the list currently." << endl;
	;
      }else {
	PRINT(head);
      }
    //if user says AVERAGE, call the average function 
    }else if (strcmp(input, "AVERAGE") == 0){
      AVERAGE(head, head, 0, 0.0f);

      //exit if user says quit
    }else if (strcmp(input, "QUIT") == 0){
      exit(0);
    }
  }

  return 0;
  
}

//add a student to the list recursively, using recursion, and sorting by ID
void ADD(Node * current, Node * previous, Student * newStudent, Node * &head){

  if (head == NULL){ // if the list is empty
    //cout << "Is my add function working?" << endl;
    head = new Node(newStudent);
    return;
  }

  //
  if (current == NULL || newStudent -> getID() <= current -> getStudent()-> getID()){

    //create new node and insert it in correct place
    Node * newNode = new Node(newStudent);
    if (current == NULL){ //to insert at the end of the list
      previous -> setNext(newNode);
    }else { //insert at middle or beginning,
      if(!previous) { 
	head = newNode;
	newNode ->setNext(current);
      } else {
	newNode ->setNext(current);
	previous ->setNext(newNode);

      }

      //this was my prvious code, but it was leading to seg fault, so i had to write the above code, which accounts for all cases of adding students
      // newNode -> setNext(current);
      // previous -> setNext(newNode);
    }
    return;
  }

  //recursive call
  ADD(current-> getNext(), current, newStudent, head);
}

//print all students (recursively)
void PRINT(Node * head){
  if (head == NULL){ 
    return;
  }else {
    if(head != NULL){
      cout << head->getStudent()->getFirstName() << " ";
      cout << head->getStudent()->getLastName() << ", ";
      cout << fixed << setprecision(2) << head->getStudent()->getID() << ", ";
      cout << head->getStudent()->getGPA() << endl;
      PRINT(head->getNext()); // recursive call

      //head = head->getNext();
      /*cout << head -> getStudent()->getFirstName()<< " " << endl;
      cout << head -> getStudent()->getLastName()<< " " << endl;
      cout<<fixed<<setprecision(2)<<head->getStudent()->getID()<<",";
      cout<<head->getStudent()->getGPA()<<endl;
      PRINT(head->getNext());*/
    }
    
  }

}

//calculate average GPA of students recursively
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


//delete a student by ID (recursively)
void DELETE(Node * current, Node * pre, int id, Node * &head){
  if (current == NULL){ // base case: current node is null/reached the end of the list, list is empty/ID not found
    cout << "Nothing in database" << endl;
    return;
  }
  
  //check if current node student ID matches tht ID to be deleted
  if(current != NULL && current -> getStudent() -> getID() == id){
    if (head == current){
      head = current -> getNext(); //update head to point to the next node
      delete current;
    }else {

      //if node to delete is at middle or end
      pre -> setNext(current -> getNext());
      delete current;
    }
    return;

  }
  //recursive call
  DELETE(current -> getNext(), current, id, head);

}

//main.cpp
