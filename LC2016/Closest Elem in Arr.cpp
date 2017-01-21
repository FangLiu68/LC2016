//
//  Closest Elem in Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given a target integer T and an integer array A sorted in ascending order, find the index i in A such that A[i] is closest to T.
 Assumptions
 There can be duplicate elements in the array, and we can return any of the indices with same value.
 Examples
 A = {1, 2, 3}, T = 2, return 1
 A = {1, 4, 6}, T = 3, return 1
 A = {1, 4, 6}, T = 5, return 1 or 2
 A = {1, 3, 3, 4}, T = 2, return 0 or 1 or 2
 Corner Cases
 What if A is null or A is of zero length? We should return -1 in this case.
 */

#include <vector>
#include <iostream>
using namespace std;

/*
 suppose its sorted array.
 use binary search and post processing (loop termination condition when index_left + 1 = index_right)
 
 complexity:
 tiem O(logN), space O(1)
 
 test case:
 arr[1,3,7,9,100], target 10, return 9
 arr[1,3,7,9,100], target 7, return 7
 arr[1,3,7,9,100], target 5, return 7
 arr[1,3,3,7,9,100], target 2, return 3
 arr[], target 8, throw exception
 */
int find_closest_num(vector<int> input, int target){
    if(input.empty()){
        throw invalid_argument("out of boundary");
    }
    
    int left = 0;
    int right = input.size() - 1;
    
    while(left+1 < right){
        int mid = left + (right-left)/2;
        if(input[mid] == target){
            return input[mid];
        }else if(input[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }

    return target-input[left]<input[right]-target? left:right;
}

int find_closest_unsorted_arr(vector<int>& input, int target){
    if(input.empty()){
        return INT_MAX;
    }
    int res = input[0];
    int gap = abs(res-target);

    for(int i=1; i<input.size(); ++i){
        if(abs(input[i]-target) < gap){
            res = input[i];
            gap = abs(input[i]-target);
        }
    }
    return res;
}

/*
int main(){
    vector<int> arr = {1,10,17,6,100};
    int target = 8;
    cout << find_closest_unsorted_arr(arr, target) << endl;
    return 0;
}
*/
