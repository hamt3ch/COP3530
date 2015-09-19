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

    ~LinkedList(){} //deconstructor

    void insert (int value, int newIndex) {
      //index is out of range
      if(newIndex > curLength + 1) {

          cout << "Out of Range for Insert" << endl;

      }

      //index already exist
      else {

        //insert at beginning
        if(newIndex == 0)
        {
            append(value); // add new node end of list
            Node* tail = getTail(); // set that value to Head
            head = tail;
            head -> isHead = true;
            head -> nextNode -> isHead = false; // reset isHead;

        }

       //insert at end
        else if(newIndex == curLength)
        {
            append(value); // just add to end of the list
        }

        else {
            //insert index > 0 < curLength
            Node* ptrX = head -> nextNode; //  X = Runner
            Node* ptrZ = head;              // z = Follower

            while (ptrX -> index != newIndex) // find place toInsert
            {
                ptrZ = ptrX;    //set follower to previousRunner
                ptrX = ptrX -> nextNode;    // set runner to nextNode over
            }

            placeNode(ptrX, ptrZ, value); // placeNode in current list
        }
      }
        resetIndexs(); // format newList
    }

    //Helper Methods

    //insert.atEnd >> case for adding nodes at the end of list
    void append(int value){
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

    //insert.placeNode >> helps insert into current list
    void placeNode(Node* runner, Node* follower, int value) { // places node into list
        Node* newNode = new Node(value, runner->index); //create new Node

        newNode->nextNode = runner; // set newNode >> bottomHalf of List

        follower->nextNode = newNode; // set topHalf of list >> newNode

        Node* ptrX = runner; //set indexPtr = runner
        int newIndex = runner->index++; // inc old runner

        //fix index
        while (!ptrX->isHead) {
            ptrX->index = ++newIndex; // set new indexs for remaining list
            ptrX = ptrX -> nextNode;
        }
        
        curLength++; // increment length

    }

    Node* getTail(void) {

        Node* ptrX = head->nextNode; // start at head
        while (!ptrX
               ->nextNode->isHead) {
            ptrX = ptrX->nextNode; // move thru list
        }

        return ptrX;
    }

    void resetIndexs (void) { // fix index in list
        Node* ptrX = head; // start at head
        int newIndex = 0;
        do
        {
            ptrX -> index = newIndex++;
            ptrX = ptrX -> nextNode; // move to next node
        } while (!ptrX->isHead);

        curLength = ++newIndex;
    }

    //Print List
    void print (void) {
      cout << "head" << "--";  // print head intially
      Node* ptrX = head;
      do
       { // print Node.value till comeback to head
          if(ptrX->value) {
              cout << ptrX->value << "--";
          }

          else {
              cout << "Empty" << "--";
          }

          ptrX = ptrX->nextNode;

       } while(!ptrX->isHead);

        cout << "end" << endl;

        cout << "<index>" << endl;
        ptrX = head;
        do
        { // print Node.value till comeback to head
            if(ptrX->value) {
                cout << ptrX->index << "--";
            }

            else {
                cout << "Empty" << "--";
            }

            ptrX = ptrX->nextNode;

        } while(!ptrX->isHead);


        cout << "end" << endl;

        cout << "length:" << curLength << endl;
    }

    void printAtIndex(int indexToPrint) {
        Node* ptrX = head; // start at head
        while (ptrX->index != indexToPrint){
            ptrX = ptrX -> nextNode; // move thru list till index is found
        }

        cout << "element at index: " << indexToPrint << " = " << ptrX->value << endl;
    }

};

#endif /* CircularSingleLinkedList_HAM_hpp */
