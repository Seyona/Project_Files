//
//  PrimeNums.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include <iostream>
#include "PrimeNums.h"

using std::cout; using std::endl;

/*
 Forms a collection of primes from 2 -> n
 */
int* collectionOfPrimesToN(int n) {
    int* collection = new int[n];
    for(int i = 0; i < n; i++) { collection[i] = 0; }
    
    
    
    int index = 0;
    for (int i = 2; i <= n; i++) {
        bool onlyDivisableBySelf = true;
        for (int j = 2; j <= i; j++) {
            if (i % j == 0 && i != j) onlyDivisableBySelf = false;
        }
        if (onlyDivisableBySelf){
            collection[index] = i;
            index++;
        }
    }
    
    return collection;
}
/*
 Enter a number and find all Prime Factors (if there are any) and display them.
 */
void primeFactors(int x) {
    int* primes = collectionOfPrimesToN(x);
    
    int index = 0;
    while (primes[index] != 0) {
        if (x % primes[index] == 0) {
            cout << primes[index] << " ";
        }
        index++;
    }
}


int findNextPrime(int currPrime) {
    for (int i = currPrime+1; i <= INT_MAX; i ++) {
        bool IsPrime = true;
        for (int j = 2; j <= i; j++) {
            if (i % j == 0 && i != j) {
                IsPrime = false;
                break;
            }
        }
        if (IsPrime) {
            return i;
        }
    }
    return 0; // couldn't find an applicable prime, Hopefully no one goes this far
}

/*
 Find Primes until 0 is inputed
 */
void nextPrime() {
    cout << "First Prime is 2" << endl;
    int x;
    int currPrim = 2;
    cout << "Enter 1 for another, 0 to exit" << endl;
    while (std::cin >> x) {
        if (x == 0) break;
        if (x != 1) {
            cout << "Enter 1 for another prime, 0 to exit" << endl;
            break;
        } else {
            currPrim = findNextPrime(currPrim);
            cout << "The next prime is " << currPrim << endl;
        }
    }
}


