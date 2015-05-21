//
//  ChangeReturnTest.cpp
//  Projects
//
//  Created by David Baker on 5/21/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <iostream>
#include "ChangeReturnTest.h"
#include "ChangeReturn.h"

bool changeTest() {
    bool passed = true;
    for (int i = 1; i < 6; i++) {
        switch (i) {
            case 1: {
                int* string_act = new int[4];
                int* double_act = new int[4];
                int* int_act = new int[4];
                string_act = returnChange("1.00");
                double_act = returnChange(1.00);
                int_act = returnChange(100);
                
                //4 quarters are expected
                if (string_act[0] != 4 || double_act[0] != 4 || int_act[0] != 4) {
                    passed = false;
                }
                delete string_act, double_act, int_act;
            }
            case 2 : { // check dimes
                int* string_act = new int[4];
                int* double_act = new int[4];
                int* int_act = new int[4];
                string_act = returnChange(".20");
                double_act = returnChange(0.20);
                int_act = returnChange(20);
                
                //2 dimes are expected
                if (string_act[1] != 2 || double_act[1] != 2 || int_act[1] != 2) {
                    passed = false;
                }
                delete string_act, double_act, int_act;
            }
            case 3: { // check Nickels
                int* string_act = new int[4];
                int* double_act = new int[4];
                int* int_act = new int[4];
                string_act = returnChange("0.05");
                double_act = returnChange(0.05);
                int_act = returnChange(5);
                
                // 1 nickel is expected
                if(string_act[2] != 1 || double_act[2] != 1 || int_act[2] != 1) {
                    passed = false;
                }
                delete string_act, double_act, int_act;
            }
            case 4: { // time to check for pennies
                int* string_act = new int[4];
                int* double_act = new int[4];
                int* int_act = new int[4];
                string_act = returnChange("0.04");
                double_act = returnChange(0.04);
                int_act = returnChange(4);
                
                // 4 pennies are expected
                if (string_act[3] != 4 || double_act[3] != 4 || int_act[3] != 4) {
                    passed = false;
                }
                delete string_act, double_act, int_act;
            }
            case 5: { // time to check all of them working together
                int* string_act = new int[4];
                int* double_act = new int[4];
                int* int_act = new int[4];
                string_act = returnChange("0.44");
                double_act = returnChange(0.44);
                int_act = returnChange(44);
                
                // expecting 1 Quarter, 1 dime, 1 nickel, 4 pennies
                if (string_act[0] != 1 || string_act[1] != 1 ||
                    string_act[2] != 1 || string_act[3] != 4)
                {
                    passed = false;
                }
                if (double_act[0] != 1 || double_act[1] != 1 ||
                    double_act[2] != 1 || double_act[3] != 4)
                {
                    passed = false;
                }
                if (int_act[0] != 1 || int_act[1] != 1 ||
                    int_act[2] != 1 || int_act[3] != 4)
                {
                    passed = false;
                }
                delete string_act, double_act, int_act;
            }
        }
        if (!passed) {
            std::cout << "Case " << i << " failed";
            break;
        }
    }
    return passed;
}



