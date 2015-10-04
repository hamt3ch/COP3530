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
          xPtr->row = row;    // set row and col
          xPtr->col = col;
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

// template<class t>
// class SparseMatrix {
//     LinkedList* row[3] = {};
//
// }




#endif /* SparseMatrix_HAM_h */
