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

template <class type>
class Node {
  public:
      int index;
      type value;
      Node<type> *nextNode;
      bool isHead;

      Node(int initVal, int strIndex) { // constructor
          index = strIndex;
          value = initVal;
          nextNode = NULL;
          isHead = false;
      }
};


template<class t>
class LinkedList {
  public:
    Node<t> *head;
    int curLength;

    LinkedList() { // constructor
      head = NULL;
      curLength = 0;
    }

    ~LinkedList(){ //destructor
        Node<t> *myPtr = head;
        Node<t> *temp;
        while(myPtr != NULL) {
            temp = myPtr->nextNode;
            delete myPtr;
            myPtr = temp;
        }
    }
    
    void insert (t value, int newIndex) {
      //index is out of range
      if(newIndex > curLength + 1) {

          cout << "Insert.newIndex is out of range" << endl;
        

      }

      //index already exist
      else {

        //insert at beginning
        if(newIndex == 0)
        {
            append(value); // add new node end of list
            Node<t> *tail = getTail(); // set that value to Head
            head = tail;
            head -> nextNode -> isHead = false; // reset isHead;
            head -> isHead = true;
        }

       //insert at end
        else if(newIndex == curLength || newIndex == curLength + 1)
        {
            append(value); // just add to end of the list
        }

        else {
            //insert index > 0 < curLength
            Node<t> *ptrX = head -> nextNode; //  X = Runner
            Node<t> *ptrZ = head;              // z = Follower

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
    
    //delete Node ar index
    void deleteNode(int indexToDelete) {
        
        Node<t> *runner = head;
        Node<t>* follower;
        
        if(curLength == 1 && indexToDelete == 0) {
            curLength = 0; // reset list
            head = NULL;
            return;
        }
        
        if(indexToDelete >= curLength) { //check if user input is valid
            cout << "deleteNode.indexToDelete is out of range" << endl;
        }
        
        
        else {
            
            //delete index0 = head
            if(indexToDelete == 0) {
                runner = head;
                follower = getTail(); // get lastNode
                
                Node<t> *rightNode = runner->nextNode;
                Node<t> *leftNode = follower;
                
                leftNode->nextNode = rightNode;
                rightNode->isHead = true;
                
                delete runner;
                
                head = rightNode;
                
            }
            
            //delete !index0
            else {
                while (runner->index != indexToDelete) { // find nodeToDelete
                    follower = runner; // set follower to old runner
                    runner = runner->nextNode; // move to nextNode
                }
                
                Node<t> *rightNode = runner->nextNode;
                Node<t> *leftNode = follower;
                
                leftNode->nextNode = rightNode;
                
                delete runner;
            }
        }
    
        resetIndexs(); // reformat list
    }

    //Helper Methods

    //insert.atEnd >> case for adding nodes at the end of list
    void append(t value){
      if(head == NULL) { //start of list
        head = new Node<t>(value, 0);
        head->isHead = true;
        head->nextNode = head; // set nextNode to itself
      }

      else { //head already exist
        Node<t> *ptrX = head->nextNode; //set index pointer to next Node

        if(ptrX->isHead){ // one Node in List
            head->nextNode = new Node<t>(value,1); // create new node right after HEAD
            ptrX = head->nextNode;  // ptrX = new Node
            ptrX->nextNode = head; // set nextNode = head
        }

        else { //multiple nodes List
            int lastNodeIndex;
            while (!ptrX->nextNode->isHead){ //check if end of LinkedList
                ptrX = ptrX->nextNode; //move to nextNode

            }
            
            lastNodeIndex = ptrX->index + 1 ; // save last node Index

            ptrX->nextNode = new Node<t>(value, lastNodeIndex); // create new Node and set index value

            Node<t>* endNode = ptrX->nextNode; // set endNode value
            endNode -> nextNode = head; // set endNode.Next >> head
        }
      }

        curLength++; // increase length

    }

    //insert.placeNode >> helps insert into current list
    void placeNode(Node<t>* runner, Node<t>* follower, t value) { // places node into list
        Node<t>* newNode = new Node<t>(value, runner->index); //create new Node

        newNode->nextNode = runner; // set newNode >> bottomHalf of List

        follower->nextNode = newNode; // set topHalf of list >> newNode

        Node<t>* ptrX = runner; //set indexPtr = runner
        int newIndex = runner->index++; // inc old runner

        //fix index
        while (!ptrX->isHead) {
            ptrX->index = ++newIndex; // set new indexs for remaining list
            ptrX = ptrX -> nextNode;
        }

        curLength++; // increment length

    }

    //findLastNode
    Node<t>* getTail(void) {

        Node<t>* ptrX = head->nextNode; // start at head
        while (!ptrX
               ->nextNode->isHead) {
            ptrX = ptrX->nextNode; // move thru list
        }

        return ptrX;
    }

    void resetIndexs (void) { // fix index in list
        Node<t>* ptrX = head; // start at head
        int newIndex = 0;
        
        do
        {
            ptrX -> index = newIndex++;
            ptrX = ptrX -> nextNode; // move to next node
        } while (!ptrX->isHead);

        curLength = newIndex;
    }

    //Print List
    void print (void) {
      Node<t>* ptrX = head;
      
      if (head == NULL) {
            cout << "List is Empty" << endl;
          return;
      }
       
      cout << "[";  // print head intially
        
      do
       { // print Node.value till comeback to head
          cout << ptrX->value;

          if(ptrX->nextNode->isHead) // at the last Node
          {
              cout << "]";
              break;
          }
           
          cout << ",";

          ptrX = ptrX->nextNode;

       } while(!ptrX->isHead);
        
        cout << endl;
    }

    void printAtIndex(int indexToPrint) {
        Node<t>* ptrX = head; // start at head
        int count = 0;
        
        while (count != indexToPrint){
            ptrX = ptrX -> nextNode; // move thru list till index is found
            count++;
        }

        cout << ptrX->value << endl;
    }
    
    void josephus(int k) { //playing the game
        
        if (head) {
        Node<t>* delPtr = head; // start at head
        Node<t>* tempPtr;
        int count = 1;
        cout << "[";
        while (curLength > 1) {
            tempPtr = delPtr->nextNode; // save nextNode over
            if(count == k)
            {  //delete this Node
                cout << delPtr->value << ",";
                deleteNode(delPtr->index); //delete this Node
                count = 0; // reset count
            }
            
            count++;
            delPtr = tempPtr; // move to nextNode
        }
        
        //lastNode
        cout << tempPtr->value << "]";
        delete tempPtr; // delete lastNode
        }
    }

};

#endif /* CircularSingleLinkedList_HAM_hpp */
