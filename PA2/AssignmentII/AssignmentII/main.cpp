//
//  main.cpp
//  AssignmentII
//
//  Created by Hugh A. Miles on 9/25/15.
//  Copyright © 2015 HAM. All rights reserved.
//

#include <fstream>
#include <iostream>
#include "SparseMatrix_HAM.h"

int main(int argc, const char * argv[]) {

    SparseMatrix<int>* maskedMatrix = new SparseMatrix<int>();
    SparseMatrix<int>* valueMatrix = new SparseMatrix<int>();
    SparseMatrix<bool>* boolMatrix = new SparseMatrix<bool>();

    valueMatrix->read(); // MatrixA.read

    valueMatrix->print(); // MatrixA.print

    boolMatrix->read(); // MatrixB.read

    boolMatrix->print(); // MatrixB.print

    valueMatrix->mask(maskedMatrix,boolMatrix); //conduct masking of A and B

    maskedMatrix->print(); // MatrixC.print

}
