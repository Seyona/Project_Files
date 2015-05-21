//
//  HappyNumbers.cpp
//  Projects
//
//  Created by David Baker on 5/20/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "HappyNumbers.h"

using std::cout; using std::endl;
using std::string;

string to_string (int x);
string happySum (string num);

/*
 A happy number is defined by the following process. Starting with any positive 
 integer, replace the number by the sum of the squares of its digits, and repeat 
 the process until the number equals 1 (where it will stay), or it loops 
 endlessly in a cycle which does not include 1. Those numbers for which this
 process ends in 1 are happy numbers, while those that do not end in 1 are 
 unhappy numbers.
*/

void happyNums() {
    int happy[8];
    happy[0] = 1;
    
    int index_of_happy = 1;
    for (int i = 2; i < 1001; i++) {
        
        bool isHappy = false;
        int tries = 0;
        string happy_test(to_string(i));
        
        while (!isHappy && tries < 5) {
            string poss_happy = happySum(happy_test);
            bool sizeIsOne = poss_happy.length() == 1;
            isHappy = sizeIsOne && poss_happy[0] == '1';
            happy_test = poss_happy;
            tries++;
        }
        if (isHappy && index_of_happy < 8) {
            //cout << i << " ";
            happy[index_of_happy] = i;
            index_of_happy++;
        }
    }
    
    for (auto &c : happy) {
        cout << c << " ";
    }
}

//Sums the digits, returns sum
string happySum(string num) {
    int sum = 0;
    for (auto c : num) {
        int number = c - 48;
        sum += (number * number);
    }
    return to_string(sum);
}

string to_string(int x) {
    std::ostringstream ss;
    ss << x;
    return ss.str();
}
