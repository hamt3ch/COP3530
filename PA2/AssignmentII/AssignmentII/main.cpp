




//
//  main.cpp
//  AssignmentII
//
//  Created by Hugh A. Miles on 9/25/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include <iostream>
#include "SparseMatrix_HAM.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
//    LinkedList<int>* myList = new LinkedList<int>();
//    for (int i = 0; i < 10; i++) {
//        myList->append(i,0,0);
//    }
//    myList->print();
    
    
    SparseMatrix<int>* myMatrix = new SparseMatrix<int>();
    myMatrix->read();

}
