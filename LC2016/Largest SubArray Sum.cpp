//
//  Largest SubArray Sum.cpp
//  LC2016
//
//  Created by Fang Liu on 7/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 For example, given the array [-2, 1, -3, 4, -1, 2, 1, -5, 4]
 The contiguous subarray [4, -1, 2, 1] has the largest sum = 6.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 largestSum[i] = max(input[i], largestSum[i-1]+input[i])
 time O(N), space O(N)
 */
int largest_subarray_sum(vector<int>& input){
    if(input.empty()){
        return INT_MIN;
    }
    
    vector<int> record(input.size(), 0);
    record[0] = input[0];
    int res = record[0];
    
    for(int i=1; i<input.size(); ++i){
        record[i] = max(record[i-1]+input[i], input[i]);
        res = max(res, record[i]);
    }
    
    return res;
}

/*
 optimize the previous solution
 time O(N), space O(1)
 */
int largest_subarray_sumI(vector<int>& input){
    if(input.empty()){
        return INT_MIN;
    }
    
    int cur_max = input[0];
    int res = cur_max;
    
    for(int i=1; i<input.size(); ++i){
        cur_max = max(cur_max + input[i], input[i]);
        res = max(res, cur_max);
    }
    
    return res;
}