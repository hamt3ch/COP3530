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

    arrayHeap* array = new arrayHeap(numOfMachines);     //instantiate structs
    treeHeap<Machine*> tree = *new ::treeHeap<Machine*>();
//    for (int i = 0; i < 10; i++){
//        Machine* t = new Machine(5); // create new Machine
//        //t->insert(rand()%100);
//        tree.push(t); // push newMachine in Heap
//    }
//    
//    tree.print();
//    
//    for (int i = 0; i < 10; i++){
//        cout << tree.top()->sum << " ";
//        tree.pop(); // push newMachine in Heap
//    }

    //Array Heap
    for (int i = 0; i < numOfMachines; i++){ //create machines
        Machine* t = new Machine(numOfJobs); // create new Machine
        array->push(t); // push newMachine in Heap
    }

    for (int i = 0; i < numOfJobs; i++) {
        Machine* readyToWork = array->top(); // get top machine
        readyToWork->insert(jobs[i]); // add job to it
        array->pop(); //pop it off
        array->push(readyToWork); // push it back in
    }

    array->print();
    
    //HeightBiased Leftist Tree
    for (int i = 0; i < numOfMachines; i++){ //create machines
        Machine* t = new Machine(numOfJobs); // create new Machine
        tree.push(t); // push newMachine in Heap
    }
    
    for (int i = 0; i < numOfJobs; i++) {
        Machine* readyToWork = tree.top(); // get top machine
        readyToWork->insert(jobs[i]); // add job to it
        tree.pop(); //pop it off
        tree.push(readyToWork); // push it back in
    }
    
    tree.print();

}
