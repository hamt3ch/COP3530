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

    arrayHeap* myHeap = new arrayHeap(10);
    for(int i = 10; i > 0; i--){
        myHeap->push(rand() % 100);
    }

    cout << "Tree" << endl;
    treeHeap<int>* myTree = new treeHeap<int>();
    myTree->push(10);
    myTree->print();

    // cout << "Array" << endl;
    // myHeap->print();


    //Testing Priority Queue
    // int test[10];
    // for(int i = 0; i < 10; i++){
    //     test[i] = myHeap->top();
    //     cout << test[i] << " ";
    //     myHeap->pop();
    // }
    //
    // for(int i = 0; i < 10; i++){
    //     if(test[i] > test[i+1] && i + 1 != 10){
    //         cout << "order is messed up at index" << i << endl;
    //     }
    // }

}
