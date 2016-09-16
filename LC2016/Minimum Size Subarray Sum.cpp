//
//  Minimum Size Subarray Sum.cpp
//  LC2016
//
//  Created by Fang Liu on 8/9/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum >= s. 
 If there isn't one, return 0 instead.
 For example, given the array [2, 3, 1, 2, 4, 3] and s = 7.
 the subarray [4,3] has the minimal length under the problem constraint.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 例子 1 4 4， s=4
 这里不能设置res初始值为0，只能用INT_MAX
 如果用0，最开始的1，4=》length=2就不能存储下来，即length=1永远也不会出现，因为res初始值就设置成0
 只有将res初始值设置足够大，两个指针间的任何一段距离才都能被保持下来，从而在每个循环内比较
 */
int min_subarray_sum(vector<int>& input, int s){
    if(input.empty()){
        return INT_MAX;
    }
    
    int left = 0;
    int right = 0;
    int res = INT_MAX;
    int cur_sum = 0;
    
    while(right < input.size()){
        cur_sum = cur_sum + input[right];
        
        while(cur_sum >= s){
            res = min(res, right-left+1);
            cur_sum = cur_sum - input[left];
            left++;
        }
        
        right++;
    }
    
    return res==INT_MAX? 0:res;
}