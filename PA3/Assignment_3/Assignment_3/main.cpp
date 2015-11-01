//
//  main.cpp
//  Assignment_3
//
//  Created by Hugh A. Miles on 10/23/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include <iostream>
#include "minHeap_HAM.h"

int main(int argc, const char * argv[]) {

    arrayHeap* myHeap = new arrayHeap(10);
    for(int i = 10; i > 0; i--){
        myHeap->push(i);
    }

    myHeap->print();
}
