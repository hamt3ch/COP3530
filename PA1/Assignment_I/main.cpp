//
//  main.cpp
//  Assignment_I
//
//  Created by Hugh A. Miles on 9/10/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include <iostream>
#include "CircularSingleLinkedList_HAM.hpp"

int main(int argc, const char * argv[]) {
    LinkedList* tstList = new LinkedList();

    for(int i = 1; i < 11; i++){
        tstList->append(i);
        tstList->resetIndexs();
    }

    cout << "////Insert 555 at index////" << endl;
    tstList->insert(555, 1);
    tstList->print();
    cout << "//////////////////////////" << endl;

    cout << endl;
    
    cout << "////Insert 1010 at front////" << endl;
    tstList->insert(1010, 0);
    tstList->print();
    cout << "//////////////////////////" << endl;
    
    cout << endl;

    cout << "////Insert 555 at back////" << endl;
    tstList->insert(333, 11);
    tstList->print();
    cout << "//////////////////////////" << endl;
    
    cout << endl;

}
