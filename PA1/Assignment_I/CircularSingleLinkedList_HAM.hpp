
//
//  CircularSingleLinkedList_HAM.hpp
//  Assignment_I
//
//  Created by Hugh A. Miles on 9/10/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#ifndef CircularSingleLinkedList_HAM_hpp
#define CircularSingleLinkedList_HAM_hpp

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//template <class type>

class Node {
  public:
      int index;
      int value;
      Node* nextNode;
      bool isHead;
      bool isTail;

      Node(int initVal, int strIndex) { // constructor
          index = strIndex;
          value = initVal;
          nextNode = NULL;
          isHead = false;
      }
};

class LinkedList {
  public:
    Node* head;
    int curLength;

    LinkedList() { // constructor
      head = NULL;
      curLength = 0;
    }

    void insert (int value, int newIndex) {
      //index is out of range
      if(newIndex > curLength) {
          
          int tempLength = curLength;
        for (int i = 0; i <= newIndex - tempLength; i++) {
              append(NULL); // add empty nodes
        }

        Node* ptrX = head; //  ptrX = head

        while(!ptrX->nextNode->isHead) { //goto lastNode
          ptrX = ptrX->nextNode; // move to next node
        }

        ptrX -> value = value; // set value in append

      }
      //index already exist
      else {

      }

    }

    //Helper Methods
    void append(int value){  // add new element to end of list
      if(head == NULL) { //start of list
        head = new Node(value, 0);
        head->isHead = true;
        head->nextNode = head; // set nextNode to itself
      }

      else { //head already exist
        Node* ptrX = head->nextNode; //set index pointer to next Node

        if(ptrX->isHead){ // one Node in List
            head->nextNode = new Node(value,1); // create new node right after HEAD
            ptrX = head->nextNode;  // ptrX = new Node
            ptrX->nextNode = head; // set nextNode = head
        }

        else { //multiple nodes List
            int lastNodeIndex;
            while (!ptrX->nextNode->isHead){ //check if end of LinkedList
                ptrX = ptrX->nextNode; //move to nextNode

            }
            lastNodeIndex = ptrX->index + 1 ; // save last node Index


            ptrX->nextNode = new Node(value, lastNodeIndex); // create new Node and set index value

            Node* endNode = ptrX->nextNode; // set endNode value
            endNode -> nextNode = head; // set endNode.Next >> head
        }
      }

        curLength++; // increase length

    }

    //Print List
    void print (void) {
      cout << "head" << "--" << head->value << "--";  // print head intially
      Node* xPtr = head->nextNode;

      while(!xPtr->isHead) { // print Node.value till comeback to head
          if(xPtr->value) {
              cout << xPtr->value << "--";
          }

          else {
              cout << "Empty" << "--";
          }

          xPtr = xPtr->nextNode;

      }
        cout << "end" << endl;

        cout << "<index>" << endl;

        cout << "head" << "--" << head->index << "--";  // print head intially
        xPtr = head->nextNode;

        while(!xPtr->isHead) { // print Node.value till comeback to head
            cout << xPtr->index << "--";
            xPtr = xPtr->nextNode;
        }

        cout << "end" << endl;

        cout << "length:" << curLength << endl;
    }

};

#endif /* CircularSingleLinkedList_HAM_hpp */
