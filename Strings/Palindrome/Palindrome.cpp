//
//  Palindrome.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include "Palindrome.h"
//Reverse function is from ReverseString.cpp
bool isPalinDrome(char* x) {
    int index = 0;
    char* revStr = reverse(x);
    while (x[index] != '\0') {
        if (x[index] != revStr[index]) return false;
        ++index;
    }
    return true;
}