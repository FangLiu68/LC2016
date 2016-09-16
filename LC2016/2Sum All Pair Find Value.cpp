//
//  2Sum All Pair Find Value.cpp
//  LC2016
//
//  Created by Fang Liu on 4/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Find all pairs of elements in a given array that sum to the pair the given target number.
 Return all the distinct pairs of values.
 
 Assumptions
 The given array is not null and has length of at least 2
 The order of the values in the pair does not matter
 Examples
 A = {2, 1, 3, 2, 4, 3, 4, 2}, target = 6, return [[2, 4], [3, 3]]
 */

#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> twoSumAllPairFindValues(vector<int> array, int target) {
    vector<vector<int>> res;
    if(array.empty()) return res;
    
    sort(array.begin(), array.end());
    int left = 0;
    int right = array.size() - 1;
    
    vector<int> cur(2);
    while(left < right){
        if(array[left] + array[right] == target){
            cur[0] = array[left];
            cur[1] = array[right];
            res.push_back(cur);
            while(array[left+1] == array[left] && left < right) left++;
            while(array[right-1] == array[right] && right > left) right--;
            left++, right--;
        }else if(array[left] + array[right] < target){
            left++;
        }else{
            right--;
        }
    }
    
    return res;
}