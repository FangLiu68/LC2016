//
//  Jump Game.cpp
//  LC2016
//
//  Created by Fang Liu on 7/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at the position.
 Determine if you are able to reach the last index.
 
 For example
      0 1 2 3 4
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.
 */

#include <iostream>
#include <vector>
using namespace std;

/*
 maxIndex: for current index i, the max index we can get 
 in order to reach to the end, the maxIndex should >= n-1
 
 当跳到位置i后，能达到的最大距离至少是i+A[i]
 1. 能跳到位置i的条件：i <= maxIndex
 2. 一旦跳到i，则maxIndex = max(maxIndex, i+A[i])
 3. 能跳到最后一个位置n-1的条件是：maxIndex >= n-1
 
 if (maxIndex>=nums.size()-1), we could definitely reach to the end
 if (i > maxIndex), we could not get to i
 */

// time O(N), space O(1)
bool canJump(vector<int>& nums) {
    if(nums.empty()){
        return false;
    }
    
    int maxIndex = 0;
    for(int i=0; i<nums.size(); ++i){
        if(maxIndex >= nums.size()-1 || i > maxIndex) break;
        maxIndex = max(maxIndex, i + nums[i]);
    }
    
    return maxIndex>=nums.size()-1 ? true:false;
}