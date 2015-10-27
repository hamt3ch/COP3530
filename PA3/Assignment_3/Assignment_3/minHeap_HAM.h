//
//  minHeap_HAM.h
//  Assignment_3
//
//  Created by Hugh A. Miles on 10/25/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#ifndef minHeap_HAM_h
#define minHeap_HAM_h

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
    bool isEmpty;
    int size;
    Node** heap; // array of rows

public:
    // constructor
    arrayHeap(int size){
        heap = new Node*[size](); // instantiate heap
    }

    push(){

    }

    top(){

    }

    pop(){

    }


private:

};

class treeHeap {

    bool isEmpty;
    int size;
    Node** heap; // array of rows

public:
    // constructor
    arrayHeap(int size){
        heap = new Node*[size](); // instantiate heap
    }

    push(int value){

    }

    top(){

    }

    pop(){

    }
};

#endif /* minHeap_HAM_h */
