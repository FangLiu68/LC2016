//
//  Valid Perfect Square.cpp
//  LC2016
//
//  Created by Fang Liu on 8/11/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a positive integer num, write a function which returns true if num is a perfect square else false.
 
 Note: do not use any build-in library fuction such as sqrt.
 Example 1:
 input: 16; return true
 Example 2:
 input: 14; return false
 */

#include <vector>
#include <iostream>
using namespace std;

bool isPerfectSquare(int num) {
    long left = 0, right = num;
    while(left <= right){
        long mid = left + (right-left)/2;
        long t = mid * mid;
        if(t == num){
            return true;
        }else if(t < num){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}