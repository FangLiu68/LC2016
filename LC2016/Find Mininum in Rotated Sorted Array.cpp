//
//  Find Mininum in Rotated Sorted Array.cpp
//  LC2016
//
//  Created by Fang Liu on 7/20/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2
 Find the minimum element.
 You may assume no duplicate exists in the array.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 O(logN)
 */
int findMin(vector<int>& nums) {
    if(nums.empty()){
        return INT_MAX;
    }
    int left = 0;
    int right = nums.size() - 1;
    
    // delete half of the candidates
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(nums[mid] < nums[right]){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    return nums[left]<nums[right]? nums[left]:nums[right];
}