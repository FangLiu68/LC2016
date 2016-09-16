//
//  2Sum.cpp
//  LC2016
//
//  Created by Fang Liu on 4/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Determine if there exist two elements in a given array, the sum of which is the given target number.
 Assumptions
 The given array is not null and has length of at least 2
 ​Examples
 A = {1, 2, 3, 4}, target = 5, return true (1 + 4 = 5)
 A = {2, 4, 2, 1}, target = 4, return true (2 + 2 = 4)
 A = {2, 4, 1}, target = 4, return false
 */

#include <vector>
#include <iostream>
using namespace std;

bool exist2Sum(vector<int> array, int target) {
    if(array.size() < 2){
        return false;
    }
    
    sort(array.begin(), array.end());
    
    int left = 0;
    int right = array.size() - 1;
    while(left < right){
        if(array[left] + array[right] == target){
            return true;
        }else if(array[left] + array[right] < target){
            left++;
        }else{
            right--;
        }
    }
    return false;
}