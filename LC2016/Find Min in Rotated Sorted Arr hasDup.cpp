//
//  Find Min in Rotated Sorted Arr hasDup.cpp
//  LC2016
//
//  Created by Fang Liu on 12/20/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Follow up for "Find Minimum in Rotated Sorted Array":
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 Find the minimum element.
 The array may contain duplicates.
 */

#include <vector>
#include <iostream>
using namespace std;

int findMin_hasDup(vector<int>& nums) {
    if(nums.empty()){
        return INT_MAX;
    }
    int left = 0;
    int right = nums.size()-1;
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(nums[mid] < nums[right]){
            right = mid;
        }else if(nums[mid] > nums[right]){
            left = mid;
        }else{
            right--;
        }
    }
    
    return nums[left]<nums[right]? nums[left]:nums[right];
}
