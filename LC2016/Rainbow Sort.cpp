//
//  Rainbow Sort.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given an array of balls, where the color of the balls can only be Red, Green or Blue, sort the balls such that all the Red balls are grouped on the left side, all the Green balls are grouped in the middle and all the Blue balls are grouped on the right side. (Red is denoted by -1, Green is denoted by 0, and Blue is denoted by 1).
 
 Examples
 
 {0} is sorted to {0}
 {1, 0} is sorted to {0, 1}
 {1, 0, 1, -1, 0} is sorted to {-1, 0, 0, 1, 1}
 Assumptions
 
 The input array is not null.
 Corner Cases
 
 What if the input array is of length zero? In this case, we should not do anything as well.
 
 Follow up:
 a rather staight forward solution is a two-pass algorithm using counting sort.
 First, iterate teh array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
 
 could you come up with an one-pass algorithm using only constant space?
 */

/*
 [0, bound_0)       0
 [bound_0, bound_1) 1
 (bound_2, end]     2
 
 注意：
 [bound_1, bound_2] 之间未知，所以当arr[bound_1]和arr[bound_2]swap之后，bound_1并不能++，因为此时我们还不确定换回来arr[bound_1]是什么值
 而我们确定的是[arr[bound_0], arr[bound_1])之间都是1，所以当arr[bound_0]和arr[bound_1]swap之后，我们肯定的是换回来的arr[bound_1]值为1，所以bound_1++
 */
#include <vector>
#include <iostream>
using namespace std;

// O(N) 遍历一遍
void rainbow_sort(int arr[], int len){
    if(arr == NULL || len <= 0){
        return;
    }
    
    int bound_0 = 0;
    int bound_1 = 0;
    int bound_2 = len - 1;
    
    while(bound_1 <= bound_2){
        if(arr[bound_1] == 0){
            swap(arr[bound_0++], arr[bound_1++]);
        }else if(arr[bound_1] == 1){
            bound_1++;
        }else{
            swap(arr[bound_1], arr[bound_2--]);
        }
    }
}

// 遍历两遍
void sortColorsI(vector<int>& nums) {
    if(nums.empty()) return;
    
    int count_zero = 0;
    int count_one = 0;
    int count_two = 0;
    
    for(int i=0; i<nums.size(); ++i){
        if(nums[i] == 0){
            count_zero++;
        }else if(nums[i] == 1){
            count_one++;
        }else{
            count_two++;
        }
    }
    
    int index = 0;
    while(index < nums.size()){
        for(int i=0; i<count_zero; ++i){
            nums[index++] = 0;
        }
        for(int i=0; i<count_one; ++i){
            nums[index++] = 1;
        }
        for(int i=0; i<count_two; ++i){
            nums[index++] = 2;
        }
    }
}

/*
 int main(){
 int arr[] = {1, 0, 2, 1, 0, 2, 2, 1, 0};
 int len = sizeof(arr) / sizeof(int);
 rainbow_sort(arr, len);
 for(int i=0; i<len; ++i){
 cout << arr[i] << " ";
 }
 cout << endl;
 return 0;
 }*/