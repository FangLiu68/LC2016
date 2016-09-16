//
//  Search for a Range.cpp
//  LC2016
//
//  Created by Fang Liu on 7/24/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a sorted array of integers, find teh starting and ending position of a given target value.
 Your algorithm's runtime coplexity must be in the order of O(logn).
 if the target is not found in the array, return [-1, -1].
 
 For example, 
 given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4]
 */

#include <vector>
#include <iostream>
using namespace std;

int helper_firstOccur(vector<int>& nums, int target);
int helper_lastOccur(vector<int>& nums, int target);

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res;
    if(nums.empty()){
        return res;
    }
    
    int first = helper_firstOccur(nums, target);
    int last = helper_lastOccur(nums, target);
    
    res.push_back(first);
    res.push_back(last);
    
    return res;
}

// first occur of target
int helper_firstOccur(vector<int>& nums, int target){
    if(nums.empty()){
        return -1;
    }
    
    int left = 0;
    int right = nums.size() - 1;
    
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            right = mid;
        }else if(nums[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    
    return -1;
}

int helper_lastOccur(vector<int>& nums, int target){
    if(nums.empty()){
        return -1;
    }
    
    int left = 0;
    int right = nums.size() - 1;
    
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
            left = mid;
        }else if(nums[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    
    if(nums[right] == target) return right;
    if(nums[left] == target) return left;
    
    return -1;
}