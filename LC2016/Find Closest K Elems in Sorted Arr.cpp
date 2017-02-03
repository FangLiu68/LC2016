//
//  Find Closest K Elems in Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 2/1/17.
//  Copyright © 2017 Fang Liu. All rights reserved.
//

/*
 Find closest k elements in a sorted array. return the first and last indices in array.
 [1,3,5,8,12,17,19], target=9, k=4, return [3,5,8,12]
 
 solution:
 1. find the closest element's position in original array
 2. move the smaller one
 */

#include <vector>
#include <iostream>
using namespace std;

int helper_find_closest_index(vector<int>& input, int target){
    if(input.empty()){
        return -1;
    }
    int left = 0;
    int right = input.size()-1;
    while(left+1 < right){
        int mid = left+(right-left)/2;
        if(input[mid] == target){
            return mid;
        }else if(input[mid] < target){
            left = mid;
        }else{
            right = mid;
        }
    }
    return (target-input[left]<input[right]-target)? left:right;
}

vector<int> find_closest_k_elements(vector<int>& input, int target, int k){
    vector<int> res;
    if(input.empty()){
        return res;
    }
    int close_index = helper_find_closest_index(input, target);
    res.push_back(input[close_index]);
    int smaller = close_index-1;
    int larger = close_index+1;

    for(int i=0; i<k-1; ++i){
        if(larger<input.size() && smaller>=0){
            if(abs(input[close_index]-input[smaller]) < abs(input[close_index]-input[larger])){
                res.push_back(input[smaller--]);
            }else{
                res.push_back(input[larger++]);
            }
        }else if(close_index+1 >= input.size()){
            res.push_back(input[smaller--]);
        }else{
            res.push_back(input[larger++]);
        }
    }

    return res;
}

vector<int> find_closest_k_elements1(vector<int>& input, int target, int k){
    vector<int> res;
    if(input.empty()){
        return res;
    }
    int close_index = helper_find_closest_index(input, target);

    int smaller = (close_index-1 >= 0)? close_index-1 : close_index;
    int larger = (close_index+1 < input.size())? close_index+1 : close_index;

    for(int i=0; i<k; ++i){
        if(larger<input.size() && smaller>=0){
            if(abs(input[close_index]-input[smaller]) < abs(input[close_index]-input[larger])){
                res.push_back(input[smaller--]);
            }else{
                res.push_back(input[larger++]);
            }
        }else if(close_index+1 >= input.size()){
            res.push_back(input[smaller--]);
        }else{
            res.push_back(input[larger++]);
        }
    }

    return res;
}
/*
int main(){
    vector<int> input = {1,3,5,8,12,17,19};
    int target = 9;
    int k = 4;
    vector<int> res = find_closest_k_elements(input, target, k);
    for(int i=0; i<k; ++i){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
*/
