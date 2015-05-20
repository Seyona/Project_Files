//
//  FibSequence.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include "FibSequence.h"
#include <iostream>
using std::cout; using std::endl;
/*
 Fibonacci sequence to the Nth number.
 */
void fibSeqToNthTerm(int n) {
    int curr = 2;
    int num1 = 1;
    int num2 = 1;
    cout << "1, 1,";
    for (int i = curr; i < n; i++) {
        int temp = num1;
        num1 = num2;
        num2 = num1 + temp;
        cout << " " << num2;
        if (i != n -1) cout << ',';
    }
    cout << endl;
}