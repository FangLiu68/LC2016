//
//  Summary Ranges.cpp
//  LC2016
//
//  Created by Fang Liu on 7/24/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a sorted integer array without duplicates, return the summary of its ranges.
 For example, given [0, 1, 2, 4, 5, 7], return ["0->2", "4->5", "7"]
 */

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

string helper_fromTo(int from, int to){
    stringstream temp;
    if(from == to){
        temp << from;
    }else{
        temp << from << "->" << to;
    }
    return temp.str();
}

vector<string> summaryRanges(vector<int>& nums){
    vector<string> res;
    int start = 0;
    int end = 0;
    while(end < nums.size()){
        while(end < nums.size()-1 && nums[end+1] == nums[end]){
            end++;
        }
        res.push_back(helper_fromTo(nums[start], nums[end]));
        start = end+1;
        end = start;
    }
    return res;
}