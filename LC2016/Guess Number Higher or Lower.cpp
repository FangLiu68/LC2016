//
//  Guess Number Higher or Lower.cpp
//  LC2016
//
//  Created by Fang Liu on 7/27/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 We are playing the Guess Game, the game is as follows:
 I pick a number from 1 to n. You have to guess which number I picked.
 Every time you guess wrong, I'll tell you whether the number is higher or lower.
 
 You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
 -1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
 
 Example:
 n = 10, I pick 6.
 Return 6.
 */

#include <iostream>
using namespace std;
/*
int guess(int num);

int guessNumber(int n){
    int left = 0;
    int right = n;
    while(left <= right){
        int mid = left + (right-left)/2;
        int res = guess(mid);
        if(res == 0){
            return mid;
        }else if(res == 1){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return -1;
}*/