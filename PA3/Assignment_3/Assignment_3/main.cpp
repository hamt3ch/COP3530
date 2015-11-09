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

    int numOfJobs;
    int numOfMachines;

    cout << "Enter number of job(s)" << endl;
    cin >> numOfJobs;

    cout << "Enter number of machine(s)" << endl;
    cin >> numOfMachines;

    cout << "Enter Processing Time(s)" << endl;
    int jobs[numOfJobs];
    for (int i = 0; i < numOfJobs; i++){
        cin >> jobs[i];
    }

    //sort jobs in desceneding order

    //create Heap
    arrayHeap* myHeap = new arrayHeap(numOfMachines);

    //create machines
    for (int i = 0; i < numOfMachines; i++){
        Machine* t = new Machine(numOfJobs); // create new Machine
        myHeap->push(t); // push newMachine in Heap

    }

    for (int i = 0; i < numOfJobs; i++) {
        Machine* readyToWork = myHeap->top(); // get top machine
        readyToWork->insert(jobs[i]); // add job to it
        myHeap->pop(); //pop it off
        myHeap->push(readyToWork); // push it back in
    }

    myHeap->print();

//   cout << "Array" << endl;
//   arrayHeap* myHeap = new arrayHeap(10);
//   for(int i = 10; i > 0; i--){
//       Machine* t = new Machine(4);
//       t->insert(rand() % 100);
//
//       myHeap->push(t);
//
//   }
//    cout << "Starting Tree:" << endl;
//    myHeap->machinePrint();
//
//    //Testing Priority Queue
//   int test[10];
//   for(int i = 0; i < 10; i++){
//       test[i] = myHeap->top()->sum;
//       cout << test[i] << " ";
//       myHeap->pop();
//   }
//
//    for(int i = 0; i < 10; i++){
//        if(test[i] > test[i+1] && i + 1 != 10){
//            cout << "order is messed up at index" << i << endl;
//        }
//    }
}
