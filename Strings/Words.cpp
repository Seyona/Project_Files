//
//  Words.cpp
//  MiniProjects
//
//  Created by David Baker on 5/18/15.
//  Copyright (c) 2015 David Baker. All rights reserved.
//

#include "Words.h"
/*
  Count the number of vowels in a given string
  Also return the sum of all vowels
  array[0] holds # of vowels, array[1] holds the sum
 */

int* countVowels(char* str) {
    char vowels[] = {'a','e','i','o','u','\0'};
    int* out = new int[2];
    int vowelSum = 0;
    int numVowels = 0;
    int index = 0;
    
    while(str[index] != '\0') {
        int vowelIndex = 0;
        while (vowels[vowelIndex] != '\0') {
            if (str[index] == vowels[vowelIndex]) {
                numVowels++;
                vowelSum += (int)vowels[vowelIndex];
                break; //found the vowel move on to next letter
            }
            vowelIndex++;
        }
        index++;
    }
    
    out[0] = numVowels;
    out[1] = vowelSum;
    
    return out;
}

/*
    Count the number of words in a string
    Eventually want to be able to summerize a set of strings 
 */
int countWordsInStr(char* str) {
    int words = 0;
    
    for (int i = 0; i != '\0'; i++) {
        if (str[i] == ' ') {
            //check for null term / double space
            if (str[i + 1] != '\0' || str[i + 1] != ' ') {
                words++;
            } //else null term is hit
        }
    }
    return words;
}