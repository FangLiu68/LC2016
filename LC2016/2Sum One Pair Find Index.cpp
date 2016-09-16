//
//  2Sum One Pair Find Index.cpp
//  LC2016
//
//  Created by Fang Liu on 4/19/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Suppose only exist one pairs of elements in a given array that sum to the given target number.
 Return the pairs of indices.
 
 Assumptions
 The given array is not null and has length of at least 2.
 Examples
 A = {1, 5, 2, 4}, target = 5, return [0, 3]
 A = {1, 3, 2, 4}, target = 6, return [2, 3]
 */

#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

// key: input[i]; value: i
pair<int, int> twoSum_index(vector<int> input, int target){
    pair<int, int> res;
    if(input.empty()){
        return res;
    }
    
    unordered_map<int, int> mp;
    for(int i=0; i<input.size(); ++i){
        int gap = target - input[i];
        if(mp.find(gap) != mp.end()){
            res.first = i+1;
            res.second = mp[gap] + 1;
            return res;
        }
        mp[input[i]] = i;
    }
    
    return res;
}