
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

int main(int argc, char * argv[]) {
    LinkedList<int>* myList = new LinkedList<int>();

    //cout << argv[1] << endl;
    
    ifstream inputFile;
    inputFile.open(argv[1]); // argv[1] = userInput.txt
    
    if(inputFile.fail()){  //indicate file is not able to be read
        cerr << "Error opening file" << endl;
        exit(1);
    }
    
    int numOfCommands;  // getNumberOfCommands
    inputFile >> numOfCommands;
    
    while(inputFile.good() && numOfCommands > 0)
    {
        string command;
        int index;
        int value;
        
        inputFile >> command;
        if(command.compare("I") == 0) { //parse commands from inputFile
            inputFile >> value;
            inputFile >> index;
            myList->insert(value, index);
        }
        
        else if(command.compare("D") == 0) {   // Delete at Index
            inputFile >> index;
            myList->deleteNode(index);
        }
        
        else if(command.compare("S") == 0) { // Print entire list
            myList->print();
        }
        
        else if(command.compare("P") == 0) { // Print at Index
            inputFile >> index;
            myList->printAtIndex(index);
        }
                
        else if(command.compare("J") == 0) { // Activate Josephus
            int jInsertions;
            int kToDelete;
            
            inputFile >> jInsertions;   //get amount of insertions
            inputFile >> kToDelete; // terms
            
            int count = 0;
            int temp;
            while (jInsertions > count) { // add josephus terms to front of list
                inputFile >> temp;
                myList->insert(temp, 0);
                count++;
            }
            myList->print();
            myList->josephus(kToDelete);
        
        }
        
        else
        {
            cout << "Unknown Command" << endl;
        }
        
        numOfCommands--;
    }
    
    cout << endl << "<<<<EOP>>>>" << endl;
    
}
