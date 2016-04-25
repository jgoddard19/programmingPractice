//
//  main.cpp
//  MagicSquares
//
//  Created by Jared Goddard on 4/5/16.
//  Copyright © 2016 Jared. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

// [8, 1, 6,
//  3, 5, 7,
//  4, 9, 2] => true
// [2, 7, 6,
//  9, 5, 1,
//  4, 3, 8] => true
// [3, 5, 7,
//  8, 1, 6,
//  4, 9, 2] => false
// {4, 14, 15, 1,
//  9, 7, 6, 12,
//  5, 11, 10, 8,
//  16, 2, 3, 13} => false
// [8, 1, 6,
//  7, 5, 3,
//  4, 9, 2] => false

int validityCheck(int a[], int size) {
    bool validity = 0;
    //0+3+6 1+4+7 2+5+8
    cout<<"size of input array: "<<size<<"\n";
    int total = 0;
    
    //COLUMNS
    cout<<"Initializing column check\n";
    for (int j=0; j<sqrt(size); j++) {
        total = 0;
        for (int i=0; i<size; i+=sqrt(size)) {
//            cout<<a[i+j]<<"\n";
            total += a[i+j];
        }
//        cout<<"total is: "<<total<<"\n";
        if (total == 15) {
            validity = 1;
        } else {
            validity = 0;
            cout<<"failed column check, array is invalid\n";
            return validity;
        }
    }
    
//    if (input[i] + input[i + vecSqrt] + input[i + vecSqrt*2] != 15)
//    {
//        std::cout << ": False\n";
//        return;
//    }
    
    
    //ROWS
    cout<<"Initializing row check\n";
    total = 0;
    for (int j=0; j<size; j+=sqrt(size)) {
        total = 0;
        for (int i=0; i<sqrt(size); i++) {
//            cout<<a[i+j]<<"\n";
            total += a[i+j];
        }
//        cout<<"total is: "<<total<<"\n";
        if (total == 15) {
            validity = 1;
        } else {
            validity = 0;
            cout<<"failed row check, array is invalid\n";
            return validity;
        }
    }
    
    //DIAGONALS
    cout<<"Initializing diagonal check\n";
    // for 3x3: 0,4,8 and 2,4,6
    // for 4x4: 0,5,10,15 and 3,6,9,12
    total = 0;
    for (int i=0; i<size; i+=(sqrt(size)+1)) {
//        cout<<a[i]<<"\n";
        total += a[i];
    }
//    cout<<"total is: "<<total<<"\n";
    if (total == 15) {
        validity = 1;
    } else {
        validity = 0;
        cout<<"failed diagonal check, array is invalid\n";
        return validity;
    }
    total = 0;
    int index = sqrt(size)-1;
    for (int i=0; i<sqrt(size); i++) {
        index += i*(sqrt(size)-1);
//        cout<<a[index]<<"\n";
        total += a[index];
        index = sqrt(size)-1;
    }
//    cout<<"total is: "<<total<<"\n";
    if (total == 15) {
        validity = 1;
    } else {
        validity = 0;
        cout<<"failed diagonal check, array is invalid\n";
        return validity;
    }
    
    if (validity == 1) {
        cout<<"array is valid\n";
    } else {
        cout<<"array is invalid\n";
    }
    
    return validity;
}

int main(int argc, const char * argv[]) {
    int goodSquare[9] = {8, 1, 6, 3, 5, 7, 4, 9, 2};
    int goodSquare2[9] = {2, 7, 6, 9, 5, 1, 4, 3, 8};
    int badSquare3[16] = {4, 14, 15, 1, 9, 7, 6, 12, 5, 11, 10, 8, 16, 2, 3, 13};
    int badSquare[9] = {3, 5, 7, 8, 1, 6, 4, 9, 2};
    int badSquare2[9] = {8, 1, 6, 7, 5, 3, 4, 9, 2};
    
    validityCheck(goodSquare, sizeof(goodSquare)/sizeof(goodSquare[1]));
    validityCheck(goodSquare2, sizeof(goodSquare2)/sizeof(goodSquare2[1]));
    validityCheck(badSquare3, sizeof(badSquare3)/sizeof(badSquare3[1]));
    validityCheck(badSquare, sizeof(badSquare)/sizeof(badSquare[1]));
    validityCheck(badSquare2, sizeof(badSquare2)/sizeof(badSquare2[1]));
    
    return 0;
}