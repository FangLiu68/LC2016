//
//  Search in Rotated Sorted Array.cpp
//  LC2016
//
//  Created by Fang Liu on 7/21/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 you are given a target value to search. if found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.
 */

#include <vector>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target) {
    if(nums.empty()){
        return -1;
    }
    
    int left = 0;
    int right = nums.size()-1;
    
    while(left <= right){
        int mid = left + (right - left)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[left] <= nums[mid]){ // left part is sorted
            if(nums[left]<=target && target<nums[mid]){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }else{
            if(nums[mid]<target && target<=nums[right]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
    }
    
    return -1;
}