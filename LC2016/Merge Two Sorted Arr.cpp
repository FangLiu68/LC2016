//
//  Merge Two Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 4/7/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

/*
 Given two sorted integer arrays A and B, merge B into A as one sorted array.
 
 Note:
 You may assume that A has enough space (size that is greater or equal to m+n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

#include <vector>
#include <iostream>
using namespace std;

void mergeTwoSortedArr(vector<int>& input1, int size1, vector<int>& input2, int size2){
    if(input1.empty() || input2.empty()){
        return;
    }
    
    int index1 = size1 - 1;
    int index2 = size2 - 1;
    int final_index = size1 + size2 - 1;
    
    while(index1 >= 0 && index2 >= 0){
        if(input1[index1] >= input2[index2]){
            input1[final_index--] = input1[index1--];
        }else{
            input1[final_index--] = input2[index2--];
        }
    }
    
    while(index2 >= 0){
        input1[final_index--] = input2[index2--];
    }
}