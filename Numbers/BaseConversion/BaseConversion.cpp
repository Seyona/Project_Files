//
//  BaseConversion.cpp
//  Projects
//
//  Created by David Baker on 5/19/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <sstream>
#include "BaseConversion.h"

int binaryToDecimal(string bin) {
    int len = (int)bin.size() - 1;
    int dec = 0;
    int exp = 0;

    for (int i = len; i >= 0; i--, exp++) {
        dec += (bin[i] % 48) << exp; //left shift
    }
    return dec;
}

string decimalToBinary(int deci) {
    string bin = "";
    string tmp = "";
    
    std::ostringstream str;
    while (deci > 0) {
        str << deci  % 2 ;
        deci = int(deci >> 1); //right shift
    }
    
    tmp += str.str();
    for (int i = (int)(tmp.size() - 1); i >=0; i--) {
        bin += tmp[i];
    }
    return bin;
}