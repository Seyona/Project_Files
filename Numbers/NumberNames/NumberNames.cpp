d//
//  NumberNames.cpp
//  MiniProjects
//
//  Created by David Baker on 5/19/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include "NumberNames.h"

std::string oneDigit(std::string num);
std::string twoDigit(std::string num);
std::string threeDigit(std::string num);
std::string fourDigit(std::string num);
std::string fiveDigit(std::string num);
std::string sixDigit(std::string num);
std::string sevenDigit(std::string num);

std::string to_string(int x);
/*
    Gives a given integer its proper english name
    Ex: 
        Input : 1100124
        Output : one million one-hundread thousand one-hundread and twenty four
 
    Supports both positive and negative integers
 
 */
char* numberName(int num) {
    std::string number = to_string(num);
    
   
    
    int stringSize = (int)number.length();
    
    if (stringSize > 7) {
        std::string str = "to long";
        auto out = new char[str.length() + 1];
        strcpy(out, str.c_str());
        return out;
    }
    
    bool negative = false;
    if (number[0] == '-') {
        negative= true;
        stringSize--;
    }
    
    std::string name;
    if (stringSize == 1) name = oneDigit(number);
    if (stringSize == 2) name = twoDigit(number);
    if (stringSize == 3) name = threeDigit(number);
    if (stringSize == 4) name = fourDigit(number);
    if (stringSize == 5) name = fiveDigit(number);
    if (stringSize == 6) name = sixDigit(number);
    if (stringSize == 7) name = sevenDigit(number);
    
    if (negative) name = "negative " + name;
    
    auto out = new char[name.length()+1];
    strcpy(out, name.c_str());
    return out;
}

std::string oneDigit(std::string num) {
    int lastIndex = (int) num.length() - 1; //cuts off any leading numbers
    //case of input of 00001 or 21
    if (num[lastIndex] == '0' && num.length() == 1 ) return "zero";
    if (num[lastIndex] == '1') return "one";
    if (num[lastIndex] == '2') return "two";
    if (num[lastIndex] == '3') return "three";
    if (num[lastIndex] == '4') return "four";
    if (num[lastIndex] == '5') return "five";
    if (num[lastIndex] == '6') return "six";
    if (num[lastIndex] == '7') return "seven";
    if (num[lastIndex] == '8') return "eight";
    if (num[lastIndex] == '9') return "nine";
    return "";
}

std::string twoDigit(std::string num) {
    int indexOf2ndDigit = (int) num.length() - 2;

    if (num[indexOf2ndDigit] == '1') {
        if (num[indexOf2ndDigit+1] == '0') return "ten";
        if (num[indexOf2ndDigit+1] == '1') return "eleven";
        if (num[indexOf2ndDigit+1] == '2') return "twelve";
        if (num[indexOf2ndDigit+1] == '3') return "thirteen";
        if (num[indexOf2ndDigit+1] == '4') return "fourteen";
        if (num[indexOf2ndDigit+1] == '5') return "fifteen";
        if (num[indexOf2ndDigit+1] == '6') return "sixteen";
        if (num[indexOf2ndDigit+1] == '7') return "seventeen";
        if (num[indexOf2ndDigit+1] == '8') return "eightteen";
        if (num[indexOf2ndDigit+1] == '9') return "nineteen";
    }
    
    if (num[indexOf2ndDigit] == '2') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "twenty";
        } else {
            return "twenty " + oneDigit(num);
        }
    }
    
    if (num[indexOf2ndDigit] == '3') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "thirty";
        } else {
            return "thirty " + oneDigit(num);
        }
    }
    
    if (num[indexOf2ndDigit] == '4') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "fourty";
        } else {
            return "fourty " + oneDigit(num);
        }
    }
    
    if (num[indexOf2ndDigit] == '5') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "fifty";
        } else {
            return "fifty " + oneDigit(num);
        }
    }
    
    if (num[indexOf2ndDigit] == '6') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "sixty";
        } else {
            return "sixty " + oneDigit(num);
        }
    }
    
    if (num[indexOf2ndDigit] == '7') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "seventy";
        } else {
            return "seventy " + oneDigit(num);
        }
    }
    
    if (num[indexOf2ndDigit] == '8') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "eighty";
        } else {
            return "eighty " + oneDigit(num);
        }
    }
    
    if (num[indexOf2ndDigit] == '9') {
        if (num[indexOf2ndDigit+1] == '0') {
            return "ninety";
        } else {
            return "ninety " + oneDigit(num);
        }
    }
    
    return oneDigit(num);
}


std::string threeDigit(std::string num) {
    int indexOf3rdDigit = (int)num.length() - 3;
    std::string firstchar = "";
    firstchar.push_back(num[indexOf3rdDigit]);
    
    if (num[indexOf3rdDigit] != 0 && num[indexOf3rdDigit + 1] == '0' && num[indexOf3rdDigit + 2] == '0') {
        return oneDigit(firstchar) +"-hundread";
    }
    
    if (firstchar[0] != '0') {
        return oneDigit(firstchar) + "-hundread and " + twoDigit(num);
    }
    
    return twoDigit(num);
}

std::string fourDigit(std::string num) {
    int indexOf4thDigit = (int)num.length() - 4;
    std::string firstchar="";
    firstchar.push_back(num[indexOf4thDigit]);

    if (firstchar[0] != '0') {
        return oneDigit(firstchar) + "-thousand " + threeDigit(num);
    }
    
    return threeDigit(num);
}

std::string fiveDigit(std::string num) {
    int indexOf5thDigit = (int)num.length() - 5;
    std::string firstchar="";
    firstchar.push_back(num[indexOf5thDigit]);
    
    if (firstchar[0] != '0') {
        std::string firstTwo = "";
        firstTwo.push_back(num[indexOf5thDigit]);
        firstTwo.push_back(num[indexOf5thDigit + 1]);
        
        return twoDigit(firstTwo)  + "-thousand " + threeDigit(num);
    }
    
    return fourDigit(num);
}

std::string sixDigit(std::string num) {
    int indexOf6thDigit = (int)num.length() - 6;
    std::string firstchar = "";
    firstchar.push_back(num[indexOf6thDigit]);

    
    if (firstchar[0] != '0') {
        std::string firstThree;
        firstThree.push_back(num[indexOf6thDigit]);
        firstThree.push_back(num[indexOf6thDigit + 1]);
        firstThree.push_back(num[indexOf6thDigit + 2]);

        return threeDigit(firstThree)+ "-thousand " + threeDigit(num);
    }
    
    return fiveDigit(num);
}

std::string sevenDigit(std::string num) {
    int indexOf7thDigit = (int)num.length() - 7;
    std::string firstchar = "";
    firstchar.push_back(num[indexOf7thDigit]);
    
    if (firstchar[0] != '0') {
        return oneDigit(firstchar) + " million " + sixDigit(num);
    }
    
    return sixDigit(num);
}

std::string to_string(int x) {
    std::ostringstream ss;
    ss << x;
    return ss.str();
}