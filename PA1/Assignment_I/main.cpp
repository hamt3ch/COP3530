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

    for(int i = 10; i > 0; i--){
        tstList->append(i);
        tstList->print();
    }
    tstList->print();
}
