//
//  Exponents.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include "Exponents.h"

/*
    Return the produt of a^b in Lg N time
    Currently only works for Positive #'s
 */
int ExponentsInLgN(int a, int b) {
    int pow = 1;
    while (b) {
        if (b & 1) {
            pow = pow * a;
            --b;
        }
        a = a*a;
        b = b/2;
    }
    return pow;
}
