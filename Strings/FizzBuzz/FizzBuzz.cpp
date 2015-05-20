//
//  FizzBuzz.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <iostream>
#include "FizzBuzz.h"

using std::cout; using std::endl;

bool fizz(int n) {
    return n % 3 == 0;
}

bool buzz(int n) {
    return n % 5 == 0;
}
/*
    Print all numbers from 1 to N
    Multiples of 3 : print Fizz
    Multiples of 5 : print Buzz
    Multiples of 3 and 5 : print FizzBuzz
 */
void print(int UpperRange) {
    for (int i = 1; i <= UpperRange; i++) {
        if (fizz(i) && buzz(i)) {
            cout << "FizzBuzz" << endl;
        }
        else if (fizz(i)) {
            cout << "Fizz" << endl;
        }
        else if (buzz(i)) {
            cout << "Buzz" << endl;
        }
    }
}