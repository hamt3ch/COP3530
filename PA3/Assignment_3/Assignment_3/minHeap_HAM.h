//
//  minHeap_HAM.h
//  Assignment_3
//
//  Created by Hugh A. Miles on 10/25/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#ifndef minHeap_HAM_h
#define minHeap_HAM_h

#include <math.h>
using namespace std;
#define empty -1

template <class type>
class Node {
public:
    type value;
    Node* rightChild;
    Node* leftChild;

    //constructor
    Node(int initVal) {
        value = initVal;
    }
};

class arrayHeap {
    int length; // number of elements
    int* heap; // array of rows

public:
    // constructor
    arrayHeap(int size){
        heap = new int[size]; // instantiate heap
        length = 0;
    }

    //add element to heap
    void push(int toInsert){
        //insert element at the end of the list
        heap[length] = toInsert; //add to end of heap
        int curIndex = length; // index of the value just added{

        //make recursive call here to the heap
        compare(getParent(curIndex), curIndex);// swap values

        length++; // increase length
    }

    //recursive sort for insert
    void compare(int parentIndex, int childIndex){
        if(childIndex == 0){
            //there is no parentIndex
        }

        else if(heap[parentIndex] > heap[childIndex]){
            //swap values
            swap(parentIndex, childIndex);

            //check compare again
            compare(getParent(parentIndex),parentIndex);
        }
    }

    //fix head after a pop
    void reAlign(int parentIndex) {
        //check leftChild
        if(heap[parentIndex] > heap[getLeft(parentIndex)] && getLeft(parentIndex) < length){
            //swap values
            swap(parentIndex, getLeft(parentIndex));

            //check nodes below it
            reAlign(getLeft(parentIndex));
        }

        //check rightChild
        if(heap[parentIndex] > heap[getRight(parentIndex)] && getRight(parentIndex) < length){
            //swap values
            swap(parentIndex, getRight(parentIndex));
         //   print();

            //check nodes below it
            reAlign(getRight(parentIndex));
        }
    }

    //get minValue from heap
    int top(){
        return heap[0]; // return firstElement list >> minValue
    }

    //remove minValue from heap
    void pop(){
        //pull off top value
        heap[0] = empty;
      //  print();
        //take last value in heap an put it at the top
        swap(0, length - 1);
        //print();

        //decrease length
        length--;

        //compare with nodes below it
        reAlign(0);



    }

    //is the heap empty?
    bool isEmpty (){
        if(length) {
            return true;
        }
        else {
            return false;
        }
    }

    //get length
    int getLength(){
        return length;
    }

    void print(){
        int curlen = length;
        int i = 0;
        int n = 0;
        while (curlen > 0){
            int prints = pow(2, n++); // get number of prints
            for(int j = 0; j < prints; j++){
                if(i >= length){
                    break;
                }
                cout << " " << heap[i] << " ";
                i++;
                curlen--;

            }
            cout << endl;
            for(int j = 0; j < prints; j++){
                cout << " /" << "\\ " ;
            }
            //curlen -= prints;
            cout << endl; // break
        }

        cout << "----------" << endl;
    }

private:
    //getRightChild of current parent index
    int getRight(int index){
        return 2*index + 2; // represents leftChild
    }

    //getLeftChild of current parent index
    int getLeft(int index){
        return 2*index + 1; // represents rightChild
    }

    //getParent of currentChild index
    int getParent(int index) {
       return floor((index - 1)/2);
    }

    //swap indexOne with indexTwo
    void swap(int indexOne, int indexTwo){
        int save = heap[indexOne];
        heap[indexOne] = heap[indexTwo];
        heap[indexTwo] = save;
    }

};

class treeHeap {

    bool isEmpty;
    int size;
   // Node** heap; // array of rows

public:
    // constructor
    treeHeap(int size){
    //    heap = new Node*[size](); // instantiate heap
    }

    void push(int value){

    }

    void top(){

    }

    void pop(){

    }
};

#endif /* minHeap_HAM_h */
