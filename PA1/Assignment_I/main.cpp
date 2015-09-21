//
//  main.cpp
//  Assignment_I
//
//  Created by Hugh A. Miles on 9/10/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include <fstream>
#include <iostream>
#include "CircularSingleLinkedList_HAM.hpp"

int main(int argc, const char * argv[]) {
    LinkedList* myList = new LinkedList();

    ifstream inputFile;
    inputFile.open("input.txt");
    
    if(inputFile.fail()){  //indicate file is not able to be read
        cerr << "Error opening file" << endl;
        exit(1);
    }
    
    int numOfCommands;  // getNumberOfCommands
    inputFile >> numOfCommands;
    cout << "Number of Commands:" << numOfCommands << endl;
    
    while(inputFile.good() && numOfCommands > 0)
    {
        string command;
        int index;
        int value;
        
        inputFile >> command;
        if(command.compare("I") == 0) { //parse commands from inputFile
            inputFile >> value;
            inputFile >> index;
            cout << "Insert " << value << " at " << index << endl;
           myList->insert(value, index);
        }
        
        else if(command.compare("D") == 0) {   // Delete at Index
            inputFile >> index;
            cout << "Delete element at "<< index << endl;
            myList->deleteNode(index);
        }
        
        else if(command.compare("S") == 0) { // Print entire list
            cout << "Print entire list" << endl;
            myList->print();
        }
        
        else if(command.compare("P") == 0) { // Print at Index
            inputFile >> index;
            cout << "Print element at " << index << endl;
            myList->printAtIndex(index);
        }
                
        else if(command.compare("J") == 0) { // Activate Josephus
            cout << "Start Josephus" << endl;
        }
        
        else
        {
            cout << "Unknown Command" << endl;
        }
        
        numOfCommands--;
    }
    
    cout << "end of program" << endl;
}
