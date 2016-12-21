//
//  Find Target in Increasing Decreasing Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 12/20/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array, first increasing, then decreasing, find the target value.
 [1,3,6,7,4,2,0]
 target=3, return index 1; target=5, return index -1; target=2, return index 5
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 steps:
 1. find position of the largest element
    compare arr[mid] with arr[mid+1]
    arr[mid]<arr[mid+1]: right half
    arr[mid]>arr[mid+1]: left half
 2. do binary search on the increasing position and decreasing position
 */
int helper_findMax(vector<int>& arr){
    if(arr.empty()){
        return INT_MIN;
    }
    int left = 0;
    int right = arr.size()-1;
    while(left+1 < right){
        int mid = left+(right-left)/2;
        if(arr[mid]<arr[mid+1]){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    return arr[right]>arr[left]? right:left;
}

int helper_binarySearch(vector<int>& arr, int left, int right, int target){
    if(arr.empty()){
        return INT_MIN;
    }
    while(left <= right){
        int mid = left+(right-left)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}

int find_target_in_increasing_decreasing_arr(vector<int>& arr, int target){
    if(arr.empty()){
        return -1;
    }
    int maxValue_index = helper_findMax(arr);
    int left_res = helper_binarySearch(arr, 0, maxValue_index, target);
    int right_res = helper_binarySearch(arr, maxValue_index+1, arr.size()-1, target);
    if(left_res != -1){
        return left_res;
    }else if(right_res != -1){
        return right_res;
    }else{
        return -1;
    }
}

int main(){
    vector<int> arr = {1,3,6,7,4,2,0};
    int target = 2;
    cout << find_target_in_increasing_decreasing_arr(arr, target) << endl;
    return 0;
}
