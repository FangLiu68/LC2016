//
//  Sqrt.cpp
//  LC2016
//
//  Created by Fang Liu on 12/16/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// Implement int sqrt() function

#include <iostream>
using namespace std;

/*
 Binary Search and post processing
 if num/mid = mid, return mid
 if num/mid > mid, left = mid
 if num/mid < mid, right = mid
 post processing 需要向下取整
 
 complexity
 time O(logN), space O(1)
 
 test case:
 num = -2
 num = 1, return 1
 num = 16, return 4
 num = 10, return 3
 */
int mySqrt(int num){
    if(num < 0){
        throw invalid_argument("out of boundary");
    }
    if(num < 2){
        return num;
    }

    int left = 1;
    int right = num;

    while(left+1 < right){
        int mid = left+(right-left)/2;
        if(num/mid == mid){
            return mid;
        }else if(num/mid < mid){
            right = mid;
        }else{
            left = mid;
        }
    }

    if(num/right > right){
        return right;
    }else{
        return left;
    }
}
/*
int main(){
    int num = 10;
    cout << mySqrt(num) << endl;
    return 0;
}*/
