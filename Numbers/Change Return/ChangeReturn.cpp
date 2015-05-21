//
//  ChangeReturn.cpp
//  Projects
//
//  Created by David Baker on 5/21/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <stdlib.h>
#include "ChangeReturn.h"

using std::string;


/*
    Return the change of the given amount
    Will be in units of Quarters, Dimes, Nickels, and Pennies
    Input is a string 
        Note: Values past 2 decmial points will be ignored
    Output is a set of int pointers 
        int[0] is Quarters
        int[1] is Dimes
        int[2] is Nickels
        int[3] is Pennies
 */
int* returnChange(string cash) {
    double cash_money = std::stod(cash);;
    return returnChange(cash_money);
}

/*
    Return the change of the given amount
    Will be in units of Quarters, Dimes, Nickels, and Pennies
    Input is a Double
        Note: values past 2 decimal points will be ignored
    Output is a set of int pointers
        int[0] is Quarters
        int[1] is Dimes
        int[2] is Nickels
        int[3] is Pennies
 */
int* returnChange (double cash) {
    cash *= 100; //moves decimal to places to the right
    return returnChange((int)cash);
}

/* 
    Return the change of the given amount
    Will be in units of Quarters, Dimes, Nickels, and Pennies
    Input : an Integer
    Output is a set of int pointers
        int[0] is Quarters
        int[1] is Dimes
        int[2] is Nickels
        int[3] is Pennies
 */
int* returnChange(int cash) {
    int* cash_out = new int[4];
    
    // Quarters
    cash_out[0] = cash / 25;
    cash %= 25;
    
    // Dimes
    cash_out[1] = cash / 10;
    cash %= 10;
    
    // Nickels
    cash_out[2] = cash / 5;
    cash %= 5;
    
    // Pennies
    cash_out[3] = cash;
    cash %= 1;
    
    return cash_out;
}



