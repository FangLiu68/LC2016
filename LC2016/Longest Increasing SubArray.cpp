//
//  Longest Increasing SubArray.cpp
//  LC2016
//
//  Created by Fang Liu on 7/17/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array, find the longest increasing subarray(contigousely), and return its length.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 longestIncreasingSubArr[i] = during index (0, i) the longest increasing subarray ending at index i
 LIS[i] = LIS[i-1] + 1 // if input[i] > input[i-1]
        = 1 // else
 
 input A[n] = {7, 2, 3, 1, 5, 8, 9, 6}
 definition: M[n] represents the length of longest increasing subarray ends with A[n]
 base case: M[0] = 1
 induction rule:
 M[n] = 1          (if A[n] <= A[n-1])
      = M[n-1] + 1 (if A[n] >  A[n-1])
 result: max
 */

// time O(N), space O(N)
int longest_increasing_subarr(vector<int>& input){
    if(input.empty()){
        return INT_MIN;
    }
    
    vector<int> record(input.size(), 0);
    record[0] = 1;
    int res = record[0];
    
    for(int i=1; i<input.size(); ++i){
        if(input[i] > input[i-1]){
            record[i] = record[i-1] + 1;
        }else{
            record[i] = 1;
        }
        res = max(res, record[i]);
    }
    
    return res;
}

/*
 Optimize the previous solution 
 time complexity O(N), space complexity O(1)
 */
int LIS(vector<int>& input){
    if(input.empty()){
        return INT_MIN;
    }
    
    int cur_longest = 1;
    int res = cur_longest;
    
    for(int i=1; i<input.size(); ++i){
        if(input[i] > input[i-1]){
            cur_longest = cur_longest + 1;
        }else{
            cur_longest = 1;
        }
        
        res = max(res, cur_longest);
    }
    
    return res;
}

/*
int main(){
    vector<int> input = {7, 2, 3, 1, 5, 8, 9, 6};
    cout << LIS(input) << endl;
    return 0;
}*/
