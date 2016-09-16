//
//  3Sum Closest.cpp
//  LC2016
//
//  Created by Fang Liu on 7/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array S of n integers, find three integers in S such that the sum is closest to a given number target. 
 Return the sum of the three integers. You may assume that each input would have exactly one solution.
 For example:
 given array S = {-1, 2, 1, -4}, and target = 1
 the sum that is closest to the target is 2 (-1+2+1=2)
 */

#include <vector>
#include <iostream>
using namespace std;

int three_sum_closest(vector<int>& input, int target){
    if(input.size() < 3){
        return INT_MIN;
    }
    
    sort(input.begin(), input.end());
    int close = INT_MAX;
    int res = 0;
    
    for(int i=0; i<input.size(); ++i){
        int start = i+1;
        int end = input.size()-1;
        while(start < end){
            int sum = input[i] + input[start] + input[end];
            if(sum == target){
                return sum;
            }
            
            int gap = abs(target - sum);
            if(gap < close){
                res = sum;
                gap = close;
            }
            
            if(sum < target){
                start++;
            }else{
                end--;
            }
        }
    }
    
    return res;
}