//
//  Find Mininum in Rotated Sorted Array II.cpp
//  LC2016
//
//  Created by Fang Liu on 7/21/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Follow up for "Find Mininum in Rotated Sorted Array"
 what if duplicates are allowed?
 would this affect the run-time complexity? How and why?
 
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 The array may contain duplicates.
 */

#include <vector>
#include <iostream>
using namespace std;

int find_min_rotatedSortArrII(vector<int>& input){
    if(input.empty()){
        return INT_MIN;
    }
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(mid < right){
            right = mid;
        }else if(mid > right){
            left = mid;
        }else{
            right--;
        }
    }
    
    return input[left] < input[right]? left : right;
}