//
//  Remove Dup in Sorted Arr Keep Two.cpp
//  LC2016
//
//  Created by Fang Liu on 4/6/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// Given one sorted array, remove the dup nodes and keep at most two copies.

#include <vector>
#include <iostream>
using namespace std;

int remove_dup_in_sortedArr_keepTwo(vector<int> input){
    if(input.size() <= 2){
        return input.size();
    }
    
    int slow = 2;
    for(int i=2; i<input.size(); ++i){
        if(input[i] != input[slow-2]){
            input[slow++] = input[i];
        }
    }
    
    return slow;
}