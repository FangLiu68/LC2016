//
//  Closest Elem in Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a target integer T and an integer array A sorted in ascending order, find the index i in A such that A[i] is closest to T.
 Assumptions
 There can be duplicate elements in the array, and we can return any of the indices with same value.
 Examples
 A = {1, 2, 3}, T = 2, return 1
 A = {1, 4, 6}, T = 3, return 1
 A = {1, 4, 6}, T = 5, return 1 or 2
 A = {1, 3, 3, 4}, T = 2, return 0 or 1 or 2
 Corner Cases
 What if A is null or A is of zero length? We should return -1 in this case.
 */

#include <iostream>
using namespace std;

int find_closest_elem(int arr[], int len, int target){
    if(arr == NULL || len <= 0){
        return -1;
    }
    
    int left = 0;
    int right = len-1;
    
    while(left < right-1){
        int mid = left+(right-left)/2;
        if(arr[mid] == target){
            return mid;
        }else if(arr[mid] < target){ // 无法判断是否要舍去left/right，所以post processing
            left = mid;
        }else{
            right = mid;
        }
    }
    
    if(abs(arr[left]-target) <= abs(arr[right]-target)){
        return left;
    }else {
        return right;
    }
}

