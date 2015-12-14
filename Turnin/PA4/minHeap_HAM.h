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

class Machine {
public:
    int* log;
    int sum;
    int length;
    int max;
    
    Machine(int size){
        log = new int[size];
        sum = 0;
        length = 0;
        max = size;
    }
    
    ~Machine(){
        
    }
    
    void insert(int value){
        if(length <= max){
            //insert element at the end of the machine
            log[length] = value; //add to end of heap
            sum += value;
            length++; // increase length
        }
        
        else {
            cout << "No more room in machine" << endl;
        }
    }
    
    void print(){
        //cout << "Sum = " << sum << endl;
        //cout << "Log:";
        for(int i = 0; i < length; i++){
            cout << log[i];
            if(i < length - 1){
                cout << ",";
            }
        }
        cout << endl;
    }
};

class arrayHeap {
    int length;  // number of elements
    int max;
    int* heap;  // array of rows
    Machine** machineHeap; // array of Machines
    int sum; // sum of array
    
public:
    // constructor
    arrayHeap(int size){
        heap = new int[size];  // instantiate heap
        machineHeap = new Machine*[size]();
        length = 0;
        max = size;
    }
    
    ~arrayHeap(){
        
    }
    
    //add element to heap
    void push(Machine* toInsert){
        if(length <= max){
            machineHeap[length] = toInsert; //add machine to end of list
            int curIndex = length; // index of the value just added{
            
            //make recursive call here to the heap
            compare(getParent(curIndex), curIndex);// swap values
            
            length++; // increase length
        }
        
        else {
            cout << "No more room in heap" << endl;
        }
    }
    
    
    //recursive sort for insert
    void compare(int parentIndex, int childIndex) {
        if(childIndex == 0){
            //there is no parentIndex
        }
        
        else if(machineHeap[parentIndex]->sum > machineHeap[childIndex]->sum){
            //swap values
            swap(parentIndex, childIndex);
            
            //check compare again
            compare(getParent(parentIndex),parentIndex);
        }
    }
    
    //fix head after a pop
    void reAlign(int parentIndex) {
        if(machineHeap[parentIndex]){
            //check leftChild
            if(getLeft(parentIndex) < length && machineHeap[parentIndex]->sum > machineHeap[getLeft(parentIndex)]->sum){
                //swap values
                swap(parentIndex, getLeft(parentIndex));
                
                //check nodes below it
                reAlign(getLeft(parentIndex));
            }
            
            //check rightChild
            if(getRight(parentIndex) < length && machineHeap[parentIndex]->sum > machineHeap[getRight(parentIndex)]->sum){
                //swap values
                swap(parentIndex, getRight(parentIndex));
                
                //check nodes below it
                reAlign(getRight(parentIndex));
            }
        }
    }
    
    //get minValue from heap
    Machine* top(){
        return machineHeap[0];
    }
    
    //remove minValue from heap
    void pop(){
        //pull off top value
        machineHeap[0] = NULL;
        
        //take last value in heap an put it at the top
        swap(0, length - 1);
        
        //decrease length
        length--;
        
        //compare with nodes below it
        reAlign(0);
    }
    
    //is the heap empty?
    bool isEmpty (){
        if(length) {
            return false;
        }
        else {
            return true;
        }
    }
    
    //get length
    int size(){
        return length;
    }
    
