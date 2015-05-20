//
//  BaseConversionTest.cpp
//  Projects
//
//  Created by David Baker on 5/19/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "BaseConversion.h"

using std::cout; using std::endl;

bool binaryToDecTest() {
    bool pass = true;
    int i;
    for (i = 1; i <= 4; i++) {
        int expected = 0;
        int actual = 0;
        switch (i) {
            case 1:
                expected = 3;
                actual = binaryToDecimal("11");
                if (expected != actual) {
                    pass = false;
                    break;
                }
            case 2:
                expected = 150;
                actual = binaryToDecimal("10010110");
                if (expected != actual) {
                    pass = false;
                    break;
                }
            case 3: //does leading 0's fail the case
                expected = 1;
                actual = binaryToDecimal("000000000000000000001");
                if (expected != actual) {
                    pass = false;
                    break;
                }
            case 4: //will a bad input give me the correct answer
                expected = 2;
                actual = binaryToDecimal("1010");
                if (expected == actual) {
                    pass = false;
                    break;
                }
         }
        if (!pass) break;
    }
    
    if (!pass) cout << "Case " << i << " failed";
    return pass;
}

bool decimalToBinTest() {
    bool pass = true;
    int i;
    for (i = 1;i <= 4; i++) {
        string expected = "";
        string actual = "";
        switch (i) {
            case 1:
                expected = "11";
                actual = decimalToBinary(3);
                if (expected.compare(actual) != 0) {
                    pass = false;
                    break;
                }
            case 2:
                expected = "10010110";
                actual = decimalToBinary(150);
                if (expected.compare(actual) != 0) {
                    pass = false;
                    break;
                }
            case 3: // does leading 0's before integer mess things up
                expected = "1";
                actual = decimalToBinary(0000000000000001);
                if (expected.compare(actual) != 0) {
                    pass= false;
                    break;
                }
            case 4: //will a bad input give me the correct answer
                expected = "111";
                actual = decimalToBinary(9);
                if (expected.compare(actual) == 0) {
                    pass = false;
                    break;
                }
        }
        if (!pass) break;
    }
    return pass;
}