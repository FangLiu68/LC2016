//
//  Jump Game II.cpp
//  LC2016
//
//  Created by Fang Liu on 7/26/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in teh minimum number of jumps.
 
 For example:
                  0 1 2 3 4
 Given array A = [2,3,1,1,4]
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 d[k] = max(i+A[i]) d[k-2] < i <= d[k-1]
 */

int jump(vector<int>& nums) {
    int curMax = 0;
    int res = 0;
    int index = 0;
    
    while(curMax < nums.size()-1){
        int lastMax = curMax;
        
        while(index <= lastMax){
            curMax = max(curMax, index+nums[index]);
            index++;
        }
        
        res++;
        if(lastMax == curMax) return -1;
    }
    return res;
}

/*
int main(){
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
    return 0;
}
*/