//
//  minHeap_HAM.h
//  Assignment_3
//
//  Created by Hugh A. Miles on 10/25/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#ifndef minHeap_HAM_h
#define minHeap_HAM_h

using namespace std;
#define empty -1

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
    int size(){
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

template <class type>
class Node {
public:
    type value;
    Node<type>* rightChild;
    Node<type>* leftChild;

    //constructor
    Node(type initVal) {
        value = initVal;
        rightChild = NULL;
        leftChild = NULL;
    }
};

template <class type>
class treeHeap {
    Node<type>* root;
    int length;

public:
    // constructor
    treeHeap(){
    root = NULL;

    //testing
       //lvl1
       root = new Node<type>(1);
       root->rightChild = new Node<type>(3);
       root->leftChild = new Node<type>(2);

       //lvl2
       root->rightChild->rightChild = new Node<type>(7);
       root->rightChild->leftChild = new Node<type>(6);

       root->leftChild->rightChild = new Node<type>(5);
       root->leftChild->leftChild = new Node<type>(4);
    }

    //add value to heap
    void push(int value){
        if(root == NULL){
            //create a root
            root = new Node<type>(value);
        }

        else {
            //meld both currentTree w/ new Node
        }
    }

    void pop(){

    }

    void print() {
        //breadth-First Search
        int h = getHeight(root);
        int i;
        for(i=1; i<=h; i++) {
            lvlOrder(root, i);
            cout << endl;
        }
    }

private:
    void meld(treeHeap<type>* current, treeHeap<type>* toMeld){

    }

    void postOrder(Node<type>* root, int level = 0){
        cout<< "lvl: " << level<< " " <<root->value << "\n";
        if(root != NULL){
            if(root->leftChild){
                cout << "left" << endl;
                postOrder(root->leftChild, level + 1);
            }

            if(root->rightChild){
                cout << "right" << endl;
                postOrder(root->rightChild, level + 1);
            }
        }
    }

    void lvlOrder(Node<type>* root, int level){
        if(root == NULL)
        return;

        if(level == 1)
        cout << root->value << " ";

        else if (level > 1)
        {
            lvlOrder(root->leftChild, level-1);
            lvlOrder(root->rightChild, level-1);
        }
    }

    int getHeight(Node<type>* node){
        if (node == NULL)
        return 0;
        else
        {
            /* compute the height of each subtree */
            int lheight = getHeight(node->leftChild);
            int rheight = getHeight(node->rightChild);

            /* use the larger one */
            if (lheight > rheight)
            return(lheight+1);
            else return(rheight+1);
        }
    }
};

#endif /* minHeap_HAM_h */
