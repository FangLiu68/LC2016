//
//  One Missing Num in Unsorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/1/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an integer array of size N - 1, containing all the numbers from 1 to N except one, find the missing number.
 
 Assumptions
 The given array is not null, and N >= 1
 Examples
 A = {2, 1, 4}, the missing number is 3
 A = {1, 2, 3}, the missing number is 4
 A = {}, the missing number is 1
 */
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

/* 
 M1: add numbers all the way from 0 to arr.size()+1, get the sum1 which includes the missing number's value
     add all the numbers from arr, get sum2 which doesn't include the missing value
     sum1 - sum2 = missing value
 both sorted/ unsorted arr could use this method.
 time complexity O(N), space complexity O(1)
*/
int find_missing_useMath(vector<int> input){
    if(input.empty()){
        return -1;
    }
    
    int sum1 = 0;
    int sum2 = 0;
    
    // get Sum1
    for(int i = 0; i <= input.size()+1; ++i){
        sum1 = sum1 + i;
    }
    
    // get Sum2
    for(int i = 0; i < input.size(); ++i){
        sum2 = sum2 + input[i];
    }
    
    return sum1 - sum2;
}

/*
 M2: bucket sort
 桶排序 swap- a[i]=i+1
 {3,1,5,4} -> {1,5,3,4} 返回2
 
 rules: input[i] = i+1 => i = input[i]-1 => input[i]=input[input[i]-1]
 
 time complexity O(N), space complexity O(1)
 */
int find_missing_bucketSort(vector<int> input){
    if(input.empty()){
        return -1;
    }
    
    for(int i=0; i<input.size(); ++i){
        while(input[i] != i+1 && input[i] <= input.size()){
            swap(input[i], input[input[i]-1]);
        }
    }
    
    for(int i=0; i<input.size(); ++i){
        if(input[i] != i+1){
            return i+1;
        }
    }
    return input.size()+1;
}

/*
 M3: use hash table to mark each elem is visted or not
 time complexity O(N), space complexity O(N)
 */
int find_missing_hash(vector<int> input){
    if(input.empty()){
        return 1;
    }
    bool mark[input.size()+1];
    for(int i=0; i<=input.size(); ++i){
        mark[i] = false;
    }
    for(int i=0; i<input.size(); ++i){
        mark[input[i]] = true;
    }
    for(int i=1; i<=input.size(); ++i){
        if(mark[i] == false){
            return i;
        }
    }
    return input.size()+1;
}

/*
 M4: put all elem to set from the arr. then check number 1-arr.size()+1, find the missing one.
 time complexity ???
 */
int find_missing_set(vector<int> input){
    if(input.empty()){
        return 1;
    }
    unordered_set<int> mark;
    for(int i=0; i<input.size(); ++i){
        mark.insert(input[i]);
    }
    for(int i=1; i<=input.size()+1; ++i){
        if(mark.find(i) == mark.end()){
            return i;
        }
    }
    return input.size()+1;
}

/*
 变形题：given an array containing number 1-n, one missing, find it
 */
int find_missing_num(vector<int> input, int n){
    if(input.empty()){
        return 1;
    }
    
    // 数组里一共包含了n-1个数，那么数组大小是n-1，则index大小<n-1
    int sum = 0;
    for(int i=0; i<n-1; ++i){
        sum = sum + input[i];
    }
    
    return (1+n)*n/2 - sum;
}
/*
int main(){
    vector<int> input = {2, 1, 4};
    cout << find_missing_num(input,4) << endl;
    return 0;
}*/