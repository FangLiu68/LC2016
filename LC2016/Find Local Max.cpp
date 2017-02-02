//
//  Find Local Max.cpp
//  LC2016
//
//  Created by Fang Liu on 2/1/17.
//  Copyright © 2017 Fang Liu. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

int find_local_max(vector<int>& input){
    if(input.empty()){
        return -1;
    }
    int left = 0;
    int right = input.size()-1;
    while(left+1 < right){
        int mid = left+(right-left)/2;
        if(input[mid]>input[mid+1] && input[mid]>input[mid-1]){
            return mid;
        }else if(input[mid]<input[mid+1]){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    return input[left]>input[right]? left:right;
}
