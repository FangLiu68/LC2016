//
//  First Occurrence Elem.cpp
//  LC2016
//
//  Created by Fang Liu on 3/22/16.
//  Copyright © 2016 Fang Liu. All rights reserved.
//

// Given a sorted array, return the first index of the target element.

#include <iostream>
using namespace std;

/*
 termination condition: 当left和right相邻的时候，跳出while循环，再判断left和right究竟哪个是最终答案(post processing)
 */
int find_first_occr(int arr[], int len, int target){
    if(arr == NULL || len <= 0){
        return -1;
    }
    
    int left = 0;
    int right = len - 1;
    
    while(left < right-1){ // if left neighbors right ->terminate
        int mid = left + (right-left)/2;
        if(arr[mid] == target){
            right = mid; // do not stop, keep checking left
        }else if(arr[mid] < target){
            left = mid + 1; // or left = mid
        }else{
            right = mid - 1; // or right = mid
        }
    }
    
    if(arr[left] == target){
        return left;
    }
    if(arr[right] == target){
        return right;
    }
    
    return -1;
}
/*
int main(){
    int arr[] = {4, 5, 5, 5, 5, 6, 6, 8};
    int len = sizeof(arr)/sizeof(int);
    int target = 6;
    cout << find_first_occr(arr, len, target) << endl;
    return 0;
}*/