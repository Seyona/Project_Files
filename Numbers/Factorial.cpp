//
//  Factorial.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include "Factorial.h"

int iterativeFact(int n) {
    int fact = n;
    for (int i = n-1; i > 1; i--) {
        fact = fact * i;
    }
    return fact;
}

int recursiveFact(int n) {
    if (n == 1) return n;
    return n * recursiveFact(n-1);
}
