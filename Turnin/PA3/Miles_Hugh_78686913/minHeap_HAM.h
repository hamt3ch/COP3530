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
//            //lvl1
//            root = new Node<type>(new Machine(10));
//            root->value->insert(1);
//
//            root->rightChild = new Node<type>(new Machine(10));
//            root->rightChild->value->insert(3);
//
//            root->leftChild = new Node<type>(new Machine(10));
//            root->leftChild->value->insert(2);
//
//            //lvl2
//            root->rightChild->rightChild = new Node<type>(new Machine(10));
//            root->rightChild->rightChild->value->insert(7);
//
//            root->rightChild->leftChild = new Node<type>(new Machine(10));
//            root->rightChild->leftChild->value->insert(6);
//
//            root->leftChild->rightChild = new Node<type>(new Machine(10));
//            root->leftChild->rightChild->value->insert(5);
//            root->leftChild->leftChild = new Node<type>(new Machine(10));
//            root->leftChild->leftChild->value->insert(4);
//
//            //lvl3
//            root->rightChild->rightChild->rightChild = new Node<type>(new Machine(10));
//            root->rightChild->rightChild->rightChild->value->insert(15);
//            root->rightChild->rightChild->leftChild = new Node<type>(new Machine(10));
//            root->rightChild->rightChild->leftChild->value->insert(14);
//
//            root->rightChild->leftChild->rightChild = new Node<type>(new Machine(10));
//            root->rightChild->leftChild->rightChild->value->insert(13);
//            root->rightChild->leftChild->leftChild = new Node<type>(new Machine(10));
//            root->rightChild->leftChild->leftChild->value->insert(12);
//
//            root->leftChild->rightChild->rightChild = new Node<type>(new Machine(10));
//            root->leftChild->rightChild->rightChild->value->insert(11);
//            root->leftChild->rightChild->leftChild = new Node<type>(new Machine(10));
//            root->leftChild->rightChild->leftChild->value->insert(10);
//
//            root->leftChild->leftChild->rightChild = new Node<type>(new Machine(10));
//            root->leftChild->leftChild->rightChild->value->insert(9);
//            root->leftChild->leftChild->leftChild = new Node<type>(new Machine(10));
//            root->leftChild->leftChild->leftChild->value->insert(8);

        }

    //add value to heap
    void push(type value){

    if(root == NULL){
            //create a root
            root = new Node<type>(value);
        }

    else if(root->value->sum > value->sum) { // root < value
            Node<type>* saveOldRoot = root; //save old tree
            root = new Node<type>(value);    // create newRoot
            root->leftChild = saveOldRoot; // place old Tree as right Node
        }

    else {
        //meld both currentTree w/ new Node
        Node<type>* toPush = new Node<type>(value);
        meld(root, toPush);
    }
}

    void pop(){
        Node<type>* toDelete = root;
        Node<type>* curRight = root->rightChild;
        Node<type>* curLeft = root->leftChild;

        //There are value in the tree
        if (root) {
            //root children exist
            if(curRight && curLeft){
                //check which is lest and set as root then meld
                if(root->rightChild->value->sum > root->leftChild->value->sum){
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

    void printSubTree(Node<type>* subRoot){
        //breadth-First Search
        int h = getHeight(subRoot);
        int i;
        for(i=1; i<=h; i++) {
            lvlOrder(subRoot, i);
            cout << endl;
        }
    }

private:
    void meld(Node<type>* currentRoot, Node<type>* toMeld){

        Node<type>* ptrX = currentRoot;

        //compare Node.values
        Node <type>* myParent; //saves parentNode when looking for spot to meld
        while(ptrX->value->sum <= toMeld->value->sum){ // traverse right side tree
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

    void checkRanks(Node<type>* root){ // checks if the currentChildren are in right order
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

    void swap(Node<type>* parent){
        Node<type>* save = parent->rightChild;
        parent->rightChild = parent->leftChild;
        parent->leftChild = save;
    }

    int getRank(Node<type>* node){
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

    void lvlOrder(Node<type>* root, int level){
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

    void machinelvlOrder(Node<type>* root, int level){
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

    int getHeight(Node<type>* node){
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
