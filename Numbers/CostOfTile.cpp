//
//  CostOfTile.cpp
//  MiniProjects
//
//  Created by David Baker on 5/19/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

#include "CostOfTile.h"

std::string to_string(double x);

/*
    Calculate the needed amount of cash for a (W*L) floor plan with X cost
    Cost is assumed to be amount per measure of thier type 
    If using feet it is assumed cost is x dollars/euros per sq foot
    If using meters it is assumed cost is x dollars/euros per sq meter
    Precision is given to 3 decimal places
 */
char* costOfTile(double cost, double length, double width) {
    
    
    double squareFeet = length * width;
    double totalCost = squareFeet * cost;
    
    std::string costStr = to_string(totalCost);
    
    std::string strBeforeDeci = "";
    std::string strAfterDeci = "";
    
    int precisionAfterDecimal = 0;
    bool pastDecimal = false;
    
    for (auto &c : costStr) {
        if (!pastDecimal) {
            if (c != '.') {
                strBeforeDeci += c;
            }
            else {
                pastDecimal = true;
            }
        } else {
            if (precisionAfterDecimal != 3) {
                strAfterDeci += c;
                precisionAfterDecimal++;
            }
            else {
                break;
            }
        }
    }
    
    int totalSize = (int)(strAfterDeci.size() + strBeforeDeci.size());
    char* costOut = new char[totalSize+2]; //need space for decimal and \0
    
    int index = 0;
    for (auto &c : strBeforeDeci) {
        costOut[index] = c;
        index++;
    }
    costOut[index++] = '.'; // Does this do what i think it does?
    for (auto &c : strAfterDeci) {
        costOut[index] = c;
        index++;
    }
    costOut[totalSize+1] = '\0';
    return costOut;
}

std::string to_string(double x) {
    std::ostringstream ss;
    ss << x;
    return ss.str();
}