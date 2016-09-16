//
//  Subsets with No Dup.cpp
//  LC2016
//
//  Created by Fang Liu on 4/14/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a set of distinct integers, nums, return all possible subsets.
 
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If nums = [1,2,3], a solution is:
 
 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]
 */

#include <vector>
#include <iostream>
using namespace std;



void helper_subsets(vector<int> nums, int level, vector<vector<int>>& res, vector<int> cur);

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> cur;
    helper_subsets(nums, 0, res, cur);
    return res;
}

void helper_subsets(vector<int> nums, int level, vector<vector<int>>& res, vector<int> cur){
    if(nums.size() == level){ // level从0开始，base case时num已经全部push进cur
        res.push_back(cur);
        return;
    }
    
    cur.push_back(nums[level]);
    helper_subsets(nums, level+1, res, cur); // 本层和下一步的dfs的level是同一层，相同值
    cur.pop_back();
    
    helper_subsets(nums, level+1, res, cur);
}

////// 另一种做法
void helper_sub(vector<int>& input, int step, vector<vector<int>>& res, vector<int>& cur){
    for(int i=step; i<input.size(); ++i){
        cur.push_back(input[i]);
        res.push_back(cur);
        if(i < input.size()-1){
            helper_sub(input, i+1, res, cur);
        }
        cur.pop_back();
    }
}

vector<vector<int>> subss(vector<int>& input){
    vector<vector<int>> res;
    vector<int> cur;
    if(input.size() == 0) return res;
    res.push_back(cur);
    sort(input.begin(), input.end());
    helper_sub(input, 0, res, cur);
    return res;
}


