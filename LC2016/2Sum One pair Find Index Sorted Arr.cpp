//
//  2Sum One pair Find Index Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 
 The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 
 You may assume that each input would have exactly one solution.
 
 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
 */

#include <vector>
#include <iostream>
using namespace std;

pair<int,int> twoSumSortedArr(vector<int> input, int target){
    pair<int, int> res;
    if(input.empty()) return res;
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left < right){
        if(input[left] + input[right] == target){
            res.first = left + 1;
            res.second = right + 1;
            break;
        }else if(input[left] + input[right] < target){
            left++;
        }else{
            right--;
        }
    }
    
    return res;
}
