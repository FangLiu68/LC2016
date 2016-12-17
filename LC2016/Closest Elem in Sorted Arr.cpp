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
int find_closest_num(vector<int> arr, int target){
    if(arr.empty()){
        throw invalid_argument("out of boundary");
    }
    
    int left = 0;
    int right = arr.size() - 1;
    
    while(left+1 < right){
        int mid = left + (right-left)/2;
        if(arr[mid] == target){
            return arr[mid];
        }else if(arr[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    
    if(abs(arr[left]-target) < abs(arr[right]-target)){
        return arr[left];
    }else{
        return arr[right];
    }
}
/*
int main(){
    vector<int> arr = {1,3,7,9,100};
    int target = 2;
    cout << find_closest_num(arr, target) << endl;
    return 0;
}
*/
