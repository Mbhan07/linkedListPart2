#include <iostream>
#include "student.h"
#include "node.h"
#include <cstring>
#include <vector>
#include <iterator>
#include <iomanip>


using namespaces std;

/*
function prototypes 
 */

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

    //for adding, deleteing, averaging or printning, which will all require the same information per student

    if(strcmp(input, "ADD") == FALSE){
      

    }
  }
  
}
//main.cpp
