
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

    int numOfCommands;  // getNumberOfCommands
    cin >> numOfCommands;

    while(numOfCommands > 0)
    {
        string command;
        int index;
        int value;

        cin >> command;
        if(command.compare("I") == 0) { //parse commands from inputFile
            cin >> value;
            cin >> index;
            myList->insert(value, index);
        }

        else if(command.compare("D") == 0) {   // Delete at Index
            cin >> index;
            myList->deleteNode(index);
        }

        else if(command.compare("S") == 0) { // Print entire list
            myList->print();
        }

        else if(command.compare("P") == 0) { // Print at Index
            cin >> index;
            myList->printAtIndex(index);
        }

        else if(command.compare("J") == 0) { // Activate Josephus
            int jInsertions;
            int kToDelete;

            cin >> jInsertions;   //get amount of insertions
            cin >> kToDelete; // terms

            int count = 0;
            int temp;
            while (jInsertions > count) { // add josephus terms to front of list
                cin >> temp;
                myList->insert(temp, 0);
                count++;
            }

            myList->josephus(kToDelete); // Simulate josephus
        }

        else
        {
            cout << "Unknown Command" << endl;
        }

        numOfCommands--;
    }

    cout << endl;
}
