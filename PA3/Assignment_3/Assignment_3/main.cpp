//
//  main.cpp
//  Assignment_3
//
//  Created by Hugh A. Miles on 10/23/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include <iostream>
#include <math.h>
#include "minHeap_HAM.h"

int main(int argc, const char * argv[]) {

//    cout << "Array" << endl;
//    arrayHeap* myHeap = new arrayHeap(10);
//    for(int i = 10; i > 0; i--){
//        myHeap->push(rand() % 100);
//    }

    cout << "Tree" << endl;
    treeHeap<int>* myTree = new treeHeap<int>();
    for(int i = 0; i < 10; i++){
        myTree->push(rand() % 100);
        myTree->print();
        cout << "----------" << endl;
    }

    // for (int i = 0; i < 10; i++){
    //     cout << myTree->top() << endl;
    //     myTree->pop();
    //     myTree->print();
    // }

   // myTree->print();


    //cout << myTree->top();

    // cout << "Array" << endl;
    // myHeap->print();


    //Testing Priority Queue
    int test[10];
    for(int i = 0; i < 10; i++){
        test[i] = myTree->top();
        cout << test[i] << " ";
        myTree->pop();
    }

    for(int i = 0; i < 10; i++){
        if(test[i] > test[i+1] && i + 1 != 10){
            cout << "order is messed up at index" << i << endl;
        }
    }

}
