//
//  Find Larger Smallest Num in Sorted Arr.cpp
//  LC2016
//
//  Created by Fang Liu on 12/24/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// find the larger smallest number in a sorted array

#include <vector>
#include <iostream>
using namespace std;

int find_larger_smallest(vector<int>& arr, int target){
    if(arr.empty() || arr[arr.size()-1]<=target){
        return -1;
    }

    int left = 0;
    int right = arr.size()-1;

    while(left+1 < right){
        int mid = left+(right-left)/2;
        if(arr[mid] == target){
            left = mid+1;
        }else if(arr[mid] < target){
            left = mid+1;
        }else{
            right = mid;
        }
    }

    return arr[left]>target? left:right;
}
/*
int main(){
    vector<int> arr = {1,3,6,8};
    int target = 8;
    cout << find_larger_smallest(arr, target) << endl;
    return 0;
}*/
