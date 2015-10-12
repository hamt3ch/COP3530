//
//  SparseMatrix_HAM.h
//  AssignmentII
//
//  Created by Hugh A. Miles on 9/25/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#ifndef SparseMatrix_HAM_h
#define SparseMatrix_HAM_h

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

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

    Node<type> getNode(int col){    // find node with certain column value
        Node<type>* xPtr = head; // ptr = start of the list
        while (xPtr) {
            if(xPtr->col == col){ //found colNode in this list
                //return node
                return *xPtr;
            }
            xPtr = xPtr->nextNode;
        }

        return NULL;
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
     string name;
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
            int colIndex; // userTemp Variables

            cout << "Enter element's column, and value of each term in row" << i << endl;
            for (int j = 0; j < elements; j++) {
                  cin >> value;  // getUserValues()
                  cin >> colIndex;
                  //create new node to represent a spot in matrix
                  myRow[i]->append(colIndex, i+1, value);
                }
            }
        }

      void print() {
          cout << "rows = " << numOfRow << " columns = " << numOfCol << endl;
          for(int i = 0; i < numOfRow; i++){
              cout << "row " << i+1 << "[";
              Node<type>* ptrX = myRow[i]->head; // set pointer equal to head
              while (ptrX) {
                  cout << "col:" << ptrX->col << " value = " << ptrX->value;
                 // cout << "[" << ptrX->row << "," << ptrX->col << "]" << "{" << ptrX->value << "}" << " ";
                  ptrX = ptrX -> nextNode; // move to next Node
                  if(ptrX){ cout << " ,";}
              }
              cout << "]" << endl;
          }
      }

     void mask(SparseMatrix<type>* maskedMatrix, SparseMatrix<bool>* boolMatrix){

       //setup of newMatrix
       maskedMatrix->setRowLength(numOfRow);  //dynamically set MatrixC
       maskedMatrix->setColLength(numOfCol);  

       for (int i = 0; i < numOfRow; i++){
         LinkedList<bool>* boolList = boolMatrix->myRow[i]; //set pointers for comparison
         LinkedList<type>* valueList = myRow[i];
         Node<bool>* boolPtr = boolList->head;
         Node<type>* valuePtr = valueList->head;

         //compareLinks
         while(boolPtr){
           if(boolPtr->value){ // rowNode has valuePtr
               Node<type> temp = valueList->getNode(boolPtr->col); // find if boolNode is in valueList
                int tempCol = temp.col; //get values from node
                int tempVal = temp.value;

             //append value to List
             if(tempVal){
             maskedMatrix->myRow[i]->append(tempVal,i,tempCol);
           }
           }

            boolPtr = boolPtr->nextNode; // move to nextNode
         }
       }
     }

//Dynamic Functions
    void setRowLength(int maxRow){
        // create the intial array of LinkedList and tag there col value
        myRow = new LinkedList<int>*[maxRow]();
        numOfRow = maxRow;
        for (int i  = 0; i < numOfRow; i++) {
            myRow[i] = new LinkedList<type>(); // create new LinkList
        }
     }

   void setColLength(int maxCol){
        numOfCol = maxCol;
     }
  };

#endif /* SparseMatrix_HAM_h */