    void printTree(){
        int curlen = length;
        int i = 0;
        int n = 0;
        while (curlen > 0){
            int prints = pow(2, n++); // get number of prints
            for(int j = 0; j < prints; j++){
                if(i >= length){
                    break;
                }
                cout << " " << machineHeap[i]->sum << " ";
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
    
    void print() {
        for (int i = 0; i < length; i++){
            cout << "Machine " << i+1 << ": ";
            machineHeap[i]->print();
        }
    }
    
    //find max in heap
    int getMax() {
        int max = machineHeap[0]->sum; // add job to it
        for (int i = 0; i < length; i++) {
            Machine* index = machineHeap[i]; // get top machine
            if(index->sum > max){
                max = index->sum;
            }
        }
        
        return max;
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
    
    void swap(int indexOne, int indexTwo){
        Machine* save = machineHeap[indexOne];
        machineHeap[indexOne] = machineHeap[indexTwo];
        machineHeap[indexTwo] = save;
    }
    
};

template <class type>
class treeNode {
public:
    type value;
    treeNode<type>* rightChild;
    treeNode<type>* leftChild;
    
    //constructor
    treeNode(type initVal) {
        value = initVal;
        rightChild = NULL;
        leftChild = NULL;
    }
    
    ~treeNode() {
        
    }
};

template <class type>
class treeHeap {
    treeNode<type>* root;
    int length;
    
public:
    // constructor
    treeHeap(){
        root = NULL;
    }
    
    ~treeHeap(){
        
    }
    
    //add value to heap
    void push(type value){
        
        if(root == NULL){
            //create a root
            root = new treeNode<type>(value);
        }
        
        else if(root->value->getWeight() > value->getWeight()) { // root < value
            treeNode<type>* saveOldRoot = root; //save old tree
            root = new treeNode<type>(value);    // create newRoot
            root->leftChild = saveOldRoot; // place old Tree as right Node
        }
        
        else {
            //meld both currentTree w/ new Node
            treeNode<type>* toPush = new treeNode<type>(value);
            meld(root, toPush);
        }
    }
    
    void pop(){
        treeNode<type>* toDelete = root;
        treeNode<type>* curRight = root->rightChild;
        treeNode<type>* curLeft = root->leftChild;
        
        //There are value in the tree
        if (root) {
            //root children exist
            if(curRight && curLeft){
                //check which is lest and set as root then meld
                if(root->rightChild->value->getWeight() > root->leftChild->value->getWeight()){
                    root = curLeft;
                    meld(root,curRight);
                }
                
                else {
                    root = curRight;
                    meld(root,curLeft);
                }
                
                // remove root
                delete toDelete;
            }
            
            //noRightChild but there is a Left
            else if(!curRight && curLeft) {
                root = curLeft; //leftist tree bias no need to checkout left
            }
        }
        
        //Empty Tree
        else{
            cout << "Tree has no values in it" << endl;
        }
        
    }
    
    type top() {
        return root->value;
    }
    
    void print() {
        //breadth-First Search
        int h = getHeight(root);
        int i;
        for(i=1; i<=h; i++) {
            machinelvlOrder(root, i);
            cout << endl;
        }
    }
    
    void printTree() {
        //breadth-First Search
        int h = getHeight(root);
        int i;
        for(i=1; i<=h; i++) {
            lvlOrder(root, i);
            cout << endl;
        }
    }
    
    void printSubTree(treeNode<type>* subRoot){
        //breadth-First Search
        int h = getHeight(subRoot);
        int i;
        for(i=1; i<=h; i++) {
            lvlOrder(subRoot, i);
            cout << endl;
        }
    }
    
private:
    void meld(treeNode<type>* currentRoot, treeNode<type>* toMeld){
        
        treeNode<type>* ptrX = currentRoot;
        
        //compare Node.values
        treeNode <type>* myParent; //saves parentNode when looking for spot to meld
        while(ptrX->value->getWeight() <= toMeld->value->getWeight()){ // traverse right side tree
            myParent = ptrX;
            ptrX = ptrX->rightChild;
            if (!ptrX){
                break;
            }
        }
        
        //place nodeHere
        myParent->rightChild = toMeld;
        
        //checkRank and see if a swap is need (leftist)
        checkRanks(root);
        
        if(ptrX == NULL){ //the tree is complete
            return;
        }
        
        else {
            //call meld on detached node
            meld(root,ptrX);
        }
    }
    
    void checkRanks(treeNode<type>* root){ // checks if the currentChildren are in right order
        if(root){
            //rank(L) > rank(R)
            if(getRank(root->leftChild) < getRank(root->rightChild)){
                //swap the Nodes
                swap(root);
            }
            
            checkRanks(root->leftChild);    //check the rest of tree
            checkRanks(root->rightChild);
        }
        
        else {
            return; // nothing to see
        }
    }
    
    void swap(treeNode<type>* parent){
        treeNode<type>* save = parent->rightChild;
        parent->rightChild = parent->leftChild;
        parent->leftChild = save;
    }
    
    int getRank(treeNode<type>* node){
        if(node) { // part of tree
            if(node->rightChild && node->leftChild){
                int leftRank = getRank(node->leftChild); // getChildrenRank
                int rightRank = getRank(node->rightChild);
                int childrenRank = (leftRank > rightRank) ? leftRank : rightRank;
                return 1 + childrenRank;
            }
            
            else { // this node is connected to a null
                return 1;
            }
        }
        
        else {  //NULL Node
            return 0;
        }
    }
    
    void lvlOrder(treeNode<type>* root, int level){
        if(root == NULL){
            cout << " - ";
            return;
        }
        
        if(level == 1){
            cout << "[" << root->value->sum << "]" << " ";
        }
        
        else if (level > 1)
        {
            lvlOrder(root->leftChild, level-1);
            lvlOrder(root->rightChild, level-1);
        }
    }
    
    void machinelvlOrder(treeNode<type>* root, int level){
        if(root == NULL){
            cout << " - ";
            return;
        }
        
        if(level == 1){
            root->value->print();
        }
        
        else if (level > 1)
        {
            machinelvlOrder(root->leftChild, level-1);
            machinelvlOrder(root->rightChild, level-1);
        }
    }
    
    int getHeight(treeNode<type>* node){
        if (node == NULL)
            return 0;
        
        else {
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
