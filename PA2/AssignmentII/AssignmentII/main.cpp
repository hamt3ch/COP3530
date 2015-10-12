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
	
	SparseMatrix<int>* valueMatrix = new SparseMatrix<int>(); // MatrixA
    SparseMatrix<bool>* boolMatrix = new SparseMatrix<bool>(); //MatrixB
    SparseMatrix<int>* maskedMatrix = new SparseMatrix<int>(); // MatrixC
    
    cout << "Reading Matrix A" << endl;
    valueMatrix->read(); // MatrixA.read

    cout << "Matrix A, result:" << endl;
    valueMatrix->print(); // MatrixA.print

    cout << "Reading Matrix B" << endl;
    boolMatrix->read(); // MatrixB.read

    cout << "Matrix B, result:" << endl;
    boolMatrix->print(); // MatrixB.print

    //Masking
    valueMatrix->mask(maskedMatrix,boolMatrix);

    cout << "Matrix C, result:" << endl;
    maskedMatrix->print(); // print matrix

}
