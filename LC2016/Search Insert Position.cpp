//
//  Search Insert Position.cpp
//  LC2016
//
//  Created by Fang Liu on 7/21/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a sorted array and a target value, return teh index if the target is found. If not, return the index where it would be if it were inserted in order.
 You may assume no duplicates in the array.
 */
#include <vector>
#include <iostream>
using namespace std;

// same as binary search. only difference is return index left.
int searchInsert(vector<int>& nums, int target) {
    if(nums.empty()){
        return 0;
    }
    
    int left = 0;
    int right = nums.size() - 1;
    
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return left;
}