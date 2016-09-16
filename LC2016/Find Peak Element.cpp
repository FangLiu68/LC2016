//
//  Find Peak Element.cpp
//  LC2016
//
//  Created by Fang Liu on 7/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 A peak element is an element that is greater than its neighbors.
 Given an input array where num[i]!=num[i+1], find a peak element and return its index.
 The array may contain multiple peaks, in that case return the index to any one of teh peaks is fine.
 You may imagine that num[-1] = num[n] = INT_MIN
 For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 */

#include <vector>
#include <iostream>
using namespace std;

int find_peak(vector<int>& input){
    if(input.empty()){
        return INT_MIN;
    }
    
    if(input.size() == 1) return 0;
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left < right-1){
        int mid = left + (right-left)/2;
        if(input[mid] > input[mid-1] && input[mid] > input[mid+1]){
            return mid;
        }else if(input[mid] < input[mid-1]){
            right = mid;
        }else{
            left = mid;
        }
    }
    
    return input[left]>input[right]? left:right;
}