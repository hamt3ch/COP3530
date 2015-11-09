//
//  main.cpp
//  Assignment_3
//
//  Created by Hugh A. Miles on 10/23/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include <ctime>
#include <iostream>
#include <math.h>
#include "minHeap_HAM.h"

//protoTypes///////////////
void bubbleSort(int a[], int n);

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
    bubbleSort(jobs, numOfJobs);

    arrayHeap* array = new arrayHeap(numOfMachines);      //instantiate structs
    treeHeap<Machine*> tree = *new ::treeHeap<Machine*>();

    //Array Heap
    clock_t start = clock();
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
  
    cout << "Min Heap Finshing Time: " << array->getMax() << endl;
    cout << "Schedule:" << endl;
    array->print();
    
    clock_t end = clock();
    float time =  (float) (end-start) / CLOCKS_PER_SEC;
    
    cout << "Time Elapsed: " << time << endl;
    cout << endl;
    
    //HeightBiased Leftist Tree
    start = clock();
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
    
    //get max sum in tree
    treeHeap<Machine*> tempTree = *new ::treeHeap<Machine*>();
    int sum[numOfMachines];
    cout << "Height Biased Leftist Tree Finshing Time: ";
    for (int i = 0; i < numOfMachines; i++) {
        Machine* readyToWork = tree.top(); // get top machine
        tree.pop(); //pop it off
        sum[i] = readyToWork->sum; // save sum
        tempTree.push(readyToWork); // push it back in
    }
    
    //Get max sum in tree
    int max = sum[0];
    for(int i = 1; i < numOfMachines; i++){
        if(sum[i] > max){
            max = sum[i];
        }
    }
    cout << max << endl;
    
    //print Machines in tree
    cout << "Schedule:" << endl;
    for (int i = 0; i < numOfMachines; i++) {
        Machine* readyToWork = tempTree.top(); // get top machine
        tempTree.pop(); //pop it off
        
        cout << "Machine " << i+1 << ": ";
        readyToWork->print();
        tree.push(readyToWork); // push it back in
    }
    
    end = clock();
    
    time =  (float) (end-start) / CLOCKS_PER_SEC;
    
    cout << "Time Elapsed: " << time << endl;

}

void bubbleSort(int a[], int n){
    int temp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++){
            if(a[j]<a[j+1]){
                temp=a[j];
                a[j]=a[j+1];  /*Swap have been done here*/
                a[j+1]=temp;
            }    
        }     
    } 
}

