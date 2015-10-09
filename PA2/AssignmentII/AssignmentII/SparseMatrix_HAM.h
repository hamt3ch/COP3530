//
//  SparseMatrix_HAM.h
//  AssignmentII
//
//  Created by Hugh A. Miles on 9/25/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#ifndef SparseMatrix_HAM_h
#define SparseMatrix_HAM_h
using namespace std;
#include <vector>

template <class type>
class Node {
    public:
        int row;
        int col;
        type value;
        Node* nextNode;

        Node(type initValue) {  // constructor
            value = initValue; // set Node value
            nextNode = NULL;
        }
};

template <class type>
class LinkedList {
public:
    Node<type>* head;
    int length;

    LinkedList() { //constructor
        head = NULL;
        length = 0;
    }

    void append(type value, int row, int col) { // append to end of list
      if(head == NULL){
        head = new Node<type>(value);  // set initValue
        head->row = row;    // set row and col
        head->col = col;
      }

      else {
          Node<type>* xPtr = head;   // set pointer to head
          while (xPtr->nextNode) { // find lastNode
            xPtr = xPtr -> nextNode;
          }

          xPtr->nextNode = new Node<type>(value);
          xPtr->nextNode->row = row;    // set row and col
          xPtr->nextNode->col = col;
      }

      length++; // increase length
    }



    void print() {
      Node<type>* xPtr = head;   // set pointer to head
      while (xPtr->nextNode) { // find lastNode
          cout << xPtr->value << "-";
        xPtr = xPtr -> nextNode;
      }
    }
};

template<class type>
class SparseMatrix {
  public:
     int numOfRow; // size of matrix
     int numOfCol;
     LinkedList<type>** myRow; // array of rows

     SparseMatrix() { // constructor

     }

     void read() { // figure out matrix size and elements
        //read in size of matrix
        cout << "Enter number of rows, columns" << endl;
        cin >> numOfRow;
        cin >> numOfCol;

        // create the intial array of LinkedList and tag there col value
        myRow = new LinkedList<type>*[numOfRow]();
        for (int i  = 0; i < numOfRow; i++) {
            myRow[i] = new LinkedList<type>(); // create new list
        }

        int elements;
        int value;
        for (int i = 0; i < numOfRow; i++) {
            cout << "Enter number of terms/elements in row" << i << endl;
            cin >> elements;
            int rowIndex = i; // i represents the row
            int colIndex;

            cout << "Enter element's column, and value of each term in row" << i << endl;
            for (int j = 0; j < elements; j++) {
                  //cin >> colIndex;
                  //cin >> value;
                  //create new node to represent a spot in matrix
                  myRow[i]->append(555, i, j);
                }
            }
        }
      void print() {
          
          for(int i = 0; i < numOfRow; i++){
              Node<type>* ptrX = myRow[i]->head; // set pointer equal to head
              int count = 0; // set counter
              while (ptrX) {
                  cout << "[" << ptrX->row << "," << ptrX->col << "]";
                  ptrX = ptrX -> nextNode; // move to next Node
              }
              
              cout << endl;
          }
      }
  };




#endif /* SparseMatrix_HAM_h */
