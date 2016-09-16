//
//  Classic Binary Search.cpp
//  LC2016
//
//  Created by Fang Liu on 3/21/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//


// classic binary search

#include <iostream>
using namespace std;

int binary_search(int arr[], int len, int target){
    if(arr == NULL || len <= 0){
        return -1;
    }
    
    int left = 0;
    int right = len - 1;
    
    while(left <= right){ // <=
        int mid = left + (right - left)/2;
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