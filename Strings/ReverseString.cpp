//
//  ReverseString.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <iostream>
#include "ReverseString.h"

char* reverse(char* x) {
    int length = (int)strlen(x);
    char* revStr = new char[length+1];
    for (int i = 0; i < length; i++) {
        revStr[i] = x[length-1-i];
    }
    revStr[length] = '\0';
    return revStr;
 }
