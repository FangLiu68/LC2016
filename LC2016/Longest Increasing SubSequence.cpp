//
//  Longest Increasing SubSequence.cpp
//  LC2016
//
//  Created by Fang Liu on 7/18/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Longest Ascending SubSequence
 Given an unsorted array of integers, find the length of longest increasing subsequence.
 
 For example,
 Given [10, 9, 2, 5, 3, 7, 101, 18],
 The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
 
 Your algorithm should run in O(n2) complexity.
 Follow up: Could you improve it to O(n log n) time complexity?
 
 Longest[i] = (0,i) longest ascending subsequence length ending at index i
 Longest[i] = max(Longest[j]) + 1 (0<=j<i and A[i]>A[j])
 */

#include <iostream>
#include <vector>
using namespace std;

int Longest_increasing_subsequence(vector<int>& input){
    if(input.empty()){
        return 0;
    }
    
    // record[i] the longest increasing subsequence length ending at index i
    vector<int> record(input.size(), 1);
    int res = record[0];
    
    for(int i=1; i<input.size(); ++i){
        
        int cur_max = 0;
        for(int j=0; j<i; ++j){
            if(input[i] > input[j]){
                cur_max = max(cur_max, record[j]);
            }
        }
        record[i] = cur_max + 1;
        res = max(res, record[i]);
    }
    
    return res;
}
/*
int main(){
    vector<int> input = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << Longest_increasing_subsequence(input) << endl;
    return 0;
}*/