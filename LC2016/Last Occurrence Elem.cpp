//
//  Last Occurrence Elem.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// Given a sorted array, return the last index of the target element. If the target couldn't be found, return -1.

#include <iostream>
using namespace std;

int find_last_occur(int arr[], int len, int target){
    if(arr == NULL || len <= 0){
        return -1;
    }
    
    int left = 0;
    int right = len - 1;
    while(left < right-1){ // NOTE
        int mid = left + (right-left)/2;
        if(arr[mid] == target){
            left = mid;
        }else if(arr[mid] < target){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    if(arr[right] == target){
        return right;
    }
    if(arr[left] == target){
        return left;
    }
    
    return -1;
}
/*
int main(){
    int arr[] = {4, 5, 5, 5, 5, 6, 6, 8};
    int len = sizeof(arr)/sizeof(int);
    int target = 5;
    cout << find_last_occur(arr, len, target) << endl;
    return 0;
}*/